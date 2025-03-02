#include "graphics.h"

#include <iostream>
#include <ostream>
#include <SFML/Graphics/RenderTarget.hpp>

graphics::graphics()
{
    this->init_font();
    this->init_text();
}

bool graphics::init_font()
{
    if (!font.loadFromFile("coolvetica compressed hv.otf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
        return false;
    }

    return true;
}

void graphics::init_text()
{
    if (init_font())
    {
        menu_text[0].setFont(font);
        menu_text[0].setCharacterSize(60);
        menu_text[0].setFillColor(sf::Color::White);
        menu_text[0].setString("PLAY");
        menu_text[0].setPosition(1280 / 2 - menu_text[0].getGlobalBounds().width / 2, 720/ 4 );

        menu_text[1].setFont(font);
        menu_text[1].setCharacterSize(60);
        menu_text[1].setFillColor(sf::Color::White);
        menu_text[1].setString("VOCAB");
        menu_text[1].setPosition(1280 / 2 - menu_text[1].getGlobalBounds().width / 2, 720 / 2);

        menu_text[2].setFont(font);
        menu_text[2].setCharacterSize(60);
        menu_text[2].setFillColor(sf::Color::White);
        menu_text[2].setString("EXIT");
        menu_text[2].setPosition(1280 / 2 - menu_text[2].getGlobalBounds().width / 2, 720 / 4 * 3);

        score_.setFont(font);
        score_.setCharacterSize(60);
        score_.setFillColor(sf::Color::White);
        score_.setPosition(60, 30);

        definition_.setFont(font);
        definition_.setCharacterSize(60);
        definition_.setFillColor(sf::Color::White);
        definition_.setString("Definition:");
        definition_.setPosition(1280 / 2 - definition_.getGlobalBounds().width / 2, 120);

        definitionText.setFont(font);
        definitionText.setCharacterSize(60);
        definitionText.setFillColor(sf::Color::White);

        definitiontext_vocab.setFont(font);
        definitiontext_vocab.setCharacterSize(40);
        definitiontext_vocab.setFillColor(sf::Color::White);

        definition_vocab.setFont(font);
        definition_vocab.setCharacterSize(40);
        definition_vocab.setFillColor(sf::Color::White);

        hpText.setFont(font);
        hpText.setCharacterSize(60);
        hpText.setFillColor(sf::Color::White);
        hpText.setPosition(60, 100);

        timerText.setFont(font);
        timerText.setCharacterSize(60);
        timerText.setFillColor(sf::Color::White);
        timerText.setPosition(1100, 40);

        inputTextDisplay.setFont(font);
        inputTextDisplay.setCharacterSize(60);
        inputTextDisplay.setFillColor(sf::Color::White);

        end_text[0].setFont(font);
        end_text[0].setCharacterSize(60);
        end_text[0].setFillColor(sf::Color::White);
        end_text[0].setString("YOU LOST");
        end_text[0].setPosition(1280 / 2 - end_text[0].getGlobalBounds().width / 2, 720 / 3);

        end_text[1].setFont(font);
        end_text[1].setCharacterSize(60);
        end_text[1].setFillColor(sf::Color::White);
       
    }
}

void graphics::render_game(sf::RenderTarget& target)
{

    definitionText.setPosition(1280 / 2 - definitionText.getGlobalBounds().width / 2, 220);
    inputTextDisplay.setPosition(1280 / 2 - inputTextDisplay.getGlobalBounds().width / 2, 400);
    score_.setString("SCORE: " + std::to_string(this->score));

    target.draw(this->score_);
    target.draw(this->definition_);
    target.draw(this->definitionText);
    target.draw(this->hpText);
    target.draw(this->timerText);
    target.draw(this->inputTextDisplay);

}

void graphics::render_menu(sf::RenderTarget& target)
{
    target.draw(menu_text[0]);
    target.draw(menu_text[1]);
    target.draw(menu_text[2]);
}

void graphics::render_end(sf::RenderTarget& target)
{
    end_text[1].setString("Your score is: " + std::to_string(score));
    end_text[1].setPosition(1280 / 2 - end_text[1].getGlobalBounds().width / 2, 720 / 3 * 2);
    target.draw(end_text[0]);
    target.draw(end_text[1]);
}

void graphics::render_vocab(sf::RenderTarget& target, std::string definition_text, std::string definition)
{
    definitiontext_vocab.setString(definition_text);
    definition_vocab.setString(definition);

    definitiontext_vocab.setPosition(1280 / 2 - definitiontext_vocab.getGlobalBounds().width / 2, 400);
    definition_vocab.setPosition(1280 / 2 - definition_vocab.getGlobalBounds().width/2, 200);

    target.draw(definitiontext_vocab);
    target.draw(definition_vocab);
}

void graphics::text_fit(int width)
{
    if(definitionText.getGlobalBounds().width > width)
    {
        while (this->definitionText.getGlobalBounds().width > width)
        {
            definitionText.setCharacterSize(definitionText.getCharacterSize() - 1);
        }

    }else if(definitionText.getGlobalBounds().width < width - 200)
    {
        definitionText.setCharacterSize(60);
    }
    
}

void graphics::text_fit_vocab(int width)
{
    if (definitiontext_vocab.getGlobalBounds().width > width)
    {
        while (this->definitiontext_vocab.getGlobalBounds().width > width)
        {
            definitiontext_vocab.setCharacterSize(definitiontext_vocab.getCharacterSize() - 1);
        }

    }
    else if (definitiontext_vocab.getGlobalBounds().width < width - 200)
    {
        definitiontext_vocab.setCharacterSize(40);
    }
}
