#include "Logic_Header.h"

Logic::Logic()
{
	mPosition.x = 0;
	mPosition.y = 0;
}
void Logic::setPosition(int _x, int _y)
{
	mPosition.x = _x;
	mPosition.y = _y;
}
int Logic::getEvent(SDL_Event * e)
{
	while (SDL_PollEvent(e) != 0)
	{
		if (e->type == SDL_KEYDOWN)
		{
			switch (e->key.keysym.sym)
			{
			case 27:
			{
					   return 0;
			}
			case ' ':
			{
						if (visible == TEACHERS_TEAM)visible = STUDENT_TEAM;
						else visible = TEACHERS_TEAM;
						return 1;
			}
			}
		}
		if (e->type == SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			setPosition(x, y);
		ifclicked(x, y);
			return 1;
		}
	}
	return 1;
}