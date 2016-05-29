#include "Gwint_Studencki_Header.h"
#include "Deck_Header.h"
#include "Logic_Header.h"

int main(int argc, char* args[])
{

	srand(time(NULL));
	Logic entirelogic;

	entirelogic.drawingStudentsCards(); // drawing 10 cards from student's deck
	entirelogic.drawingTeachersCards();//drawing 10 cards from teacher's deck
	entirelogic.loadDeckTexture(); // get textures to all drawed cards

	SDL_Texture * background = NULL;
	background = IMG_LoadTexture(entirelogic.getRenderer(), "tekstura.png");

	SDL_Rect background_rect;

	background_rect.x = 0;
	background_rect.y = 0;
	background_rect.h = 866;
	background_rect.w = 1400;

	SDL_Event * mainEvent = new SDL_Event();
	while (entirelogic.getEvent(mainEvent)) // function doing all the mouse and keyboard checking as well as logic
	{
		SDL_RenderClear(entirelogic.getRenderer());
		SDL_RenderCopy(entirelogic.getRenderer(), background, NULL, &background_rect);
		entirelogic.loadAndSetCards();
		SDL_RenderPresent(entirelogic.getRenderer());
	}
	delete mainEvent;
	SDL_DestroyTexture(background);
	entirelogic.~Logic();
	return 0;
}