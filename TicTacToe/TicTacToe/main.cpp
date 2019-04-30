// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tic Tac Toe");

	while (window.isOpen())
	{
		Event event;

		while(window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();
		window.display();
	}

	return 0;
}
