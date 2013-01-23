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

#ifndef RESOURCES_H
#define RESOURCES_H

#include "universal.h"

#include "texture.h"
#include "audio.h"
#include "font.h"

typedef struct Resources Resources;

typedef enum ResourceState {
	RS_GfxLoaded = 1,
	RS_SfxLoaded = 2
} ResourceState;

enum {
	SNDSRC_COUNT = 35
};

struct Resources {
	ResourceState state;

	Texture *textures;
	Sound *sounds;

	ALuint sndsrc[SNDSRC_COUNT];

};

extern Resources resources;

void load_resources(void);
void free_resources(void);
#endif