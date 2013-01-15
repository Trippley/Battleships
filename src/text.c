

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
		
		TTF_Font *f = TTF_OpenFont(buffer, size);
		
		if(!f) {
			printf("Error while loading Font: '%s',buffer); 
			return -1;
		}
		
		printf("-- '%s' loaded\n, buffer);
		
		free(buffer);
		
		return f;
}

//texture convert text()

//draw text with alignment

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