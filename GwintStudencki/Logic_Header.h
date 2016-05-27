#ifndef LOGIC_HEADER_H
#define LOGIC_HEADER_H
#include "Deck_Header.h"
class Logic : public Deck
{
private:
	SDL_Point mPosition;
public:
	Logic();
	void setPosition(int _x, int _y);
	int getEvent(SDL_Event * e);
	
};

#endif