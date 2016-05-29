#include "Gwint_Studencki_Header.h"
#include "Table_Header.h"
#include "Logic_Header.h"

int main(int argc, char* args[])
{

	srand(time(NULL));
	Logic gwent;

	gwent.drawingStudentsCards(); // drawing 10 cards from student's deck
	gwent.drawingTeachersCards();//drawing 10 cards from teacher's deck
	gwent.loadTableTexture(); // get textures to all drawed cards, background and curtains

	SDL_Event * mainEvent = new SDL_Event();

	while (gwent.getEvent(mainEvent)) // function doing all the mouse and keyboard checking as well as logic
	{
		SDL_RenderClear(gwent.getRenderer());
		gwent.showBackground();
		gwent.showAndSetCards();
		gwent.showCurtain(1);
		SDL_RenderPresent(gwent.getRenderer());
	}
	delete mainEvent;
	gwent.~Logic();
	return 0;
}