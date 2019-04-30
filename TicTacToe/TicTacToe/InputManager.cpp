#include "pch.h"
#include "InputManager.h"

InputManager::InputManager() {}

InputManager::~InputManager() {}

bool InputManager::IsSpriteClicked(Sprite sprite, Mouse::Button mouseButton, RenderWindow & window)
{
	if (Mouse::isButtonPressed(mouseButton))
	{
		IntRect tempRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
		if (tempRect.contains(Mouse::getPosition(window))) return true;
	}
	return false;
}

Vector2i InputManager::GetMousePosition(RenderWindow & window) { return Mouse::getPosition(window); }