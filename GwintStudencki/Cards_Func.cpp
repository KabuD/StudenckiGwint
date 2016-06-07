#include "Cards_Header.h"

Cards::Cards(int _index, string _path, int _points, int _type, int _membership, int _ability)
{
	card_rect = { 0, 0, 100, 100 };
	point_rect = { 0, 0, 30, 30 };
	ability_rect = { 0, 0, 30, 30 };
	type_rect = { 0, 0, 30, 30 };

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
	if (ability){ SDL_RenderCopy(_renderer, card_ability, NULL, &ability_rect); }
	SDL_RenderCopy(_renderer, card_type, NULL, &type_rect);
}

void Cards::loadPoints(SDL_Renderer * _renderer)
{
	string cards = "karty/punkty/";
	string png = ".png";
    string ToString = to_string(points);
    cards.append(ToString); // karty/punkty/"points"
	cards.append(png);// karty/punkty/"points".png
	card_points = NULL;
	card_points = IMG_LoadTexture(_renderer, cards.c_str());

	
	cards = "karty/type/";
	ToString = to_string(type);
	cards.append(ToString); 
	cards.append(png);
	card_type = NULL;
	card_type = IMG_LoadTexture(_renderer, cards.c_str());
	
	if (ability)
	{
		cards = "karty/ability/";
		ToString = to_string(ability);
		cards.append(ToString);
		cards.append(png);
		card_ability = NULL;
		card_ability = IMG_LoadTexture(_renderer, cards.c_str());
	}
}

void Cards::changePosInRow(int _x)
{
	card_rect.x = _x;
	point_rect.x = _x;
	ability_rect.x = _x + 35;
	type_rect.x = _x;
}

void Cards::changeRow(int _y)
{
	card_rect.y = _y;
	point_rect.y = _y;
	ability_rect.y = _y+70;
	type_rect.y = _y+70;
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

void Cards::getOldPoints()
{
	points = original_points;
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

void Cards::maximizeCard()
{
	if (ability)ability_rect = { 0, 0, 60, 60 };
	point_rect = { 0, 0, 60, 60 };
	type_rect = { 0, 0, 60, 60 };
	card_rect = { 0, 0, 200, 200 };
}

void Cards::normalizeCard()
{
	if (ability)	ability_rect = { 0, 0, 30, 30 };
	card_rect = { 0, 0, 100, 100 };
	point_rect = { 0, 0, 30, 30 };
	type_rect = { 0, 0, 30, 30 };
}