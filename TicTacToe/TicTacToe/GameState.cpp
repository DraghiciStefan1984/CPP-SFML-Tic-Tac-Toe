#include "pch.h"
#include <sstream>
#include <iostream>
#include "GameState.h"
#include "DEFINITIONS.h"
#include "PauseState.h"

GameState::GameState(GameDataRef data) : _data(data) {}

GameState::~GameState() {}

void GameState::Init()
{
	gameState = STATE_PLAYING;
	turn = PLAYER_PIECE;
	this->_data->assetManager.LoadTexture("Pause Button", PAUSE_BUTTON);
	this->_data->assetManager.LoadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
	this->_data->assetManager.LoadTexture("X Piece", X_PIECE_FILEPATH);
	this->_data->assetManager.LoadTexture("O Piece", O_PIECE_FILEPATH);

	_background.setTexture(this->_data->assetManager.GetTexture("Background"));
	_pauseButton.setTexture(this->_data->assetManager.GetTexture("Pause Button"));
	_gridSprite.setTexture(this->_data->assetManager.GetTexture("Grid Sprite"));

	_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);
	_gridSprite.setPosition(SCREEN_WIDTH / 2 * _gridSprite.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - _gridSprite.getGlobalBounds().height / 2);
	InitGridPieces();

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gridArray[x][y] = EMPTY_PIECE;
		}
	}
}

void GameState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed) this->_data->window.close();
		if (this->_data->inputManager.IsSpriteClicked(this->_pauseButton, Mouse::Left, this->_data->window)) this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
		else if (this->_data->inputManager.IsSpriteClicked(this->_gridSprite, Mouse::Left, this->_data->window)) this->CheckAndPlacePiece();
	}
}

void GameState::Update(float deltaTime) {}

void GameState::Draw(float deltaTime)
{
	this->_data->window.clear();
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_pauseButton);
	this->_data->window.draw(this->_gridSprite);

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			this->_data->window.draw(this->_gridPieces[x][y]);
		}
	}

	this->_data->window.display();
}

void GameState::InitGridPieces()
{
	Vector2u tempSpriteSize = this->_data->assetManager.GetTexture("X Piece").getSize();

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			_gridPieces[x][y].setTexture(this->_data->assetManager.GetTexture("X Piece"));
			_gridPieces[x][y].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x*x) - 7, _gridSprite.getPosition().y + (tempSpriteSize.y*y) - 7);
			_gridPieces[x][y].setColor(Color(255, 255, 255, 255));
		}
	}
}

void GameState::CheckAndPlacePiece()
{
	Vector2i touchPoint = this->_data->inputManager.GetMousePosition(this->_data->window);
	FloatRect gridSize = _gridSprite.getGlobalBounds();
	Vector2f gapOutsideOfGrid = Vector2f((SCREEN_WIDTH - gridSize.width) / 2, (SCREEN_HEIGHT - gridSize.height) / 2);
	Vector2f gridLocalTouchPoint = Vector2f(touchPoint.x - gapOutsideOfGrid.x, touchPoint.y - gapOutsideOfGrid.y);
	Vector2f gridSectionSize = Vector2f(gridSize.width / 3, gridSize.height / 3);
	
	int column, row;
	if (gridLocalTouchPoint.x < gridSectionSize.x) column = 1;
	else if(gridLocalTouchPoint.x < gridSectionSize.x * 2) column = 2;
	else if (gridLocalTouchPoint.x < gridSize.width) column = 3;
	if (gridLocalTouchPoint.y < gridSectionSize.y) row = 1;
	else if (gridLocalTouchPoint.y < gridSectionSize.y * 2) row = 2;
	else if (gridLocalTouchPoint.y < gridSize.height) row = 3;

	if (gridArray[column - 1][row - 1] == EMPTY_PIECE)
	{
		gridArray[column - 1][row - 1] = turn;

		if (PLAYER_PIECE == turn)
		{
			_gridPieces[column - 1][row - 1].setTexture(this->_data->assetManager.GetTexture("X Piece"));
		}
	}
}
