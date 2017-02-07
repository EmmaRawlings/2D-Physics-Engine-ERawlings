#include "Game.h"

Game::Game(void)
{
	this->mousePos = new Vector2(50,50);
	this->menu = new GameMenu();
	this->world = new GameWorld();
	for (int i = 0; i < 1024; i++) {
		buttons[i] = false;
	}
	this->activeScreen = 0;
}

Game::Game(const Game& game)
{
	this->mousePos = new Vector2(*game.mousePos);
	this->menu = new GameMenu(*game.menu);
	this->world = new GameWorld(*game.world);
	for (int i = 0; i < 1024; i++) {
		this->buttons[i] = game.buttons[i];
	}
	this->activeScreen = game.activeScreen;
}

Game& Game::operator=(const Game& game)
{
	delete this->mousePos;
	delete this->menu;
	delete this->world;
	this->mousePos = new Vector2(*game.mousePos);
	this->menu = new GameMenu(*game.menu);
	this->world = new GameWorld(*game.world);
	for (int i = 0; i < 1024; i++) {
		this->buttons[i] = game.buttons[i];
	}
	this->activeScreen = game.activeScreen;
	return *this;
}

void Game::update(double time)
{
	if (this->activeScreen == 0) {
		this->menu->update(time);
	}
	else if (this->activeScreen == 1) {
		this->world->update(time);
	}
}

void Game::buttonPress(int button)
{
	this->buttons[button] = true;
}

void Game::buttonRelease(int button)
{
	this->buttons[button] = false;
}

void Game::mousePosition(int x, int y)
{
	this->mousePos = new Vector2(x, y);
	if (this->activeScreen == 0) {
		this->menu->mouseAt(x, y);
	}
	else if (this->activeScreen == 1) {
		this->world->mouseAt(x, y);
	}
}

void Game::mouseClick(int x, int y)
{
	this->mousePosition(x, y);
	if (this->activeScreen == 0) {
		this->menu->mouseClick(x, y);
		if (this->menu->goToDemo != 0) {
			this->activeScreen = this->menu->goToDemo;
			this->menu->goToDemo = 0;
		}
	}
	else if (this->activeScreen == 1) {
		this->world->mouseClick(x, y);
	}
}

RenderData Game::getRenderData() const
{
	RenderData renderData;
	if (this->activeScreen == 0) {
		renderData.addRenderData(this->menu->getRenderData());
	}
	else if (this->activeScreen == 1) {
		renderData.addRenderData(this->world->getRenderData());
	}
	return renderData;
}

Game::~Game(void)
{
	delete this->mousePos;
	delete this->menu;
	delete this->world;
}
