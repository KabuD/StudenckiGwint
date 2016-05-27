#include "Cards_Header.h"

Cards::Cards(int _index, string _path, int _points, int _type, int _membership, int _ability)
{
	card_rect.x = 0;
	card_rect.y = 0;
	card_rect.h = 100;
	card_rect.w = 100;
	index = _index;
	path = _path;
	points = _points;
	type = _type;
	ability = _ability;
	membership = _membership;
}

void Cards::loadCardTexture(SDL_Renderer*_renderer)
{
	card_image = NULL;
	card_image = IMG_LoadTexture(_renderer, path.c_str());
	if (card_image == NULL)
	{
		cout << "file not found: " << path << endl;
		system("PAUSE");
	}
}
void Cards::drawCard(SDL_Renderer *_renderer)
{
	SDL_RenderCopy(_renderer, card_image, NULL, &card_rect);
}
void Cards::changePosInRow(double _x)
{
	card_rect.x = _x;
}
void Cards::changeRow(double _y)
{
	card_rect.y = _y;
}
int Cards::getX()
{
	return card_rect.x;
}
int Cards::getY()
{
	return card_rect.y;
}
int Cards::getMebership()
{
	return membership;
}
int Cards::getType()
{
	return type;
}