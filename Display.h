#pragma once
#include <SDL.h>
#include <iostream>
#include "cleanup.h"
#include "Game.h"
#include "TextureLoader.h"
#include <SDL_ttf.h>
#include <string> 
class Display {
    SDL_Window* fenetre;
    SDL_Event evenements;
    SDL_Renderer* renderer;
    Game* game;
    bool terminer;
    TTF_Font* police;
    SDL_Surface* frame;
    SDL_Texture* frameTexture;
    bool showFPS = false;

public:
    int width, height;
    Display(int width, int height);
    void run();
    void handle_event(SDL_Event event);
    void handle_input(SDL_KeyboardEvent evenements);
    void handle_mouse(SDL_MouseButtonEvent evenements);
    


};

void logSDLError(std::ostream& os, const std::string& msg);