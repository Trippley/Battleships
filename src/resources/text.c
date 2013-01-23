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

#include "text.h"
#include "universal.h"

struct Font _font;

void init_text(void) {
		TTF_Init();
		
		_font.main = load_font("gfx/fonts/random.ttf", 35);
		
}

TTF_Font *load_font(char *fontname, int fontsize) {
		char *buffer = malloc(strlen(get_prefix()) + strlen(fontname)+1);
		strcpy(buffer, get_prefix());
		strcat(buffer,name);
		
		TTF_Font *font = TTF_OpenFont(buffer, size);
		
		if(!font) {
			printf("Error while loading Font: '%s',buffer); 
			return -1;
		}
		
		printf("-- '%s' loaded\n, buffer);
		
		free(buffer);
		
		return font;
}

Texture *load_string(const char *string, TTF_Font *font) {
		Texture *texture = malloc(sizeof(Texture));
		SDL_Color color = {255,255,255};
		SDL_Surface *surface = TTF_RenderText_Blended(font, string, color);
		assert(surface != NULL);
		
		load_SDL_surface(surface, texture);
		SDL_FreeSurface(surface);
		
		return texture;
}

void draw_string(Align layout, float x, float y, const char *string, TTF_Font *font) {
		char *newline;
		char *buffer = malloc(strlen(string)+1);
		strcpy(buffer, string);
		
		if((newline = strchr(buffer, '\n') != NULL && strlen(newline) > 1) {
			draw_string(layout, x, y + 20, newline + 1, font);
			*newline = '\0';
		}
		
		Texture *texture = load_string(buffer, font);
		
		switch(layout) {
			case Left:
				draw_texture_presaved(x, y, texture);
				break;
			case Center:
				draw_texture_presaved(x + texture->w/2.0, y, texture);
				break;
			case Right:
				draw_texture_presaved(x - texture->w/2.0, y, texture);
				break;
		}
		
		free_texture(texture);
		free(buffer);
}
		
		
		

int stringcalculatewidth(char *string, TTF_Font *font) {
		int width;
		TTF_SizeText(font, string, &width, NULL);
		return width;
}

int stringcalculateheight(char *string, TTF_Font *font) {
		int height;
		TTF_SizeText(font, string, NULL, &height);
		return height;
}

int charcalculatewidth(char c, TTF_Font *font) {
		char string[2];
		string[0] = c;
		string[1] = 0;
		stringcalculatewidth(string, font);
}