#pragma once

#include <iostream>

#include <vector>
#include "SFML/Graphics.hpp"

#include "graphics.h"

struct Entry {
	std::string word;
	std::string definition;
};

class gra
{
public:

	sf::RenderWindow window;
	sf::Event event;

	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 720;
	const int FONT_SIZE = 24;

	std::string currentWord;
	std::string currentDefinition;
	std::string inputText;


	int dobrze;
	int hp;
	int selecti_;

	float timer = 20.0f;


	std::vector<std::string>words;
	std::vector<std::string>definitions;
	std::vector<Entry> entries = parseJsonFile("database.txt");

	graphics* graphics_;

	gra();

	void move_up();
	void move_down();
	void set_all();

	void menu();
	void game_on();
	void you_lost();

	void losuj_defnincje(std::vector<std::string>words, int& index);
	bool zgaduj(std::vector<std::string>words, std::vector<std::string>definitions, int index);

	std::string trim(const std::string& str);
	std::vector<Entry> parseJsonFile(const std::string& filename);
};