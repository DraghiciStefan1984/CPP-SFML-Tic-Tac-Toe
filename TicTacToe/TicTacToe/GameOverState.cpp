#include "pch.h"
#include <sstream>
#include <iostream>
#include "GameOverState.h"
#include "GameState.h"
#include "DEFINITIONS.h"

GameOverState::GameOverState(GameDataRef data) : _data(data) {}

GameOverState::~GameOverState() {}

void GameOverState::Init()
{
	this->_data->assetManager.LoadTexture("Retry Button", RESUME_BUTTON);
	this->_data->assetManager.LoadTexture("Home Button", HOME_BUTTON);

	this->_retryButton.setTexture(this->_data->assetManager.GetTexture("Resume Button"));
	this->_homeButton.setTexture(this->_data->assetManager.GetTexture("Home Button"));

	this->_retryButton.setPosition(this->_data->window.getSize().x / 2 - this->_retryButton.getGlobalBounds().width / 2, this->_data->window.getSize().x / 3 - this->_retryButton.getGlobalBounds().height / 2);
	this->_homeButton.setPosition(this->_data->window.getSize().x / 2 - this->_homeButton.getGlobalBounds().width / 2, this->_data->window.getSize().x / 3 * 2 - this->_homeButton.getGlobalBounds().height / 2);
}

void GameOverState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed) this->_data->window.close();
		if (this->_data->inputManager.IsSpriteClicked(this->_retryButton, Mouse::Left, this->_data->window)) this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
		if (this->_data->inputManager.IsSpriteClicked(this->_homeButton, Mouse::Left, this->_data->window))	this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
	}
}

void GameOverState::Update(float deltaTime) {}

void GameOverState::Draw(float deltaTime)
{
	this->_data->window.clear();
	this->_data->window.draw(this->_retryButton);
	this->_data->window.draw(this->_homeButton);
	this->_data->window.display();
}