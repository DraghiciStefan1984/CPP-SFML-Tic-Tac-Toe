#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

using namespace sf;
using namespace std;

class GameState : public State
{
private:
	GameDataRef _data;
	Sprite _background;
	Sprite _pauseButton;

	int turn;
	int gameState;

public:
	GameState(GameDataRef data);
	~GameState();

	void Init();
	void HandleInput();
	void Update(float deltaTime);
	void Draw(float deltaTime);
};