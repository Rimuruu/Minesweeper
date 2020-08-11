#pragma once
#include <SDL.h>
#include "TextureLoader.h"
#include "Grid.h"
#include "Button.h"
#include "UI.h"

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
	SDL_Texture* win;
	SDL_Texture* bg;
	STAND stand;
	UI* ui;
	int mine;
	Game(SDL_Renderer *renderer, TTF_Font* police);
	void render();
	void play();
	void reset();
	void checkWin();





};
