#pragma once
#include "Vector2.h"
#include "RenderData.h"
#include <string>
class Button
{
public:
	Button(const Vector2& position, const Vector2& size, std::string text, const Vector2& textOffset);
	Button(const Button& button);
	Button& operator=(const Button& button);
	bool mouseHover(int x, int y);
	bool click(int x, int y);
	RenderData getRenderData() const;
	~Button();
private:
	//text
	bool hover;
	std::string text;
	Vector2* textOffset;
	Vector2* position;
	Vector2* size;
};