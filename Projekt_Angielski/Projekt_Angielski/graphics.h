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
	sf::Text hpText;
	sf::Text timerText;
	sf::Text inputTextDisplay;

	graphics();

	bool init_font();

	void init_text();
	void render_game(sf::RenderTarget& target);
};
