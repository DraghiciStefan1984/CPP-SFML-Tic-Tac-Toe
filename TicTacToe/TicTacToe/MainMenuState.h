#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

using namespace sf;
using namespace std;

class MainMenuState : public State
{
private:
	GameDataRef _data;
	Sprite _background;
	Sprite _playButton;
	Sprite _playButtonOuter;
	Sprite _title;

public:
	MainMenuState(GameDataRef data);
	~MainMenuState();

	void Init();
	void HandleInput();
	void Update(float deltaTime);
	void Draw(float deltaTime);
};