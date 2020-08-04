#include "Game.h"

void Game::play() {
	this->stand = STAND::PLAYING;
}

void Game::reset() {
	this->grid->reset();
	this->stand = STAND::PLAYING;
}


Game::Game(SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->mine = 100;
	this->grid = new Grid(renderer,mine);
	this->stand = STAND::START;
	this->playButton = new Button_play(350, 275, 100, 50, "./img/button.bmp", renderer);
	this->resetButton = new Button_reset(300, 400, 200, 50, "./img/buttonreset.bmp", renderer);
	gameover = loadTexture("./img/gameover.bmp", renderer);
}
void Game::render() {
	if (stand == STAND::PLAYING || stand == STAND::GAMEOVER) { 
		this->grid->render(renderer);
		if (stand == STAND::GAMEOVER) {
			this->resetButton->render(renderer);
			renderTexture(gameover, renderer, 200, 200, 0, 0, 400, 150);
		}
	}
	else if(stand == STAND::START) this->playButton->render(renderer);
	
	

}



