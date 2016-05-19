#ifndef GWINT_STUDENCKI_HEADER_H
#define GWINT_STUDENCKI_HEADER_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

const int WINDOW_WIDTH = 1366;
const int WINDOW_HEIGHT = 768;
const int WINDOW_x = 200;
const int WINDOW_y = -800;

bool init();
bool loadMedia();
void close();
void applythepng();







#endif