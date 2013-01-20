
#include "universal.h"
#include "gfx.h"
#include <stdlib.h>

static GraphicsMode estimated_modes[] = { //4:3
		{RESOLUTIONX, RESOLUTIONY},
		
		{640, 480},
		{800, 600},
		{1024, 768},
		{1280, 960},
		{1152, 864},
		{1400, 1050},
		{1440, 1080},

		{0, 0},
};

void gfx_init(void) {
		SDL_Rect **modes;
		int i;
		
		memset(&graphics, 0, sizeof(graphics));
		
		modes = SDL_ListModes(NULL, SDL_FULLSCREEN | SDL_HWSURFACE);
		if(!modes) {
			printf("gfx_init(): There ain't any fullscreen modes");
			tconfig.intval[FULLSCREEN] = False;
		} else if(modes == (SDL_Rect**)-1) {
			printf("gfx_init(): There could be compability issues with your standard video drivers");
		} else {
			for(i = 0; modes[i]; i++) {
				gfx_add_mode(modes[i]->w, modes[i]->h);
			}
		}
		
		for(i = 0; estimated_modes[i].width; i++) {
			gfx_add_mode(estimated_modes[i].width, estimated_modes[i].height);
		}
		
		qsort(graphics.modes, graphics.modecount, sizeof(GraphicsMode), gfx_compare_modes);
		
		gfx_setmode(tconfig.intval[GFX_WIDTH, tconfig.intval[GFX_HEIGHT], tconfig.intval[FULLSCREEN]);
		SDL_WM_SetCaption("Battleships",NULL);
}

void gfx_shutdown(void) {
		SDL_FreeSurface(display);
		free(graphics.modes);
}

static void _gfx_setmode(int w, int h, int fullscreen, int fallback) {
		int sdlflags = SDL_OPENGL;
		
		if(fullscreen) sdlflags |=SDL_FULLSCREEN;
		
		if(!fallback) {
			graphics.estimated.width = w;
			graphics.estimated.height = h;
		}
		
		if(display) {
			SDL_FreeSurface(display);
		}
		
		if(!display = SDL_SetVideoMode(w, h, 32, sdlflags))) {
			if(fallback) {
				printf("graphics_setmode(): Screen couldn't be opened: %s", SDL_GetError());
				return -1;
			}
			
			printf("graphics_setmode(): Setting the Resolution to %dx%d failed, trying to fall back to %dx%d", w, h, RESOLUTIONX, RESOLUTIONY);
			_gfx_setmode(RESOLUTIONX, RESOLUTIONY, fullsreen, True);
		}
		
		const SDL_VideoInfo *info = SDL_GetVideoInfo();
		graphics.current.width = info->current_w;
		graphics.current.height = info->current_h;
		
		glViewport(0, 0, graphics.current.width, graphics.current.height);
}

static void gfx_setmode(int w, int h, int fullscreen) { //for debugging purposes
		_graphics_setmode(w, h, fullscreen, False);
}

int gfx_fullscreenset(void) {
		return !!(display->sdlflags & SDL_FULLSCREEN);
}

void gfx_tooglefullscreen(void) {
		gfx_setmode(graphics.target.width, graphics.target.height, !gfx_fullscreenset());
}
	
static void gfx_add_mode(int width, int height) {
		if(graphics.modes) {
			int i; 
			for(i = 0; i < graphics.modecount; i++) {
				GraphicsMode *m = &(graphics.modes[i]);
				if(m->width == width && m->height == height)
					return;
			}
		}

		graphics.modes = (GraphicsMode*)realloc(graphics.modes, (++graphics.modecount) * sizeof(GraphicsMode));
		graphics.modes[graphics.modecount-1].width  = width;
		graphics.modes[graphics.modecount-1].height = height;
}	
	
static int gfx_compare_modes(const void *a, const void *b) {
	GraphicsMode *ga = (GraphicsMode*)a;
	GraphicsMode *gb = (GraphicsMode*)b;
	return ga->width * ga->height - gb->width * gb->height;
}