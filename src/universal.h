/*########################
###
###		This Programm
###		falls under the
###		MIT Software
###		license. Check
###		COPYING for 
###		further
###		information.
###
########################*/

#ifndef UNIVERSAL_H
#define UNIVERSAL_H

#include <SDL/SDL.h>

#include "config.h"
#include "random.h"

#define CONFIG_FILE "config"

enum {
		//default values
		
		RES_X = 800,
		RES_Y = 600,
		
		SCREEN_W = 800,
		SCREEN_H = 600,
		
		FPS = 60,
		
		GAME_WIN,
		GAME_OVER,
		GAME_ABORT,
		GAME_RESTART
		
};

typedef struct {
		int fpstime;
		int fps;
		double fps_expected;
		
		/* Placeholder
		fps_expected = FPS;
		fpstime = SDL_GetTicks();		
		*/
} FRAMESPS;

typedef struct {
		int frames;
		int lastframetime;
		int timer;
		
		int gameover;
		int points;
		
		FRAMESPS fps;
} Universal;

extern Universal universal;

void init_universal(void);

void framerate(int *lastframetime);
void fps_calc(FRAMESPS *fps);
// void rotate180(void);
// void fillwithcolor(r,g,b,a); (Red, Green, Blue, Alpha)
void fading(float f);

int gamekeypressed(int keypressed);

#endif