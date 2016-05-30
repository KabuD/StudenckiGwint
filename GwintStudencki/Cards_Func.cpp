#include "Cards_Header.h"

Cards::Cards(int _index, string _path, int _points, int _type, int _membership, int _ability)
{
	card_rect.x = 0;
	card_rect.y = 0;
	card_rect.h = 100;
	card_rect.w = 100;
	point_rect.x = 0;
	point_rect.y = 0;
	point_rect.w = 30;
	point_rect.h= 30;
	index = _index;
	path = _path;
	points = _points;
	original_points = _points;
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
	SDL_RenderCopy(_renderer, card_points, NULL, &point_rect);
}
void Cards::loadPoints(SDL_Renderer * _renderer)
{
	string cards = "karty/punkty/";
	string png = ".png";
    string pointsInString = to_string(points);
    cards.append(pointsInString); // karty/punkty/"points"
	cards.append(png);// karty/punkty/"points".png
	card_points = NULL;
	card_points = IMG_LoadTexture(_renderer, cards.c_str());
}
void Cards::changePosInRow(double _x)
{
	card_rect.x = _x;
	point_rect.x = _x;
}
void Cards::changeRow(double _y)
{
	card_rect.y = _y;
	point_rect.y = _y;
}
int Cards::getX()
{
	return card_rect.x;
}
int Cards::getY()
{
	return card_rect.y;
}
int Cards::getMembership()
{
	return membership;
}
void Cards::changeMembership()
{
	if (membership == STUDENT_TEAM)membership = TEACHERS_TEAM;
	else membership = STUDENT_TEAM;
}
void Cards::multiplyPoints(int howMany)
{
	points = original_points * pow(2,howMany);
}
int Cards::getType()
{
	return type;
}
string Cards::getName()
{
	return path;
}
int Cards::getPoints()
{
	return points;
}
int Cards::getAbility()
{
	return ability;
}