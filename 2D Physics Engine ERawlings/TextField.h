#pragma once
#include "Vector2.h"
#include "RenderData.h"
#include <string>
class TextField
{
public:
	TextField(const Vector2& position, const Vector2& size, std::string text, const Vector2& textOffset);
	TextField(const TextField& tField);
	TextField& operator=(const TextField& tField);
	void SetText(std::string text);
	RenderData getRenderData() const;
	~TextField();
private:
	std::string text;
	Vector2* textOffset;
	Vector2* position;
	Vector2* size;
};

