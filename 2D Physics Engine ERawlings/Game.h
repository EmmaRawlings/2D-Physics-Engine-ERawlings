#pragma once
#include <list>
#include "Edge2.h"
#include "GameMenu.h"
#include "GameWorld.h"
class Game
{
public:
	Game(void);
	Game(const Game& game);
	Game& operator=(const Game& game);
	void update(double time);
	void buttonPress(int button);
	void buttonRelease(int button);
	void mousePosition(int x, int y);
	void mouseClick(int x, int y);
	RenderData getRenderData() const;
	~Game(void);
private:
	Vector2* mousePos;
	bool buttons[1024]; // buttons pressed/unpressed
							//not enough, need to process multiple presses per frame
							//instead buffer keypresses for next frame
	GameMenu* menu;
	GameWorld* world;
	int activeScreen; //0=menu 1=demo1
};

