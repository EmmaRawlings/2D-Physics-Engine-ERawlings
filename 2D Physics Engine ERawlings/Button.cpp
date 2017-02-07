#include "Button.h"

Button::Button(const Vector2& position, const Vector2& size, std::string text, const Vector2& textOffset)
{
	//text = "fgsbjd";
	this->position = new Vector2(position);
	this->size = new Vector2(size);
	this->text = text;
	this->textOffset = new Vector2(textOffset);
	this->hover = false;
}

Button::Button(const Button& button)
{
	this->textOffset = new Vector2(*button.textOffset);
	this->position = new Vector2(*button.position);
	this->size = new Vector2(*button.size);
	this->hover = button.hover;
	this->text = button.text;
}

Button& Button::operator=(const Button& button)
{
	delete this->textOffset;
	delete this->position;
	delete this->size;
	this->textOffset = new Vector2(*button.textOffset);
	this->position = new Vector2(*button.position);
	this->size = new Vector2(*button.size);
	this->hover = button.hover;
	this->text = button.text;
	return *this;
}

bool Button::mouseHover(int x, int y)
{
	x -= this->position->x;
	y -= this->position->y;
	if (x>0 && y>0 && x<this->size->x && y<this->size->y){
		this->hover = true;
	}
	else {
		this->hover = false;
	}
	return this->hover;
}

bool Button::click(int x, int y)
{
	bool click = false;
	x -= this->position->x;
	y -= this->position->y;
	if (x>0 && y>0 && x<this->size->x && y<this->size->y) {
		click = true;
	}
	return click;
}

RenderData Button::getRenderData() const
{
	Colour colour;
	if (this->hover == true){
		colour.r = 144;
		colour.g = 112;
		colour.b = 96;
	}
	else {
		colour.r = 48;
		colour.g = 48;
		colour.b = 48;
	}
	RenderData renderData;
	renderData.addLine(this->position->x, this->position->y, 0, this->position->x + this->size->x, this->position->y, 0, colour.r, colour.g, colour.b, 255, 1);
	renderData.addLine(this->position->x, this->position->y, 0, this->position->x, this->position->y + this->size->y, 0, colour.r, colour.g, colour.b, 255, 1);
	renderData.addLine(this->position->x + this->size->x, this->position->y, 0, this->position->x + this->size->x, this->position->y + this->size->y, 0, colour.r, colour.g, colour.b, 255, 1);
	renderData.addLine(this->position->x, this->position->y + this->size->y, 0, this->position->x + this->size->x, this->position->y + this->size->y, 0, colour.r, colour.g, colour.b, 255, 1);
	renderData.addText(this->position->x + this->textOffset->x, this->position->y + this->textOffset->y, 0, colour.r, colour.g, colour.b, 255, 24, this->text);
	return renderData;
}

Button::~Button()
{
	delete this->textOffset;
	delete this->position;
	delete this->size;
}
