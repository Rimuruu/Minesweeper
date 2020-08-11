#include "Game.h"

void Game::play() {
	this->stand = STAND::PLAYING;
	this->ui->startChrono();
	this->ui->flag = 100;
}

void Game::reset() {
	this->grid->reset();
	this->stand = STAND::PLAYING;
	this->ui->startChrono();
	this->ui->flag = 100;
}


Game::Game(SDL_Renderer* renderer, TTF_Font * police) {
	this->renderer = renderer;
	this->mine = 100;
	this->grid = new Grid(renderer,mine);
	this->stand = STAND::START;
	this->playButton = new Button_play(350, 350, 100, 50, "./img/button.bmp", renderer);
	this->resetButton = new Button_reset(300, 400, 200, 50, "./img/buttonreset.bmp", renderer);
	gameover = loadTexture("./img/gameover.bmp", renderer);
	win = loadTexture("./img/win.bmp", renderer);
	bg = loadTexture("./img/title.bmp", renderer);
	ui = new UI(police,renderer,mine);
}
void Game::render() {
	if (stand == STAND::PLAYING || stand == STAND::GAMEOVER || stand == STAND::WIN) {
		this->grid->render(renderer);
		if (stand == STAND::GAMEOVER || stand == STAND::WIN) {
			this->resetButton->render(renderer);
			renderTexture(stand== STAND::GAMEOVER?gameover: win, renderer, 200, 200, 0, 0, 400, 150);
		}
		else if (stand == STAND::PLAYING) ui->render(renderer);
	}
	else if (stand == STAND::START) {
		renderTexture(bg,renderer, 0,0 , 0, 0, NULL, NULL);
		this->playButton->render(renderer);
	}
	
	

}

void Game::checkWin() {
	int mineFind = 660;
	for (size_t x = 0; x < 30; x++)
	{
		for (size_t y = 0; y < 22; y++)
		{
			if (grid->cases[x][y]->showing != STATE::MINE && grid->cases[x][y]->showing != STATE::MINETRIGGER && grid->cases[x][y]->showing != STATE::NOTREVEAL) {
				mineFind--;
			}
		}
	}
	std::cout << "mineFind " << mineFind << " mine " << mine;
	if (this->mine == mineFind) stand = STAND::WIN;
}


