#include "pch.h"
#include <sstream>
#include <iostream>
#include "MainMenuState.h"
#include "DEFINITIONS.h"

MainMenuState::MainMenuState(GameDataRef data) : _data(data) {}

MainMenuState::~MainMenuState() {}

void MainMenuState::Init()
{
	this->_data->assetManager.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
	this->_data->assetManager.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
	this->_data->assetManager.LoadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);
	this->_data->assetManager.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

	this->_background.setTexture(this->_data->assetManager.GetTexture("Background"));
	this->_playButton.setTexture(this->_data->assetManager.GetTexture("Play Button"));
	this->_playButtonOuter.setTexture(this->_data->assetManager.GetTexture("Play Button Outer"));
	this->_title.setTexture(this->_data->assetManager.GetTexture("Game Title"));

	this->_playButton.setPosition((SCREEN_WIDTH / 2) - this->_playButton.getGlobalBounds().width / 2, 
								  (SCREEN_HEIGHT / 2) - this->_playButton.getGlobalBounds().height / 2);
	this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - this->_playButtonOuter.getGlobalBounds().width / 2,
									   (SCREEN_HEIGHT / 2) - this->_playButtonOuter.getGlobalBounds().height / 2);
	this->_title.setPosition((SCREEN_WIDTH / 2) - this->_title.getGlobalBounds().width / 2,
		this->_playButtonOuter.getGlobalBounds().height * 0.1);
}

void MainMenuState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed) this->_data->window.close();
		if (this->_data->inputManager.IsSpriteClicked(this->_playButton, Mouse::Left, this->_data->window)) cout << "go to game screen" << endl;
	}
}

void MainMenuState::Update(float deltaTime) {}

void MainMenuState::Draw(float deltaTime)
{
	this->_data->window.clear();
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_playButton);
	this->_data->window.draw(this->_playButtonOuter);
	this->_data->window.draw(this->_title);
	this->_data->window.display();
}
