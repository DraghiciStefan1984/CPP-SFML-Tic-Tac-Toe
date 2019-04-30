#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class InputManager
{
public:
	InputManager();
	~InputManager();

	bool IsSpriteClicked(Sprite sprite, Mouse::Button mouseButton, RenderWindow& window);
	Vector2i GetMousePosition(RenderWindow& window);
};