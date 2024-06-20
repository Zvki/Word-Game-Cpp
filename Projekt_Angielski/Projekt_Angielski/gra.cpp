#include "gra.h"

#include <fstream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/Window/VideoMode.hpp>

gra::gra() {

	this->graphics_ = new graphics;
    this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Word Game");
    this->window.setFramerateLimit(60);
    this->hp = 3;
    this->entries = this->parseJsonFile("database.txt");

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (const auto& entry : entries)
    {
        words.push_back(entry.word);
        definitions.push_back(entry.definition);
    }
}

void gra::move_up()
{
    if(this->selecti_ - 1 >= 0)
    {
        graphics_->menu_text[this->selecti_].setFillColor(sf::Color::White);
        selecti_--;
        graphics_->menu_text[this->selecti_].setFillColor(sf::Color::Cyan);
    }
}

void gra::move_down()
{
    if (this->selecti_ + 1 < 2)
    {
        graphics_->menu_text[this->selecti_].setFillColor(sf::Color::White);
        selecti_++;
        graphics_->menu_text[this->selecti_].setFillColor(sf::Color::Cyan);
    }
}

void gra::set_all()
{
    graphics_->score = 0;
    hp = 4;
    dobrze = 0;
}



void gra::menu()
{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
			{
                move_up();
			}
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S)
            {
                move_down();
            }
            if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
            {
	            switch (selecti_)
	            {
	            case 0:
		            {
                        if(hp == 0)
                        {
                            set_all();
                        }
			            while (window.isOpen())
			            {
                            game_on();
			            }
                        break;
		            }
	            case 1:
		            {
                    this->window.close();
                    break;
		            }
	            }
            }
		}

        window.clear(sf::Color::Black);
        graphics_->render_menu(this->window);
        window.display();
}

void gra::game_on()
{

    this->graphics_->text_fit(this->WINDOW_WIDTH);

        if (timer <= 0.0f || inputText == currentWord)
        {
            if (inputText == currentWord)
            {
                // Reset timer and clear input text if word was correctly typed
                inputText.clear();
                this->graphics_->score += currentWord.size();
                dobrze++;
                timer = 20.0f - dobrze * 0.5f;
            }
            else
            {
                // Decrease HP if time ran out
                hp--;
                if (hp <= 0)
                {
	                while (this->window.isOpen())
	                {
                        this->you_lost();// Exit loop if HP is 0
	                }
                }
                // Reset timer if time ran out
                timer = 20.f - dobrze * 0.5f;
            }

            // Select a new word and definition
            int index = std::rand() % words.size();
            currentWord = words[index];
            currentDefinition = definitions[index];
            this->graphics_->definitionText.setString(currentDefinition + currentWord);
        }

        this->graphics_->hpText.setString("HP: " + std::to_string(hp));
        this->graphics_->timerText.setString("Time left: " + std::to_string(static_cast<int>(timer)));
        this->graphics_->inputTextDisplay.setString(inputText);


        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128) // Accept only ASCII characters
                {
                    if (event.text.unicode == '\b') // Handle backspace
                    {
                        if (!inputText.empty())
                            inputText.pop_back();
                    }
                    else
                    {
                        inputText += static_cast<char>(event.text.unicode);
                    }
                }
            }
        }

        this->window.clear(sf::Color::Black);
        this->graphics_->render_game(this->window);
        this->window.display();

        timer -= 0.01f;
}

void gra::you_lost()
{
    while (window.pollEvent(event))
    {
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
        {
            while (window.isOpen())
            {
                menu();
            }
            break;
        }
    }

    window.clear(sf::Color::Black);
    this->graphics_->render_end(this->window);
    window.display();

}

void gra::losuj_defnincje(std::vector<std::string> words, int& index)
{
	index = rand() % words.size();
}

bool gra::zgaduj(std::vector<std::string> words, std::vector<std::string> definitions, int index)
{
	std::string slowo;
	std::cout << definitions[index];
	std::cin >> slowo;
	if (slowo == words[index])
	{
		return true;
	}
	else
		return false;
}

std::string gra::trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

std::vector<Entry> gra::parseJsonFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku" << std::endl;
        return {};
    }

    std::vector<Entry> entries;
    std::string line;
    Entry currentEntry;
    bool inWord = false;
    bool inDefinition = false;

    while (getline(file, line)) {
        line = trim(line);

        if (line.find("\"WORD\"") != std::string::npos) {
            size_t start = line.find(":") + 3; // Zmieniamy +2 na +3, aby pomin¹æ pierwszy cudzys³ów
            size_t end = line.find_last_of("\"");
            currentEntry.word = line.substr(start, end - start);
            inWord = true;
        }
        else if (line.find("\"DEFINITION\"") != std::string::npos) {
            size_t start = line.find(":") + 3; // Zmieniamy +2 na +3, aby pomin¹æ pierwszy cudzys³ów
            size_t end = line.find_last_of("\"");
            currentEntry.definition = line.substr(start, end - start);
            inDefinition = true;
        }

        if (inWord && inDefinition) {
            entries.push_back(currentEntry);
            inWord = false;
            inDefinition = false;
            currentEntry = Entry();
        }
    }
    file.close();
    return entries;
}
