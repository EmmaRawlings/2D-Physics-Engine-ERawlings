#include "stdafx.h"
#include "TextField.h"


TextField::TextField(const Vector2& position, const Vector2& size, std::string text, const Vector2& textOffset)
{
	this->position = new Vector2(position);
	this->size = new Vector2(size);
	this->text = text;
	this->textOffset = new Vector2(textOffset);
}

TextField::TextField(const TextField& tField)
{
	this->textOffset = new Vector2(*tField.textOffset);
	this->position = new Vector2(*tField.position);
	this->size = new Vector2(*tField.size);
	this->text = tField.text;
}

TextField& TextField::operator=(const TextField& tField)
{
	delete this->textOffset;
	delete this->position;
	delete this->size;
	this->textOffset = new Vector2(*tField.textOffset);
	this->position = new Vector2(*tField.position);
	this->size = new Vector2(*tField.size);
	this->text = tField.text;
	return *this;
}

void TextField::SetText(std::string text) {
	this->text = text;
}

RenderData TextField::getRenderData() const
{
	Colour colour;
	colour.r = 48;
	colour.g = 48;
	colour.b = 48;
	RenderData renderData;
	renderData.addLine(this->position->x, this->position->y, 0, this->position->x + this->size->x, this->position->y, 0, colour.r, colour.g, colour.b, 255, 1);
	renderData.addLine(this->position->x, this->position->y, 0, this->position->x, this->position->y + this->size->y, 0, colour.r, colour.g, colour.b, 255, 1);
	renderData.addLine(this->position->x + this->size->x, this->position->y, 0, this->position->x + this->size->x, this->position->y + this->size->y, 0, colour.r, colour.g, colour.b, 255, 1);
	renderData.addLine(this->position->x, this->position->y + this->size->y, 0, this->position->x + this->size->x, this->position->y + this->size->y, 0, colour.r, colour.g, colour.b, 255, 1);
	renderData.addText(this->position->x + this->textOffset->x, this->position->y + this->textOffset->y, 0, colour.r, colour.g, colour.b, 255, 24, this->text);
	return renderData;
}

TextField::~TextField()
{
	delete this->textOffset;
	delete this->position;
	delete this->size;
}
