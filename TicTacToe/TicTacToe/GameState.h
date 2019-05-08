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
	Sprite _gridSprite;
	Sprite _gridPieces[3][3];
	int gridArray[3][3];

	int turn;
	int gameState;
	void InitGridPieces();
	void CheckAndPlacePiece();

public:
	GameState(GameDataRef data);
	~GameState();

	void Init();
	void HandleInput();
	void Update(float deltaTime);
	void Draw(float deltaTime);
};