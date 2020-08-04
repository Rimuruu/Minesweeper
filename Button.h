#pragma once
#include <SDL.h>
#include <string>
#include "TextureLoader.h"
#include <iostream>
class Game;

class Button {
	SDL_Rect rect;
	SDL_Texture* texture;
public:
	Button(int x, int y, int w, int h, std::string filetexture, SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer);
	void isClicked(SDL_MouseButtonEvent evenements,Game* game);
	void virtual trigger(Game* game);
};

class Button_play : public Button {
public:
	void trigger(Game* game) override;
	Button_play(int x, int y, int w, int h, std::string filetexture, SDL_Renderer* renderer);
};

class Button_reset : public Button {
public:
	void trigger(Game* game) override;
	Button_reset(int x, int y, int w, int h, std::string filetexture, SDL_Renderer* renderer);
};


