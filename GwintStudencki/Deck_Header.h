#ifndef DECK_HEADER_H
#define DECK_HEADER_H

#include "Cards_Header.h"

bool ifDrawed(int iLiczba, int tab[], int ile);

class Deck
{
protected:
	SDL_Renderer *renderer;
	SDL_Window* window;
	SDL_Texture * background;
	


	vector<Cards*>Students;
	vector<Cards*>Teachers;
	vector<Cards*>StudentsBase;
	vector<Cards*>TeachersBase;
public:
	Deck();
	
	void drawingStudentsCards();
	void drawingTeachersCards();
	void loadDeckTexture();
	void loadCards();
	SDL_Renderer * getRenderer();
	~Deck()
	{
		Students.clear();
		Teachers.clear();
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
	}
};

#endif