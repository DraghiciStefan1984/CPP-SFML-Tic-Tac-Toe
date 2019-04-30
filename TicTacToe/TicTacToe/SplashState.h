#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

using namespace std;
using namespace sf;

class SplashState : public State
{
private:
	GameDataRef _data;
	Clock _clock;
	Sprite _background;

public:
	SplashState(GameDataRef data);
	~SplashState();

	void Init();
	void HandleInput();
	void Update(float deltaTime);
	void Draw(float deltaTime);
};