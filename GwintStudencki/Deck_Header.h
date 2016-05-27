#ifndef DECK_HEADER_H
#define DECK_HEADER_H

#include "Cards_Header.h"

bool ifDrawed(int iLiczba, int tab[], int ile);

class Deck
{
protected:
	SDL_Point mPosition;
	// handlers
	SDL_Renderer *renderer;
	SDL_Window* window;
	SDL_Texture * background;

	int visible; // operates which cards are visible on screen. changing on space in 'Logic'

	// to make sure that cards arent being moved indefinetly in loadCard func
	bool doneStudentBase;
	bool doneTeachersBase;

	bool doneStudentsMelee;
	bool doneStudentsRanged;
	bool doneStudentsSiege;

	bool doneTeachersMelee;
	bool doneTeachersRanged;
	bool doneTeachersSiege;

	bool doneStudentsUsed;
	bool doneTeachersUsed;

    // entire, starting decks
	vector<Cards*>Students;
	vector<Cards*>Teachers;

	// 10 cards that are drawed at the begining
	vector<Cards*>StudentsBase;
	vector<Cards*>TeachersBase;

	// places for Student's cards after clicking them
	vector<Cards*>StudentsMelee;
	vector<Cards*>StudentsRanged;
	vector<Cards*>StudentsSiege;

	// places for Teachers's cards after clicking them
	vector<Cards*>TeachersMelee;
	vector<Cards*>TeachersRanged;
	vector<Cards*>TeachersSiege;

	// places where cards are placed after round
	vector<Cards*>StudentsUsed;
	vector<Cards*>TeachersUsed;

public:
	Deck();
	
	//chooses cards for students deck
	void drawingStudentsCards();
	// chooses cards for teachers deck
	void drawingTeachersCards();
	//loads texture for each card
	void loadDeckTexture();
	//function in loop to show and set cards on screen
	void loadAndSetCards();
	//getting renderer to main
	SDL_Renderer * getRenderer();
    // handling mouse
    void ifclicked(double _x, double _y);
	// getting clicked cards into respective vectors
    void setOnTable(Cards * e, int whichOne);



	~Deck()
	{
		Students.clear();
		Teachers.clear();
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
	}
};

#endif