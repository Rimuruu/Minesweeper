#pragma once
#include <SDL.h>
#include "TextureLoader.h"
#include "Cell.h"
#include <vector>

class Grid {
public:
	int x,y;
	SDL_Texture* texture;
	std::vector<std::vector<Cell*>> cases;
	Grid(SDL_Renderer* renderer, int mine);
	int mine;
	void render(SDL_Renderer* renderer);
	void init(int mine);
	void reset();
	void revealMine();
	int neighbourMine(int x, int y);
	void revealNeighbour(int x, int y);
};