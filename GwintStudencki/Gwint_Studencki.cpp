#include "Gwint_Studencki_Header.h"
#include "Table_Header.h"
#include "Logic_Header.h"

int main(int argc, char* args[])
{

	srand(time(NULL));
	Logic gwent;

	//Keep track of the current frame
	int frame = 0;
	//Whether or not to cap the frame rate
	bool cap = true;
	//The frame rate regulator
	Timer fps;


	gwent.loadStudentsCards(); // drawing 10 cards from student's deck
	gwent.loadTeachersCards();//drawing 10 cards from teacher's deck
	gwent.loadTableTexture(); // get textures to all drawed cards, background and curtains
	gwent.loadCounter();
	gwent.loadCurtains();

	SDL_Event * mainEvent = new SDL_Event();

	while (gwent.getEvent(mainEvent)) // function doing all the mouse and keyboard checking as well as logic
	{
		SDL_RenderClear(gwent.getRenderer());
		gwent.showBackground();
		gwent.showAndSetCards();
		gwent.checkIfEndRound();
		gwent.checkIfEndGame();
	    gwent.showCurtain(gwent.returnCurtain());
		gwent.viewPointScore();
		SDL_RenderPresent(gwent.getRenderer());


		frame++;
		//If we want to cap the frame rate
		if ((cap == true) && (fps.get_ticks() < 1000 / FRAMES_PER_SECOND))
		{
			//Sleep the remaining frame time
			SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
		}
	
	}
	delete mainEvent;
	gwent.~Logic();
	return 0;
}

