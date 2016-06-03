#ifndef GWINT_STUDENCKI_HEADER_H
#define GWINT_STUDENCKI_HEADER_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>


using namespace std;

const int WINDOW_WIDTH=1280;
const int WINDOW_HEIGHT=820;
const int WINDOW_x=100;
const int WINDOW_y=-100;

const int TEACHERS_TEAM = 1;
const int STUDENT_TEAM = 2;

const int ABILITY_NONE = 0;
const int ABILITY_ALL4ONE = 1;
const int ABILITY_SPY = 2;
const int ABILITY_MEDIC = 3;

const int TYPE_MELEE = 1;
const int TYPE_RANGED = 2;
const int TYPE_SIEGE = 3;

const int CURTAIN_TEACHERPASS = 1;
const int CURTAIN_STUDENTPASS = 2;
const int CURTAIN_STUDENTTUNR = 3;
const int CURTAIN_TEACHERTURN = 4;
const int CURTAIN_STUDENTWIN = 5;
const int CURTAIN_TEACHERWIN = 6;

const int ROW_TEACHERS_SIEGE = 14;
const int ROW_TEACHERS_RANGED = 124;
const int ROW_TEACHERS_MELEE = 234;
const int ROW_STUDENTS_MELEE = 361;
const int ROW_STUDENTS_RANGED = 477;
const int ROW_STUDENTS_SIEGE = 589;
const int ROW_BASE = 699;

const int FRAMES_PER_SECOND = 30;

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
#endif