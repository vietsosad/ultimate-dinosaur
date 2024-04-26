
#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H
#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<iostream>
#include<algorithm>
#include<fstream>
//#include "TextObject.h"

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

const int SCREEN_WIDTH = 890;
const int SCREEN_HEIGHT = 500;

//const int COLOR_KEY_R = 167;
//const int COLOR_KEY_B = 175;
//const int COLOR_KEY_G = 180;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int CORLOR_KEY_B = 180;


static Mix_Chunk* g_sound_jump;
static Mix_Chunk* g_sound_background;
static Mix_Chunk* g_sound_touching;
static Mix_Chunk* g_sound_click;
static Mix_Chunk* g_sound_menu;
const int RENDER_DRAW_COLOR = 0Xff;
#define TILE_SIZE_ 64

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

	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& other_object);
	
}

#endif
// Le Hoang Viet