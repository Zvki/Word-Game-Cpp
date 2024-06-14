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
    if (!font.loadFromFile("Dinofiles.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
        return false;
    }

    return true;
}

void graphics::init_text()
{
    if(init_font())
    {
        menu_text[0].setFont(font);
        menu_text[0].setCharacterSize(24);
        menu_text[0].setFillColor(sf::Color::White);
        menu_text[0].setString("PLAY");
        menu_text[0].setPosition(1280 / 2 - menu_text[0].getGlobalBounds().width / 2, 720/3);

        menu_text[1].setFont(font);
        menu_text[1].setCharacterSize(24);
        menu_text[1].setFillColor(sf::Color::White);
        menu_text[1].setString("EXIT");
    	menu_text[1].setPosition(1280 / 2 - menu_text[0].getGlobalBounds().width / 2, 720 / 3 * 2);

        score_.setFont(font);
        score_.setCharacterSize(24);
        score_.setFillColor(sf::Color::White);
        score_.setPosition(60, 30);

        definition_.setFont(font);
        definition_.setCharacterSize(24);
        definition_.setFillColor(sf::Color::White);
        definition_.setString("Definition:");
        definition_.setPosition(1280 / 2 - definition_.getGlobalBounds().width / 2, 120);

        definitionText.setFont(font);
        definitionText.setCharacterSize(18);
        definitionText.setFillColor(sf::Color::White);

        hpText.setFont(font);
        hpText.setCharacterSize(24);
        hpText.setFillColor(sf::Color::White);
        hpText.setPosition(60, 60);

        timerText.setFont(font);
        timerText.setCharacterSize(24);
        timerText.setFillColor(sf::Color::White);
        timerText.setPosition(1100, 30);

        inputTextDisplay.setFont(font);
        inputTextDisplay.setCharacterSize(24);
        inputTextDisplay.setFillColor(sf::Color::White);
       
    }
}

void graphics::render_game(sf::RenderTarget& target)
{

    definitionText.setPosition(1280 / 2 - definitionText.getGlobalBounds().width / 2, 160);
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
}

void graphics::text_fit(int width)
{
    while(this->definitionText.getGlobalBounds().width > width)
    {
        definitionText.setCharacterSize(definitionText.getCharacterSize() - 1);

    }

    if (definitionText.getGlobalBounds().width < width - 100.f)
    {
        definitionText.setCharacterSize(24);
    }
}
