#pragma once
#include "RenderData.h"
#include "Button.h"
#include "PointObject.h"
#include "TextField.h"
class GameMenu
{
public:
	GameMenu(void);
	GameMenu(const GameMenu& gMenu);
	GameMenu& operator=(const GameMenu& gMenu);
	void update(double time);
	void mouseAt(int x, int y); //update cursor position
	void mouseClick(int x, int y); //click the button where the cursor is
	RenderData getRenderData();
	~GameMenu(void);
	int goToDemo;
private:
	TextField* textField;
	Button* buttons[4];
	std::string hoverTexts[4];
	int buttonCount;
};

