#include "Display.h"




    Display::Display(int width, int height) {
        this->fenetre = SDL_CreateWindow("Minesweeper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        std::string fileFont= "./font/Lato-Regular.ttf";
        SDL_Color couleurNoire = { 255, 255, 255 };
        if (fenetre == 0)
        {
            std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
           
            SDL_Quit();
            delete this;
        }
       renderer = SDL_CreateRenderer(fenetre, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
       if (renderer == nullptr) {
           logSDLError(std::cout, "CreateRenderer");
           cleanup(fenetre);
           SDL_Quit();
       }
       this->terminer = false;
       this->game = new Game(renderer);
       this->police = TTF_OpenFont(fileFont.c_str(), 24);
       if (!this->police) {
           logSDLError(std::cout, "Font not loaded");
           // handle error
       }
       else {
           std::cout << "Font loaded" << std::endl;
       }
       SDL_Surface* ico = SDL_LoadBMP("./img/ico.bmp");
       SDL_SetWindowIcon(fenetre, ico);
    }

    void Display::run() {
        const int FPS = 60;
        const int frameDelay = 1000 / FPS;
        Uint32 frameStart;
        int frameTime;
        int frameInSecond = 0;
        SDL_Color couleurPurple= { 238,130,238 };
        Uint32 timer = SDL_GetTicks();
        while (!terminer)
        {
            frameStart = SDL_GetTicks();
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                handle_event(event);
            }
            game->render();
            if(frameTexture!=nullptr && showFPS)renderTexture(frameTexture, renderer, 0, 0,0,0,NULL,NULL);
            SDL_RenderPresent(renderer);
            frameTime = SDL_GetTicks() - frameStart;
            if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
            frameInSecond++;
            if (SDL_GetTicks() - timer >= 1000) {
                auto s = std::to_string(frameInSecond);
                char const* pchar = s.c_str();
                frame = TTF_RenderText_Blended(police, pchar, couleurPurple);
                frameTexture = SDL_CreateTextureFromSurface(renderer,  frame);
                timer = SDL_GetTicks();
                frameInSecond=0;
            }
            
            //std::cout << SDL_GetTicks() - frameStart << std::endl;
        }
        TTF_CloseFont(police);
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        TTF_Quit();

    }
    void logSDLError(std::ostream& os, const std::string& msg) {
        os << msg << " error: " << SDL_GetError() << std::endl;
    }


    void Display::handle_event(SDL_Event event) {
        if (event.type == SDL_QUIT) {
            this->terminer = true;
        }
        switch (event.type) {
        case SDL_QUIT:
            this->terminer = true;
            break;
        case SDL_KEYDOWN:
            handle_input(event.key);
            break;
        case SDL_MOUSEBUTTONDOWN:
            handle_mouse(event.button);
            break;
        }
    }


    void Display::handle_input(SDL_KeyboardEvent evenements) {
        switch (evenements.keysym.sym) {
        case SDLK_F1:
            std::cout << "F1" << std::endl;
            showFPS = !showFPS;
            break;
        }
    }

    void Display::handle_mouse(SDL_MouseButtonEvent evenements) {
        std::cout << "x: " << evenements.x << " y: " <<evenements.y << std::endl;
        if (game->stand == STAND::PLAYING)
        {
            for (size_t x = 0; x < 30; x++)
            {
                for (size_t y = 0; y < 22; y++)
                {

                    if (game->grid->cases[x][y]->isClicked(evenements.x, evenements.y))
                    {
                        if (evenements.button == SDL_BUTTON_LEFT) {
                            if (game->grid->cases[x][y]->showing == STATE::NOTREVEAL) {
                                game->grid->cases[x][y]->showing = game->grid->cases[x][y]->content;
                                if (game->grid->cases[x][y]->content == STATE::EMPTY) game->grid->revealNeighbour(x, y);
                                if (game->grid->cases[x][y]->content == STATE::MINE) {
                                    game->grid->cases[x][y]->showing = STATE::MINETRIGGER;
                                    game->grid->revealMine();
                                    game->stand = STAND::GAMEOVER;
                                }
                            }
                        }
                        else if (evenements.button == SDL_BUTTON_RIGHT) {
                            if (game->grid->cases[x][y]->showing == STATE::NOTREVEAL) {
                                game->grid->cases[x][y]->showing = STATE::FLAG;

                            }
                            else if (game->grid->cases[x][y]->showing == STATE::FLAG) {
                                game->grid->cases[x][y]->showing = STATE::NOTREVEAL;
                            }
                        }
                        break;
                    }

                }
            }
        }
        else if(game->stand == STAND::START) game->playButton->isClicked(evenements,game);
        else if (game->stand == STAND::GAMEOVER) game->resetButton->isClicked(evenements,game);

       
    }


