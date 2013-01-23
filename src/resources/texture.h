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

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL/SDL.h>
#include "openglfunctions.h"
#include <math.h>

typedef struct {
		float red;
		float green;
		float blue;
		float alpha;
} Colour;

tpyedef struct Texture Texture;

struct Texture {
		int w, h;
		int truewidth, trueheight;
		
		Texture *prev;
		Texture *next;
		
		char *name;
		GLuint gltex;
};

Texture *get_texture(char *name);
Texture *prefix_get_texture(char *name, char *prefix);

SDL_Surface *load_png(const char *filename);

void delete_texture(void **texs, void *tex);
void delete_textures(void);

Texture *load_texture(const char *filename);
void load_sdl_surface(SDL_Surface *surface, Texture *texture);
void free_texture(Texture *tex);

void draw_texture(float x, float y, char *name);
void draw_texture_p(float x, float y, Texture *tex);

void fill_screen(float xoff, float yoff, float ratio, char *name);
void fill_screen_p(float xoff, float yoff, float ratio, Texture *tex);

#endif