#pragma once
#include <SDL.h>
#include "TextureLoader.h"
#include "Grid.h"
#include "Button.h"


enum class STAND {
	GAMEOVER = 0,
	WIN = 1,
	START = 2,
	PLAYING = 3,
};

class Game {
public:
	Grid* grid;
	Button_play* playButton;
	Button_reset* resetButton;
	SDL_Renderer* renderer;
	SDL_Texture* gameover;
	STAND stand;
	int mine;
	Game(SDL_Renderer *renderer);
	void render();
	void play();
	void reset();





};
