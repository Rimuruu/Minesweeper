#include "Cell.h"

SDL_Texture* Cell::texture = nullptr;

Cell::Cell(SDL_Renderer* renderer,int x,int y) {
	this->x = x;
	this->y = y;
	this->indexX=0;
	this->indexY=0;
	if (texture == nullptr) {
		texture = loadTexture("./img/case.bmp", renderer);
	}
	this->content = STATE::EMPTY;
	this->showing = STATE::NOTREVEAL;
	
	}
void Cell::render(SDL_Renderer* renderer) {
	renderTexture(texture, renderer, x * 25, y * 25, (int)showing, indexY, 25, 25);
	}


bool Cell::isClicked(int x, int y) {
	if ((this->x * 25 < x && this->y * 25 < y) && ((this->x * 25) + 25 > x && (this->y * 25) + 25 > y))return true;
	else return false;
}