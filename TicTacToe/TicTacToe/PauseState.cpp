#include "pch.h"
#include <sstream>
#include <iostream>
#include "PauseState.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"

PauseState::PauseState(GameDataRef data) : _data(data) {}

PauseState::~PauseState() {}

void PauseState::Init()
{
	this->_data->assetManager.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
	this->_data->assetManager.LoadTexture("Resume Button", RESUME_BUTTON);
	this->_data->assetManager.LoadTexture("Home Button", HOME_BUTTON);

	this->_background.setTexture(this->_data->assetManager.GetTexture("Pause Background"));
	this->_resumeButton.setTexture(this->_data->assetManager.GetTexture("Resume Button"));
	this->_homeButton.setTexture(this->_data->assetManager.GetTexture("Home Button"));

	this->_resumeButton.setPosition(this->_data->window.getSize().x / 2 - this->_resumeButton.getGlobalBounds().width / 2, this->_data->window.getSize().x / 3 - this->_resumeButton.getGlobalBounds().height / 2);
	this->_homeButton.setPosition(this->_data->window.getSize().x / 2 - this->_homeButton.getGlobalBounds().width / 2, this->_data->window.getSize().x / 3 * 2  - this->_homeButton.getGlobalBounds().height / 2);
}

void PauseState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed) this->_data->window.close();
		if (this->_data->inputManager.IsSpriteClicked(this->_resumeButton, Mouse::Left, this->_data->window)) this->_data->machine.RemoveState();
		if (this->_data->inputManager.IsSpriteClicked(this->_homeButton, Mouse::Left, this->_data->window))
		{
			this->_data->machine.RemoveState();
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
}

void PauseState::Update(float deltaTime) {}

void PauseState::Draw(float deltaTime)
{
	this->_data->window.clear();
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_resumeButton);
	this->_data->window.draw(this->_homeButton);
	this->_data->window.display();
}
