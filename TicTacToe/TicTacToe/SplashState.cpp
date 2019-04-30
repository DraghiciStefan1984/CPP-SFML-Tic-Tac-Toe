#include "pch.h"
#include <sstream>
#include <iostream>
#include "SplashState.h"
#include "DEFINITIONS.h"

SplashState::SplashState(GameDataRef data) :_data(data) {}

SplashState::~SplashState() {}

void SplashState::Init()
{
	this->_data->assetManager.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
	_background.setTexture(this->_data->assetManager.GetTexture("Splash State Background"));
}

void SplashState::HandleInput()
{
	Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed) this->_data->window.close();
	}
}

void SplashState::Update(float deltaTime)
{
	if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		cout << "Go to main menu" << endl;
	}
}

void SplashState::Draw(float deltaTime)
{
	this->_data->window.clear(Color::Red);
	this->_data->window.draw(this->_background);
	this->_data->window.display();
}
