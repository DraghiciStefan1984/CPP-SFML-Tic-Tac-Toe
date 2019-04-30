#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

using namespace std;
using namespace sf;

struct GameData
{
	StateMachine machine;
	RenderWindow window;
	AssetManager assetManager;
	InputManager inputManager;
};

typedef shared_ptr<GameData> GameDataRef;

class Game
{
private:
	const float deltaTime = 1.0f / 60.0f;
	Clock _clock;
	GameDataRef _data = make_shared<GameData>();

	void Run();

public:
	Game(int width, int height, string title);
	~Game();
};