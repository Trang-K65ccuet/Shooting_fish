#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H

#include<Windows.h>
#include<SDL.h>

#include<string>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 601;
const int SCREEN_BPP = 32;
const int NUM_FISH1 = 3;
const int NUM_FISH2 = 2;
const int NUM_BOMB = 4;
 
static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Surface* g_menu = NULL;
static SDL_Surface* g_end = NULL;
static SDL_Event g_even;

static Mix_Chunk* g_sound_bullet;
static Mix_Chunk* g_sound_exp[2];
static Mix_Chunk* g_sound_track;

namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y);
	void CleanUp();
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
	int ShowMenu(SDL_Surface* des, TTF_Font* font);
	int ShowEnd(SDL_Surface* des, TTF_Font* font);
}

#endif
