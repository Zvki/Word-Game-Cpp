#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "gra.h"
#include "graphics.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"



int main() {

    gra gra_;

    gra_.game_on();
	
    std::cout << "Game Over! Your score is: " << gra_.graphics_->score << std::endl;

    return 0;
}