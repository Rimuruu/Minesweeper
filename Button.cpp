#include "Button.h"
#include "Game.h"
Button::Button(int x, int y, int w, int h, std::string filetexture, SDL_Renderer* renderer) {
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	texture = loadTexture(filetexture, renderer);
}

void Button::render(SDL_Renderer* renderer) {
	renderTexture(texture, renderer, rect.x, rect.y, 0, 0, rect.w, rect.h);
}


void Button::isClicked(SDL_MouseButtonEvent evenements,Game* game) {
	if (evenements.x > rect.x && evenements.x < rect.x + rect.w && evenements.y > rect.y && evenements.y < rect.y + rect.h) this->trigger(game);
	else std::cout << "Not Trigger !" << std::endl;
}

void  Button::trigger(Game* game) {
	std::cout << "Trigger !" << std::endl;
}


void Button_play::trigger(Game* game)
{
	game->play();
}

Button_play::Button_play(int x, int y, int w, int h, std::string filetexture, SDL_Renderer* renderer) :Button(x, y, w, h, filetexture, renderer) {

}



void Button_reset::trigger(Game* game)
{
	game->reset();
}

Button_reset::Button_reset(int x, int y, int w, int h, std::string filetexture, SDL_Renderer* renderer) :Button(x, y, w, h, filetexture, renderer) {

}