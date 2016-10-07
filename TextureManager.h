/*
Loads and draw textures, also animations
testing backup file
*/
#pragma once
#include "Game.h"
#include <SDL_image.h>
#include <map>
#include <string>

class TextureManager {
public:
      static TextureManager* Instance() {
		if (s_Instance == 0) {
			s_Instance = new TextureManager();
			return s_Instance;
	  }
		return s_Instance;
  }

	bool load(std::string fileName, std::string textureID, SDL_Renderer *mRenderer);
	void draw(std::string textureID, int x, int y, int width, int height, SDL_Renderer *mRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string textureID, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *mRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	std::map<std::string, SDL_Texture*>getTextureMap() { return m_textureMap; }
	void clearFromTextureMap(std::string id);
private:
    TextureManager();
	std::map<std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_Instance;
};
typedef TextureManager TextureManager;





