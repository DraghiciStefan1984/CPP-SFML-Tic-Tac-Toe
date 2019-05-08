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
	_background.setTexture(this->_data->assetManager.GetTexture("Background"));
	_pauseButton.setTexture(this->_data->assetManager.GetTexture("Pause Button"));
	_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);
}

void GameState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed) this->_data->window.close();
		if (this->_data->inputManager.IsSpriteClicked(this->_pauseButton, Mouse::Left, this->_data->window)) this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
	}
}

void GameState::Update(float deltaTime) {}

void GameState::Draw(float deltaTime)
{
	this->_data->window.clear();
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_pauseButton);
	this->_data->window.display();
}
