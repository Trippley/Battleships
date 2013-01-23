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

#include "resources.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "building.h"
#include "config.h"

Resources resources;

void recurse_dir(char *path) {
	DIR *dir = opendir(path);
	if(dir == NULL) {
		printf("Can't open directory '%s'", path);
		return -1;
	}
	
	struct dirent *dp;

	while((dp = readdir(dir)) != NULL) {
		char *buffer = malloc(strlen(path) + strlen(dp->d_name)+2);
		strcpy(buffer, path);
		strcat(buffer, "/");
		strcat(buffer, dp->d_name);

		struct stat statbuf;
		stat(buffer, &statbuf);

		if(S_ISDIR(statbuf.st_mode) && dp->d_name[0] != '.') {
			recurse_dir(buffer);
		} else if(strcmp(dp->d_name + strlen(dp->d_name)-4, ".png") == 0) {
				load_texture(buffer);			
		} else if(strcmp(dp->d_name + strlen(dp->d_name)-4, ".wav") == 0) {
			load_sound(buffer);

		free(buffer);
	}

	closedir(dir);
}

void load_resources(void) {
	printf("load_resources():\n");

	char *path = malloc(strlen(get_prefix())+32);

	if(!(resources.state & RS_GfxLoaded)) {
		printf("- textures:\n");
		strcpy(path, get_prefix());
		strcat(path, "gfx");
		recurse_dir(path);

		resources.state |= RS_GfxLoaded;
	}

	if(!tconfig.intval[NO_AUDIO] && !(resources.state & RS_SfxLoaded)) {
		printf("- sounds:\n");

		alGenSources(SNDSRC_COUNT, resources.sndsrc);
		strcpy(path, get_prefix());
		strcat(path, "sfx");
		recurse_dir(path);

		resources.state |= RS_SfxLoaded;
	}

	if(!(resources.state & RS_ModelsLoaded)) {
		printf("- models:\n");
		strcpy(path, get_prefix());
		strcat(path, "models");
		recurse_dir(path);

		resources.state |= RS_ModelsLoaded;
	}	
}

void free_resources(void) {	
	if(resources.state & RS_SfxLoaded) {
		printf("-- freeing sounds\n");
		delete_sounds();
		printf("-- alutExit()\n");
		alutExit();
	}

	printf("-- freeing textures\n");
	delete_textures();
}

void draw_loading_screen(void) {
	const char *prefix = get_prefix();
	char *buffer = malloc(strlen(prefix)+16);
	Texture *texture;

	strcpy(buffer, prefix);
	strcat(buffer, "gfx/loading.png");

	set_ortho();

	texture = load_texture(buffer);

	draw_texture_p(SCREEN_W/2,SCREEN_H/2, texture);
	SDL_GL_SwapBuffers();
}