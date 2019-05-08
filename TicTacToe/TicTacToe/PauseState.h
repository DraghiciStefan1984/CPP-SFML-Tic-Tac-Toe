#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

using namespace sf;
using namespace std;

class PauseState : public State
{
private:
	GameDataRef _data;
	Sprite _background;
	Sprite _resumeButton;
	Sprite _homeButton;

public:
	PauseState(GameDataRef data);
	~PauseState();

	void Init();
	void HandleInput();
	void Update(float deltaTime);
	void Draw(float deltaTime);
};