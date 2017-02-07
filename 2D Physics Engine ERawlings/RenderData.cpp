#include "RenderData.h"

#include <iostream>

RenderData::RenderData(void)
{
	this->points = new std::list<Point>();
	this->lines = new std::list<Line>();
	this->texts = new std::list<Text>();
}

RenderData::RenderData(const RenderData& rData)
{
	this->points = new std::list<Point>(*rData.points);
	this->lines = new std::list<Line>(*rData.lines);
	this->texts = new std::list<Text>(*rData.texts);
}

RenderData& RenderData::operator=(const RenderData& rData)
{
	delete this->points;
	delete this->lines;
	delete this->texts;
	this->points = new std::list<Point>(*rData.points);
	this->lines = new std::list<Line>(*rData.lines);
	this->texts = new std::list<Text>(*rData.texts);
	return *this;
}

void RenderData::addRenderData(const RenderData& rData)
{
	this->points->splice(this->points->end(), *(rData.points));
	this->lines->splice(this->lines->end(), *(rData.lines));
	this->texts->splice(this->texts->end(), *(rData.texts));
}

void RenderData::addRenderData(const RenderData &rData, const Position &position)
{
	std::list<Point> newPoints;
	for (Point point : *(rData.points)) {
		point.position.x += position.x;
		point.position.y += position.y;
		point.position.z += position.z;
		newPoints.push_back(point);
	}
	std::list<Line> newLines;
	for (Line line : *(rData.lines)) {
		line.x1 += position.x;
		line.y1 += position.y;
		line.z1 += position.z;
		line.x2 += position.x;
		line.y2 += position.y;
		line.z2 += position.z;
		newLines.push_back(line);
	}
	std::list<Text> newTexts;
	for (Text text : *(rData.texts)) {
		text.position.x += position.x;
		text.position.y += position.y;
		text.position.z += position.z;
		newTexts.push_back(text);
	}
	this->points->splice(this->points->end(), newPoints);
	this->lines->splice(this->lines->end(), newLines);
	this->texts->splice(this->texts->end(), newTexts);
}

void RenderData::addPoint(const int x, const int y, const int z, const int r, const int g, const int b, const int a, const int size)
{
	Point newPoint;
	newPoint.position.x = x;
	newPoint.position.y = y;
	newPoint.position.z = z;
	newPoint.colour.r = r;
	newPoint.colour.g = g;
	newPoint.colour.b = b;
	newPoint.colour.a = a;
	newPoint.size = size;
	this->points->push_back(newPoint);
}
void RenderData::addLine(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int r, const int g, const int b, const int a, const int width)
{
	Line newLine;
	newLine.x1 = x1;
	newLine.y1 = y1;
	newLine.z1 = z1;
	newLine.x2 = x2;
	newLine.y2 = y2;
	newLine.z2 = z2;
	newLine.colour.r = r;
	newLine.colour.g = g;
	newLine.colour.b = b;
	newLine.colour.a = a;
	newLine.width = width;
	this->lines->push_back(newLine);
}

void RenderData::addText(const int x, const int y, const int z, const int r, const int g, const int b, const int a, const int size, const std::string text)
{
	Text newText;
	newText.position.x = x;
	newText.position.y = y;
	newText.position.z = z;
	newText.colour.r = r;
	newText.colour.g = g;
	newText.colour.b = b;
	newText.a = a;
	newText.size = size;
	newText.text = text;
	this->texts->push_back(newText);
}

RenderData::~RenderData(void)
{
	delete this->points;
	delete this->lines;
	delete this->texts;
}
