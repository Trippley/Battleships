

#include "universal.h"
#include "gfx.h"

#include <SDL/SDL.h>
#include <time.h>
#include <stdio.h>
#include <png.h>

Universal universal;

void init_universal(void) {
		memset(&universal, 0, sizeof(universal));
		
		printf("- Loading Fonts:\n");
		init_text();
		
		SDL_EnableKeyRepeat(75, 50); //Keyboard Repeating Delay and Intervall
		
}

void framerate(int *lastframetime) {
		int t = *lastframetime + 1000.0/FPS - SDL_GetTicks();
		if(t > 0) {
				SDL_Delay(t);
		}
		
		*lastframetime = SDL_GetTicks();
}

void fps_calc(FRAMESPS *fps) {
		if(!fps->fps_expected) {
			fps->fps_expected = FPS;
		}
	
		if(SDL_GetTicks() > fps->fpstime+1000) {
			fps->fps_show = fps->fps;
			fps->fps = 0;
			fps->fpstime = SDL_GetTicks();
		} else {
			fps->fps++;
		}
		
		fps->fps_expected = near(); //anything else for that? should contain fps->fps_expected, fps->fps_show, 0.1
}
		

fillwithcolor(int red, int green, int blue, int alpha) {

	if(alpha <= 0) return;
//
//
//

}

void fading(float f) {
		fillwithcolor(0, 0, 0, f);
}

