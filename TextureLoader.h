#pragma once
#include <SDL.h>
#include <iostream>
void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y, int indexX, int indexY, int w, int h);
SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren);