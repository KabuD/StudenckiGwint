#ifndef TABLE_HEADER_H
#define TABLE_HEADER_H

#include "Cards_Header.h"

bool ifDrawed(int iLiczba, int tab[], int ile);

class Table
{
protected:
	SDL_Point mPosition;
	// handlers
	SDL_Renderer *renderer;
	SDL_Window* window;

	SDL_Texture * image_score;

	SDL_Texture * image_teachersTurn;
	SDL_Texture * image_teachersPass;

	SDL_Texture * image_studentsTurn;
	SDL_Texture * image_studentsPass;

	SDL_Texture * back;

	SDL_Rect screen_rect;

	int whosTurn; // operates which team can use the card
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
	Table();
	
	//chooses cards for students deck
	void drawingStudentsCards();
	// chooses cards for teachers deck
	void drawingTeachersCards();
	//func used after using spy
	void drawOneCard(int whichTeam);
	//loads texture for each card
	void loadTableTexture();
	// used in all4one ability and in setting next round
	void reloadPoints();
	//for loop
	void showBackground();
	//function in loop to show and set cards on screen
	void showAndSetCards();
	//getting renderer to main
	SDL_Renderer * getRenderer();
	//gets curtain on screen after certain actions
	void showCurtain(int whichOne);
	void loadBackgroundAndCurtains();


	
};

#endif