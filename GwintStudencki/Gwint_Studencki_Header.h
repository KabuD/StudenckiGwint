#ifndef GWINT_STUDENCKI_HEADER_H
#define GWINT_STUDENCKI_HEADER_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

const int WINDOW_WIDTH=1400;
const int WINDOW_HEIGHT=866;
const int WINDOW_x=200;
const int WINDOW_y=-900;

const int TEACHERS_TEAM = 1;
const int STUDENT_TEAM = 2;
const int NOT_VISIBLE_CARD = 0;
const int VISIBLE_CARD = 1;
const int ABILITY_NONE = 0;
const int ABILITY_ALL4ONE = 1;
const int ABILITY_SPY = 2;
const int ABILITY_MEDIC = 3;
const int TYPE_MELEE = 1;
const int TYPE_RANGED = 2;
const int TYPE_SIEGE = 3;

#endif