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

    while(gra_.window.isOpen())
    {
        gra_.menu();
    }

    return 0;
}