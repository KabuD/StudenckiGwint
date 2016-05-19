#include "Gwint_Studencki_Header.h"
#include "Game_Header.h"
#include "Deck_Header.h"

int main( int argc, char* args[] )
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = NULL;
	window = SDL_CreateWindow("Gwint Studencki", WINDOW_x, WINDOW_y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		system("PAUSE");
	}
	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	Deck oneandonly(renderer); // to get renderer into card's draw() function

	SDL_Texture * background = NULL;
	background = IMG_LoadTexture(renderer, "tekstura.png");

	SDL_Rect background_rect;
	background_rect.x = 0;
	background_rect.y = 0;
	background_rect.h = 866;
	background_rect.w = 1400;

	SDL_Event * mainEvent = new SDL_Event();
	while (mainEvent->type != SDL_QUIT)
	{
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, background, NULL, &background_rect);
		oneandonly.Draw();

		SDL_RenderPresent(renderer);
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
	return 0;
}