#include "TextureManager.h"
#include <iostream>
TextureManager* TextureManager::s_Instance = 0;

TextureManager::TextureManager() {

}

bool TextureManager::load(std::string fileName, std::string textureID, SDL_Renderer *mRenderer) {
	SDL_Surface *tempSurface = IMG_Load(fileName.c_str());
	if (tempSurface == 0) {
		std::cerr << "IMG_Load error: " << SDL_GetError() << std::endl;
		return false;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(mRenderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	if (texture != 0) {
		m_textureMap[textureID] = texture;
		return true;
	}
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *mRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(mRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *mRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(mRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(std::string id) {
	m_textureMap.erase(id);
}

