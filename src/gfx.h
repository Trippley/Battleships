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

#ifndef GFX_H
#define GFX_H

typedef struct GraphicsMode {
		unsigned int width;
		unsigned int height;
} GraphicsMode;

typedef struct {
		GraphicsMode *modes;
		int modecount;
		GraphicsMode target;
		GraphicsMode current;
} Graphics;

Graphics graphics;
SDL_Surface *display;

void gfx_init(void);
void gfx_shutdown(void);
void gfx_setmode(int w, int h, int fullscreen);
int gfx_fullscreenset(void);
void gfx_tooglefullscreen(void);

#endif