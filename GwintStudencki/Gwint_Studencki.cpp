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

	SDL_Event * mainEvent = new SDL_Event();

	while (gwent.getEvent(mainEvent)) // function doing all the mouse and keyboard checking as well as logic
	{
		SDL_RenderClear(gwent.getRenderer());
		gwent.showBackground();
		gwent.showAndSetCards();
		gwent.viewPointScore();
		gwent.showCurtain(1);
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

/*
//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frames per second
const int FRAMES_PER_SECOND = 20;




class Timer
{
private:
	//The clock time when the timer started
	int startTicks;

	//The ticks stored when the timer was paused
	int pausedTicks;

	//The timer status
	bool paused;
	bool started;

public:
	//Initializes variables
	Timer();

	//The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	//Gets the timer's time
	int get_ticks();

	//Checks the status of the timer
	bool is_started();
	bool is_paused();
};


Timer::Timer()
{
	//Initialize the variables
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}

void Timer::start()
{
	//Start the timer
	started = true;

	//Unpause the timer
	paused = false;

	//Get the current clock time
	startTicks = SDL_GetTicks();
}

void Timer::stop()
{
	//Stop the timer
	started = false;

	//Unpause the timer
	paused = false;
}

void Timer::pause()
{
	//If the timer is running and isn't already paused
	if ((started == true) && (paused == false))
	{
		//Pause the timer
		paused = true;

		//Calculate the paused ticks
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void Timer::unpause()
{
	//If the timer is paused
	if (paused == true)
	{
		//Unpause the timer
		paused = false;

		//Reset the starting ticks
		startTicks = SDL_GetTicks() - pausedTicks;

		//Reset the paused ticks
		pausedTicks = 0;
	}
}

int Timer::get_ticks()
{
	//If the timer is running
	if (started == true)
	{
		//If the timer is paused
		if (paused == true)
		{
			//Return the number of ticks when the timer was paused
			return pausedTicks;
		}
		else
		{
			//Return the current time minus the start time
			return SDL_GetTicks() - startTicks;
		}
	}

	//If the timer isn't running
	return 0;
}

bool Timer::is_started()
{
	return started;
}

bool Timer::is_paused()
{
	return paused;
}

int main(int argc, char* args[])
{
	//Quit flag
	bool quit = false;

	//Keep track of the current frame
	int frame = 0;

	//Whether or not to cap the frame rate
	bool cap = true;

	//The frame rate regulator
	Timer fps;



	while (quit == false)
	{
		//Start the frame timer
		fps.start();

		//While there's events to handle
		while (SDL_PollEvent(&event))
		{
			//If a key was pressed
			if (event.type == SDL_KEYDOWN)
			{
				//If enter was pressed
				if (event.key.keysym.sym == SDLK_RETURN)
				{
					//Turn frame rate regulator on/off
					cap = (!cap);
				}
			}

			//If the user has Xed out the window
			else if (event.type == SDL_QUIT)
			{
				//Quit the program
				quit = true;
			}
		}

		//Increment the frame counter
		frame++;

		//If we want to cap the frame rate
		if ((cap == true) && (fps.get_ticks() < 1000 / FRAMES_PER_SECOND))
		{
			//Sleep the remaining frame time
			SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
		}
	}

	//Clean up
	clean_up();

	return 0;
}





*/