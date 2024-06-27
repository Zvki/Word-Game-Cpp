#pragma once
#include <SFML/Graphics/Text.hpp>


class graphics
{
public:

	int score = 0;

	sf::Font font;

	sf::Text score_;
	sf::Text definition_;
	sf::Text definitionText;
	sf::Text definition_vocab;
	sf::Text definitiontext_vocab;
	sf::Text hpText;
	sf::Text timerText;
	sf::Text inputTextDisplay;

	sf::Text menu_text[3];
	sf::Text end_text[2];

	graphics();

	bool init_font();

	void init_text();
	void render_game(sf::RenderTarget& target);
	void render_menu(sf::RenderTarget& target);
	void render_end(sf::RenderTarget& target);
	void render_vocab(sf::RenderTarget& target, std::string definition_text, std::string definition);
	void text_fit(int width);
	void text_fit_vocab(int width);
};
