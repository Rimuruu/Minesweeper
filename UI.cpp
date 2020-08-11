
#include "UI.h"

UI::UI(TTF_Font* police, SDL_Renderer* renderer,int flag) {
    this->police = police;
    chrono = 0;
    bg = loadTexture("./img/bgui.bmp", renderer);
    bgchrono = loadTexture("./img/chrono.bmp", renderer);
    bgflag = loadTexture("./img/flag.bmp", renderer);
    this->flag = flag;
}

void UI::startChrono() {
   chronoStart = SDL_GetTicks();
}


void UI::render(SDL_Renderer* renderer) {
    renderTexture(bg, renderer, 0, 600, 0, 0, NULL, NULL);
    auto s = format_chrono(( SDL_GetTicks()- chronoStart )/1000);
    auto f = std::to_string(flag);
    char const* pchar = s.c_str();
    char const* fchar = f.c_str();
    chrono = TTF_RenderText_Blended(police, pchar, couleurWhite);
    fText = TTF_RenderText_Blended(police, fchar, couleurWhite);
    chronoTexture = SDL_CreateTextureFromSurface(renderer, chrono);
    fTexture = SDL_CreateTextureFromSurface(renderer, fText);
    renderTexture(chronoTexture, renderer, 500, 635, 0, 0, NULL, NULL);
    renderTexture(fTexture, renderer, 250, 635, 0, 0, NULL, NULL);
    renderTexture(bgchrono, renderer, 465, 635, 0, 0, NULL, NULL);
    renderTexture(bgflag, renderer, 215, 635, 0, 0, NULL, NULL);
}

std::string UI::format_chrono(Uint32 u) {
    if (u >= 5940060) return "99:60";
    else return (u/60>=10?std::to_string(u / 60): "0"+std::to_string(u / 60)) +":"+ (u%60>=10? std::to_string(u % 60): "0"+std::to_string(u % 60));
  
    
}