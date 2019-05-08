#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

using namespace sf;
using namespace std;

class GameOverState : public State
{
private:
	GameDataRef _data;
	Sprite _retryButton;
	Sprite _homeButton;

public:
	GameOverState(GameDataRef data);
	~GameOverState();

	void Init();
	void HandleInput();
	void Update(float deltaTime);
	void Draw(float deltaTime);
};