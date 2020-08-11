#include <SDL.h>
#include <iostream>
#include "Display.h"
#include <SDL_ttf.h>
#include "Resource.h"


int main(int argc, char** argv)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();

        return -1;
    }
    if (TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    Display* display = new Display(800,700);
    display->run();
   


    // On quitte la SDL

   

    return 0;
}