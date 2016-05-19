#include "Cards_Header.h"

Card::Card(string _path, int _points, int _ability, int _svp)
{
	x = 0;
	y = 0;
	w = 100;
	h = 100;
	path = _path;
	points = _points;
	ability = _ability;
	svp = _svp;
}

void Card::Print()
{
}