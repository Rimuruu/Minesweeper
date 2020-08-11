#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "TextureLoader.h"
class UI {
public:
    TTF_Font* police;
    SDL_Surface* chrono;
    SDL_Surface* fText;
    SDL_Texture* chronoTexture;
    SDL_Texture* fTexture;
    SDL_Texture* bg;
    SDL_Texture* bgchrono;
    SDL_Texture* bgflag;
    Uint32 chronoStart;
    int flag;
    SDL_Color couleurWhite = { 255,255,255 };
    SDL_Color couleurGrey = { 169,169,169 };
    UI(TTF_Font* police, SDL_Renderer * renderer,int flag);
    void render(SDL_Renderer* renderer);
    void startChrono();
    std::string format_chrono(Uint32 u);
};