#include "Cards_Header.h"

Cards::Cards(int _index, string _path, int _points, int _type, int _membership, int _ability)
{
	card_rect.x = 0;
	card_rect.y = 0;
	card_rect.h = 150;
	card_rect.w = 150;
	index = _index;
	path = _path;
	points = _points;
	type = _type;
	ability = _ability;
	membership = _membership;
}
void Cards::Draw(SDL_Renderer *_renderer)
{
	card_image = NULL;
	card_image = IMG_LoadTexture(_renderer, path.c_str());
	if (card_image == NULL)
	{
		cout << "file not found: " << path << endl;
		system("PAUSE");
	}
	SDL_RenderCopy(_renderer, card_image, NULL, &card_rect);
}