#ifndef CONFIG_H
#define CONFIG_H

#include <SDL/SDL_keysym.h>

typedef struct Configuration {
	int 	intval[64];
	char* 	strval[64];
} Configuration;

extern Configuration tconfig;

typedef enum ConfigKey {
	KEY_UP = 0,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	
	KEY_SHOT,

	KEY_FULLSCREEN,
	KEY_MENU,

	FULLSCREEN,

	NO_SHADER,
	NO_AUDIO,

	NO_STAGEBG,
	NO_STAGEBG_FPSLIMIT,

	GFX_WIDTH,
	GFX_HEIGHT,
	
	FIELDW,
	FIELDH,

	PLAYERNAME
} ConfigKey;

#define CONFIG_KEY_FIRST KEY_UP
#define CONFIG_KEY_LAST KEY_MENU

#define CONFIG_LOAD_BUFFERSIZE 256