#include "TextureLoader.h"

void log(std::ostream& os, const std::string& msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

SDL_Texture* loadTexture(const std::string& file, SDL_Renderer* ren) {
	//Initialize to nullptr to avoid dangling pointer issues
	SDL_Texture* texture = nullptr;
	//Load the image
	SDL_Surface* loadedImage = SDL_LoadBMP(file.c_str());
	//If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (texture == nullptr) {
			log(std::cout, "CreateTextureFromSurface");
		}
	}
	else {
		log(std::cout, "LoadBMP");
	}
	return texture;
}

void renderTexture(SDL_Texture* tex, SDL_Renderer* ren, int x, int y,int indexX, int indexY,int w,int h) {
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	SDL_Rect SrcR;
	dst.x = x;
	dst.y = y;

	if (w && h) {
		dst.w=w;
		dst.h=h;
	}
	else SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	//std::cout << dst.w << std::endl;
	SrcR.x = 0+(25*indexX);
	SrcR.y = 0 + (25 * indexY);
	SrcR.w = w ? w : dst.w;
	SrcR.h = h ? h : dst.h;
	//Query the texture to get its width and height to use
	SDL_RenderCopy(ren, tex, &SrcR, &dst);

	
}