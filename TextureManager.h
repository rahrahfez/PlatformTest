/*
Loads and draw textures, also animations
*/
#pragma once
#include "Game.h"
#include <SDL_image.h>
#include <map>
#include <string>

class TextureManager {
public:
	TextureManager();
	bool load(std::string fileName, std::string textureID, SDL_Renderer *mRenderer);
	void draw(std::string textureID, int x, int y, int width, int height, SDL_Renderer *mRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string textureID, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *mRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	std::map<std::string, SDL_Texture*>getTextureMap() { return mtextureMap; }
	void clearFromTextureMap(std::string id);
private:
	std::map<std::string, SDL_Texture*>mtextureMap;
};


