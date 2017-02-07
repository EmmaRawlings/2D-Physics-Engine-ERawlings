#include "GameMenu.h"

GameMenu::GameMenu(void)
{
	this->goToDemo = 0;
	Vector2 s = Vector2(180, 55);
	Vector2 a = Vector2(20, 20);
	Vector2 b = Vector2(20, 95);
	Vector2 c = Vector2(20, 170);
	Vector2 d = Vector2(20, 245);
	Vector2 t = Vector2(220, 20);
	Vector2 st = Vector2(560, 560);
	Vector2 o = Vector2(5, 0);
	this->buttons[0] = new Button(a, s, "Demo 1", o);
	this->buttons[1] = new Button(b, s, "Demo 2", o);
	this->buttons[2] = new Button(c, s, "Demo 3", o);
	this->buttons[3] = new Button(d, s, "Demo 4", o);
	this->buttonCount = 4;
	this->textField = new TextField(t, st, " ", o);
	this->hoverTexts[0] = ((std::string)"Demo 1 Description");
	this->hoverTexts[1] = ((std::string)"Demo 2 Description");
	this->hoverTexts[2] = ((std::string)"Demo 3 Description");
	this->hoverTexts[3] = ((std::string)"Demo 4 Description");
}

GameMenu::GameMenu(const GameMenu& gMenu)
{
	this->goToDemo = gMenu.goToDemo;
	this->textField = new TextField(*gMenu.textField);
	this->buttons[0] = new Button(*gMenu.buttons[0]);
	this->buttons[1] = new Button(*gMenu.buttons[1]);
	this->buttons[2] = new Button(*gMenu.buttons[2]);
	this->buttons[3] = new Button(*gMenu.buttons[3]);
	this->hoverTexts[0] = gMenu.hoverTexts[0];
	this->hoverTexts[1] = gMenu.hoverTexts[1];
	this->hoverTexts[2] = gMenu.hoverTexts[2];
	this->hoverTexts[3] = gMenu.hoverTexts[3];
	this->buttonCount = gMenu.buttonCount;
}

GameMenu& GameMenu::operator=(const GameMenu& gMenu)
{
	delete this->textField;
	delete[4] this->buttons;
	this->goToDemo = gMenu.goToDemo;
	this->textField = new TextField(*gMenu.textField);
	this->buttons[0] = new Button(*gMenu.buttons[0]);
	this->buttons[1] = new Button(*gMenu.buttons[1]);
	this->buttons[2] = new Button(*gMenu.buttons[2]);
	this->buttons[3] = new Button(*gMenu.buttons[3]);
	this->hoverTexts[0] = gMenu.hoverTexts[0];
	this->hoverTexts[1] = gMenu.hoverTexts[1];
	this->hoverTexts[2] = gMenu.hoverTexts[2];
	this->hoverTexts[3] = gMenu.hoverTexts[3];
	this->buttonCount = gMenu.buttonCount;
	return *this;
}


void GameMenu::update(double time)
{
	//nothing needs to be updated over time
}

void GameMenu::mouseAt(int x, int y)
{
	bool hovered = false;
	for (int i = 0; i < this->buttonCount; i++){
		hovered = this->buttons[i]->mouseHover(x, y);
		if (hovered) {
			this->textField->SetText(this->hoverTexts[i]);
		}
	}
}

void GameMenu::mouseClick(int x, int y)
{
	int bClicked = -1;
	for (int i = 0; i < this->buttonCount; i++) {
		if (this->buttons[i]->click(x, y)) {
			bClicked = i;
		}
	}
	if (bClicked == 0) {
		//Switch to the first demo
		this->goToDemo = 1;
	}
}

RenderData GameMenu::getRenderData()
{
	RenderData renderData;

	for (int i = 0; i < this->buttonCount; i++){
		renderData.addRenderData(this->buttons[i]->getRenderData());
	}
	renderData.addRenderData(this->textField->getRenderData());
	return renderData;
}

GameMenu::~GameMenu(void)
{
	delete this->textField;
	delete[4] this->buttons;
}
