#include "Gwint_Studencki_Header.h"

//Loads individual image
SDL_Surface* loadSurface(std::string path);
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;

