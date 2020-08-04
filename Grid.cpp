#include "Grid.h"



Grid::Grid(SDL_Renderer* renderer, int mine) {
	this->x = 0;
	this->y = 0;
	this->texture = loadTexture("./img/background.bmp", renderer);
	for (size_t x = 1; x < 31; x++)
	{
		std::vector<Cell*> ligne;
		for (size_t y = 1; y < 23; y++)
		{
			ligne.push_back(new Cell(renderer, x, y));
		}
		cases.push_back(ligne);
	}
	this->mine = mine;
	init(mine);
}

void Grid::render(SDL_Renderer* renderer) {
	renderTexture(texture, renderer, x, y, 0, 0, NULL, NULL);
	for (size_t x = 0; x < 30; x++)
	{
		for (size_t y = 0; y < 22; y++)
		{
			cases[x][y]->render(renderer);
		}
	}
}

void Grid::reset() {
	for (size_t x = 0; x < 30; x++)
	{
		for (size_t y = 0; y < 22; y++)
		{
			cases[x][y]->content = STATE::EMPTY;
			cases[x][y]->showing = STATE::NOTREVEAL;
		}
	}
	init(mine);
}

void Grid::revealMine() {
	for (size_t x = 0; x < 30; x++)
	{
		for (size_t y = 0; y < 22; y++) {
			if (cases[x][y]->content == STATE::MINE && cases[x][y]->showing != STATE::MINETRIGGER)cases[x][y]->showing = STATE::MINE;
		}
	}
}

void Grid::init(int mine) {
	int minecount = 100;
	while (minecount > 0) {
		int xmine = rand() % 29 + 0;
		int ymine = rand() % 21 + 0;
		if(cases[xmine][ymine]->content != STATE::MINE ){
			std::cout << xmine << " " << ymine << std::endl;
			cases[xmine][ymine]->content = STATE::MINE;
			minecount--;
		}
	}
	for (size_t x = 0; x < 30; x++)
	{
		for (size_t y = 0; y < 22; y++)
		{
			if(cases[x][y]->content != STATE::MINE)cases[x][y]->content = (STATE)neighbourMine(x, y);
		}
	}
}

int Grid::neighbourMine(int x, int y) {
	int count = 0;
	if (x - 1 >= 0) {
		if (cases[x-1][y]->content == STATE::MINE) count++;
	}
	if (x + 1 <= 29) {
		if (cases[x + 1][y]->content == STATE::MINE) count++;
	}
	if (y - 1 >= 0) {
		if (cases[x][y-1]->content == STATE::MINE) count++;
	}
	if (y + 1 <= 21) {
		if (cases[x][y+1]->content == STATE::MINE) count++;
	}
	if (x - 1 >= 0 && y - 1 >= 0) {
		if (cases[x-1][y - 1]->content == STATE::MINE) count++;
	}
	if (x - 1 >= 0 && y + 1 <= 21) {
		if (cases[x-1][y + 1]->content == STATE::MINE) count++;
	}
	if (x + 1 <= 29 && y - 1 >= 0) {
		if (cases[x+1][y - 1]->content == STATE::MINE) count++;
	}
	if (x + 1 <= 29 && y + 1 <= 21) {
		if (cases[x+1][y + 1]->content == STATE::MINE) count++;
	}
	if (count == 0) count = 12;
	return count;
}


void Grid::revealNeighbour(int x, int y) {
	if (x - 1 >= 0) {
		if (cases[x - 1][y]->content != STATE::MINE && cases[x - 1][y]->showing == STATE::NOTREVEAL) {
			cases[x - 1][y]->showing = cases[x - 1][y]->content;
			if (cases[x - 1][y]->content == STATE::EMPTY) revealNeighbour(x-1,y);
		}
	}
	if (x + 1 <= 29) {
		if (cases[x + 1][y]->content != STATE::MINE && cases[x + 1][y]->showing == STATE::NOTREVEAL) {
			cases[x + 1][y]->showing = cases[x + 1][y]->content;
			if (cases[x + 1][y]->content == STATE::EMPTY) revealNeighbour(x + 1, y);
		}
	}
	if (y - 1 >= 0) {
		if (cases[x][y-1]->content != STATE::MINE && cases[x][y - 1]->showing == STATE::NOTREVEAL) {
			cases[x][y-1]->showing = cases[x][y-1]->content;
			if (cases[x][y-1]->content == STATE::EMPTY) revealNeighbour(x, y-1);
		}
	}
	if (y + 1 <= 21) {
		if (cases[x][y+1]->content != STATE::MINE && cases[x][y + 1]->showing == STATE::NOTREVEAL) {
			cases[x][y+1]->showing = cases[x][y+1]->content;
			if (cases[x][y+1]->content == STATE::EMPTY) revealNeighbour(x, y+1);
		}
	}
	if (x - 1 >= 0 && y - 1 >= 0) {
		if (cases[x - 1][y-1]->content != STATE::MINE && cases[x - 1][y - 1]->showing == STATE::NOTREVEAL) {
			cases[x - 1][y-1]->showing = cases[x - 1][y-1]->content;
			if (cases[x - 1][y-1]->content == STATE::EMPTY) revealNeighbour(x - 1, y-1);
		}
	}
	if (x - 1 >= 0 && y + 1 <= 21) {
		if (cases[x - 1][y+1]->content != STATE::MINE && cases[x - 1][y + 1]->showing == STATE::NOTREVEAL) {
			cases[x - 1][y+1]->showing = cases[x - 1][y+1]->content;
			if (cases[x - 1][y+1]->content == STATE::EMPTY) revealNeighbour(x - 1, y+1);
		}
	}
	if (x + 1 <= 29 && y - 1 >= 0) {
		if (cases[x + 1][y - 1]->content != STATE::MINE && cases[x + 1][y - 1]->showing == STATE::NOTREVEAL) {
			cases[x + 1][y - 1]->showing = cases[x + 1][y - 1]->content;
			if (cases[x + 1][y - 1]->content == STATE::EMPTY) revealNeighbour(x + 1, y - 1);
		}
	}
	if (x + 1 <= 29 && y + 1 <= 21) {
		if (cases[x + 1][y + 1]->content != STATE::MINE && cases[x + 1][y + 1]->showing == STATE::NOTREVEAL) {
			cases[x + 1][y + 1]->showing = cases[x + 1][y + 1]->content;
			if (cases[x + 1][y + 1]->content == STATE::EMPTY) revealNeighbour(x + 1, y + 1);
		}
	}

}