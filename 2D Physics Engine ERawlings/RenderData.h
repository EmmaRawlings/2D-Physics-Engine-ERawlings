#pragma once
#include "Vector2.h"
#include <list>
#include <string>

//blend mode?

struct Position{
	int x;
	int y;
	int z;
};

struct Colour {
	int r;
	int g;
	int b;
	int a;
};

struct Point {
	Position position;
	Colour colour;
	int size;
};

struct Line {
	int x1;
	int y1;
	int z1;
	int x2;
	int y2;
	int z2;
	Colour colour;
	int width;
};
/*
struct Lines {
	std::list<Position> positions;
	Colour colour;
	int width;
};*/
/*
struct Sprite {
	int id;
	Position position;
	int a;
	int top;
	int left;
	int bottom;
	int right;
	//transformations
};*/

struct Text {
	std::string text;
	int size;
	Position position;
	//font type
	Colour colour;
	int a;
	//transformations
};

class RenderData
{
public:
	RenderData(void);
	RenderData(const RenderData& rData);
	RenderData& operator=(const RenderData& rData);
	void addRenderData(const RenderData& rData);
	void addRenderData(const RenderData& rData, const Position& position);
	void addPoint(const int x, const int y, const int z, const int r, const int g, const int b, const int a, const int size);
	void addLine(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int r, const int g, const int b, const int a, const int width);
	void addText(const int x, const int y, const int z, const int r, const int g, const int b, const int a, const int size, const std::string text);
	~RenderData(void);
	std::list<Point>* points;
	std::list<Line>* lines;
	std::list<Text>* texts;
};

