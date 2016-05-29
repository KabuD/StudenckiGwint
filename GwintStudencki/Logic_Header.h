#ifndef LOGIC_HEADER_H
#define LOGIC_HEADER_H
#include "Deck_Header.h"
class Logic : public Deck
{
private:
	SDL_Point mPosition;
	bool endOfRound;
	bool accepted;
	int StudentsMeleePoints;
	int StudentsRangedPoints;
	int StudentsSiegePoints;
public:
	Logic();
	int getEvent(SDL_Event * e);
	void ifclicked(double _x, double _y);
	void setOnTable(Cards * e, int whichOne);
	~Logic();
};

#endif