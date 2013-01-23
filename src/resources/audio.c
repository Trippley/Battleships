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

#include "audio.h"
#include "resources.h"
#include "universal.h"
#include "listhandling.h"

Sound *load_sound(char *filename) {
	ALuint sound;
	if(!(sound = alutCreateBufferFromFile(filename))) {
		printf("load_sound():\n!- cannot load '%s': %s", filename, alutGetErrorString(alutGetError()));
		return -1;
	}

	Sound *snd = create_element((void **)&resources.sounds, sizeof(Sound));

	snd->alsnd = sound;
	snd->lastplayframe = 0;

	char *beg = strstr(filename, "sfx/") + 4;
	char *end = strrchr(filename, '.');

	snd->name = malloc(end - beg + 1);
	memset(snd->name, 0, end-beg + 1);
	strncpy(snd->name, beg, end-beg);

	printf("-- loaded '%s' as '%s'\n", filename, snd->name);

	return snd;
}

Sound *get_snd(char *name) {
	Sound *s, *res = NULL;
	for(s = resources.sounds; s; s = s->next) {
		if(strcmp(s->name, name) == 0)
			res = s;
	}

	if(res == NULL)
		errx(-1,"get_snd():\n!- cannot load sound '%s'", name);

	return res;
}

void play_sound(char *name) {
	if(!tconfig.intval[NO_AUDIO])
		play_sound_p(get_snd(name));
}

void play_sound_p(Sound *snd) {
	if(tconfig.intval[NO_AUDIO] || snd->lastplayframe == global.frames)
		return;

	snd->lastplayframe = global.frames;

	ALuint i,res = -1;
	ALint play;
	for(i = 0; i < SNDSRC_COUNT; i++) {
		alGetSourcei(resources.sndsrc[i],AL_SOURCE_STATE,&play);
		if(play != AL_PLAYING) {
			res = i;
			break;
		}
	}

	if(res != -1) {
		alSourcei(resources.sndsrc[res],AL_BUFFER, snd->alsnd);
		alSourcePlay(resources.sndsrc[res]);
	} else {
		warnx("play_sound_p():\n!- not enough sources");
	}
}

void delete_sound(void **snds, void *snd) {
	free(((Sound *)snd)->name);
	alDeleteBuffers(1, &((Sound *)snd)->alsnd);
	delete_element(snds, snd);
}

void delete_sounds(void) {
	delete_all_elements((void **)&resources.sounds, delete_sound);
}