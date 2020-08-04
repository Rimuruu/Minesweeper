#pragma once
#include <SDL.h>
#include "TextureLoader.h"

enum class STATE {
	NOTREVEAL = 0,
	ONE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	FLAG = 9,
	MINE = 10,
	MINETRIGGER = 11,
	EMPTY = 12,

};


class Cell {
private:
public:
	int x;
	int y;
	int indexX;
	int indexY;
	STATE content, showing;
	static SDL_Texture* texture;
	Cell(SDL_Renderer* renderer,int x,int y);
	void render(SDL_Renderer* renderer);
	bool isClicked(int x, int y);




};
