
#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H
#include<iostream>
#include<Windows.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<iostream>
#include<algorithm>
#include<fstream>


static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

const int SCREEN_WIDTH = 890;
const int SCREEN_HEIGHT = 500;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_B = 175;
const int COLOR_KEY_G = 180;

const int RENDER_DRAW_COLOR = 0Xff;
#define TILE_SIZE_ 64
#define MAX_MAP_X 400
#define MAX_MAP_Y 10
typedef struct Input
{
	int right_;
	int left_;
	int up_; 
	int down_;
	int jump_;

};
namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();
}

#endif
