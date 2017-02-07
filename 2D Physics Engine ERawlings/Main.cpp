// 2D Physics Engine ERawlings.cpp
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <windows.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include <thread>
#include <time.h>
#undef main

#include "Game.h"

Game* game = new Game();

int frameCount = 0;
const double FRAMETIME = 1000. / 60.;
const double FRAMETIMESECONDS = 1. / 60.;

int screenWidth = 800;
int screenHeight = 600;
int mouseX = 0;
int mouseY = 0;

bool quit = false;
SDL_Event e;


SDL_Rect textRect;
SDL_Surface *textSurface;
SDL_Texture *textTexture;
TTF_Font* textLiberationSans = nullptr;

void logSDLError(std::ostream &os, const std::string &msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

//Import SDL Texture Functions



void update(SDL_Renderer* ren) {
	time_t timeNow;
	time_t lastUpdate;
	time(&timeNow);
	time(&lastUpdate);
	while (quit == false) {
		//	//if (FRAMETIME <= difftime(lastUpdate, time(&timeNow))){
		//		while (SDL_PollEvent(&e)){
		//			//Quit (SDL_QUIT)
		//			if (e.type == SDL_QUIT){
		//				quit = true;
		//			}
		//			//Keyboard (SDL_KEYDOWN, SDL_KEYUP)
		//			if (e.type == SDL_KEYDOWN){
		//				game->buttonPress(e.key.keysym.scancode);
		//			}
		//			if (e.type == SDL_KEYUP){
		//				game->buttonRelease(e.key.keysym.scancode);
		//			}
		//			//Mouse (SDL_MouseButtonEvent, SDL_MouseMotionEvent, SDL_MouseWheelEvent)
		//			//SDL_MouseButtonEvent (SDL_MOUSEBUTTONDOWN, SDL_MOUSEBUTTONUP)
		//			if (e.type == SDL_MOUSEBUTTONDOWN){
		//			}
		//			if (e.type == SDL_MOUSEBUTTONUP){
		//			}
		//			//SDL_MouseMotionEvent (SDL_MOUSEMOTION)
		//			if (e.type == SDL_MOUSEMOTION){
		//				game->mousePosition(e.motion.x, e.motion.y);
		//			}
		//		}
		//		game->update(1.0 / 60.0);
	}
	//}
}

void render(SDL_Renderer* ren) {

	time_t start;
	time_t end;
	while (quit == false) {
		time(&start);
		SDL_SetRenderDrawColor(ren, 224, 224, 224, 255);
		SDL_RenderClear(ren);
		//SDL_RenderCopy(ren, tex, NULL, NULL);
		//renderTexture(tex, ren, 0, 0);

		RenderData rData = game->getRenderData();
		std::list<Line>::const_iterator lineIterator;
		for (lineIterator = rData.lines->begin(); lineIterator != rData.lines->end(); ++lineIterator) {
			SDL_SetRenderDrawColor(ren, lineIterator->colour.r, lineIterator->colour.g, lineIterator->colour.b, lineIterator->colour.a);
			SDL_RenderDrawLine(ren, lineIterator->x1, lineIterator->y1, lineIterator->x2, lineIterator->y2);
		}

		std::list<Point>::const_iterator iterator;
		for (iterator = rData.points->begin(); iterator != rData.points->end(); ++iterator) {
			SDL_SetRenderDrawColor(ren, iterator->colour.r, iterator->colour.g, iterator->colour.b, iterator->colour.a);
			SDL_RenderDrawPoint(ren, iterator->position.x, iterator->position.y);
		}

		std::list<Text>::const_iterator textIterator;
		for (textIterator = rData.texts->begin(); textIterator != rData.texts->end(); ++textIterator) {
			SDL_SetRenderDrawColor(ren, textIterator->colour.r, textIterator->colour.g, textIterator->colour.b, textIterator->colour.a);

			textSurface = TTF_RenderText_Blended(textLiberationSans, textIterator->text.c_str(), { (Uint8)textIterator->colour.r, (Uint8)textIterator->colour.g, (Uint8)textIterator->colour.b });
			if (textSurface == NULL) {
				logSDLError(std::cout, "TTF_RenderText_Blended Error: ");
				break;
			}
			textTexture = SDL_CreateTextureFromSurface(ren, textSurface);
			if (textTexture == NULL) {
				logSDLError(std::cout, "SDL_CreateTextureFromSurface Error: ");
				break;
			}
			textRect.x = textIterator->position.x;
			textRect.y = textIterator->position.y;
			textRect.w = textSurface->w;
			textRect.h = textSurface->h;
			SDL_RenderCopy(ren, textTexture, NULL, &textRect);
			SDL_FreeSurface(textSurface);
			SDL_DestroyTexture(textTexture);
		}

		SDL_RenderPresent(ren);
		time(&end);
		double elapsed = difftime(end, start)*1000.0;
		std::cout << "Render time: " << (double)elapsed << "\n";
		double milliseconds_to_sleep = (FRAMETIME - elapsed);
		std::cout << "Render sleep: " << (double)milliseconds_to_sleep << "\n";
		if (milliseconds_to_sleep > 0) { /* don't sleep if we're already late */
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(milliseconds_to_sleep)));
		}

	}
}

int main(int argc, char* argv[])
{
	//initialise all the things
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		logSDLError(std::cerr, "SDL_Init error: ");
		return 1;
	}

	if (TTF_Init() != 0) {
		logSDLError(std::cerr, "SDL_Init error: ");
		return 1;
	}

	//create a window
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		logSDLError(std::cout, "SDL_CreateWindow Error: ");
		SDL_Quit();
		return 1;
	}

	//create renderer
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		logSDLError(std::cout, "SDL_CreateRenderer Error: ");
		SDL_Quit();
		return 1;
	}

	//TTF
	textLiberationSans = TTF_OpenFont("LiberationSansRegular.ttf", 48);
	if (textLiberationSans == NULL)
	{
		logSDLError(std::cout, "TF_OpenFont Error: ");
		TTF_Quit();
		SDL_Quit();
		return 1;
	}

	//SDL_Texture *tex = loadTexture("tww.bmp", ren);

	//std::thread updateThread = std::thread(update, ren);

	std::thread renderThread = std::thread(render, ren);

	renderThread.detach();
	//std::cout << "S T A R T I N G !\n";

	//updateThread.detach();

	//std::cout << "E X I T I N G !\n";


	SDL_Event e;
	bool quit = false;
	time_t start;
	time_t end;
	while (quit == false) {
		time(&start);
		while (SDL_PollEvent(&e)) {
			//Quit (SDL_QUIT)
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			//Keyboard (SDL_KEYDOWN, SDL_KEYUP)
			if (e.type == SDL_KEYDOWN) {
				game->buttonPress(e.key.keysym.scancode);
			}
			if (e.type == SDL_KEYUP) {
				game->buttonRelease(e.key.keysym.scancode);
			}
			//Mouse (SDL_MouseButtonEvent, SDL_MouseMotionEvent, SDL_MouseWheelEvent)
			//SDL_MouseButtonEvent (SDL_MOUSEBUTTONDOWN, SDL_MOUSEBUTTONUP)
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				//quit = true;
				game->mouseClick(e.motion.x, e.motion.y);
			}
			if (e.type == SDL_MOUSEBUTTONUP) {
			}
			//SDL_MouseMotionEvent (SDL_MOUSEMOTION)
			if (e.type == SDL_MOUSEMOTION) {
				game->mousePosition(e.motion.x, e.motion.y);
			}
		}

		game->update(1.0 / 60.0);

		time(&end);
		double elapsed = difftime(end, start)*1000.0;
		std::cout << "Update time: " << (double)elapsed << "\n";
		double milliseconds_to_sleep = (FRAMETIME - elapsed);
		std::cout << "Update sleep: " << (double)milliseconds_to_sleep << "\n";
		if (milliseconds_to_sleep > 0) { /* don't sleep if we're already late */
			std::this_thread::sleep_for(std::chrono::milliseconds((int)(milliseconds_to_sleep)));
		}
	}

	SDL_Quit();
	return 0;
}

