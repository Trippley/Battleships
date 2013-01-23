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

#ifndef TEXT_H
#define TEXT_H

#include <SDL/SDL.h>
#include <SDL/SDL_tff.h>

typedef enum {
		LAY_LEFT,
		LAY_CENTER,
		LAY_RIGHT
} Align;


void draw_string(Align layout, float x, float y, const char *string, TTF_Font *font);
void init_text(void);
int stringcalculatewidth(char *string, TTF_Font *font);
int stringcalculateheight(char *string, TTF_Font *font);
int charcalculatewidth(char c, TTF_Font *font);

struct Font { 
		TTF_Font *main;
};

extern struct Font _font;

#endif