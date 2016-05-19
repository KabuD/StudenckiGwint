#ifndef Game_Header_H
#define Game_Header_H

#include "Gwint_Studencki_Header.h"
#include "Cards_Header.h"

class Game
{
private:
    int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	int WINDOW_x;
	int WINDOW_y;
	SDL_Window* gWindow;
	SDL_Surface* gScreenSurface;
	SDL_Surface* gPNGSurface;
public:
	Game()
	{
		WINDOW_WIDTH = 1300;
		WINDOW_HEIGHT = 866;
		WINDOW_x = 200;
		WINDOW_y = -800;
		SDL_Window* gWindow = NULL;
		SDL_Surface* gScreenSurface = NULL;
		SDL_Surface* gPNGSurface = NULL;
	}
	SDL_Surface* loadSurface(std::string path);
	bool init();
	bool loadMedia();
	void close();
	void applythepng();
};

#endif