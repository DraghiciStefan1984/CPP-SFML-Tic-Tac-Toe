// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Game.h"
#include "DEFINITIONS.h"

using namespace sf;

int main()
{
	Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Tic Tac Toe");
	return EXIT_SUCCESS;
}
