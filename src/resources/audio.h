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

#ifndef AUDIO_H
#define AUDIO_H

#include <AL/alut.h>

struct Sound;

typedef struct Sound {
	struct Sound *next;
	struct Sound *prev;

	int lastplayframe;

	ALuint alsnd;
	char *name;
} Sound;

Sound *load_sound(char *filename);
void play_sound(char *name);
void play_sound_p(Sound *snd);

Sound *get_snd(char *name);
void delete_sounds(void);

#endif