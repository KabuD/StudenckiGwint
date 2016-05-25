#ifndef GWINT_STUDENCKI_HEADER_H
#define GWINT_STUDENCKI_HEADER_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

const int WINDOW_WIDTH=1400;
const int WINDOW_HEIGHT=866;
const int WINDOW_x=200;
const int WINDOW_y=-900;
int *wylosuj(int arr[]);
bool czyBylaWylosowana(int iLiczba, int tab[], int ile);
int wylosuj();
#endif