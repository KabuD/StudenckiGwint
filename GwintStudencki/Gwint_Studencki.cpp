#include "Gwint_Studencki_Header.h"
#include "Deck_Header.h"

int main( int argc, char* args[] )
{
	srand(time(NULL));

	Deck entiredeck;// to get renderer into card's draw() function
	entiredeck.drawingStudentsCards(); // drawing 10 cards from student's deck
	entiredeck.drawingTeachersCards();//drawing 10 cards from teacher's deck
	entiredeck.loadDeckTexture(); // get textures to all drawed cards
	SDL_Texture * background = NULL;
	background = IMG_LoadTexture(entiredeck.getRenderer(), "tekstura.png");
	SDL_Rect background_rect;
	background_rect.x = 0;
	background_rect.y = 0;
	background_rect.h = 866;
	background_rect.w = 1400;
	
	SDL_Event * mainEvent = new SDL_Event();
	while (mainEvent->type != SDL_QUIT)
	{
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(entiredeck.getRenderer());
		SDL_RenderCopy(entiredeck.getRenderer(), background, NULL, &background_rect);
		entiredeck.loadCards();
		SDL_RenderPresent(entiredeck.getRenderer());
	}
	entiredeck.~Deck();
	delete mainEvent;
	return 0;
}