

#include <SDL/SDL.h>
#include <sys/stat.h>

#include "universal.h"
#include "gfx.h"
#include "openglfunctions.h"

void gl_init(void) {
		load_opengl_functions();
		check_opengl_extensions();
		
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
		
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		
		glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) { // I don't know for what yet...
		
		printf("- Battleships is initializing:\n");
		
		if(SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("During SDL_Init an Error occured: %s", SDL_GetError());
			return -1;
		}
		
		printf("-- SDL_Init complete\n");
		
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		
		gfx_init();
		
		printf("-- GFX_Init complete\n");
		
		gl_init();
		
		print("-- OpenGL_Init complete\n");
		
		init_universal();
		
		printf("-- Game Loaded\n\n");
		
		printf("Init complete!\n");
		
		atexit(battleships_shutdown);
		
		printf("- Loading Menu...\n");
		
		MenuContent menu;
		
		create_mainmenu(&menu);
		
		printf("-- Loading complete\n");
		
		loop_mainmenu(&menu);
		
		return 0;		
}
		
		
void battleships_shutdown(void) {
		printf("\n\nBattleships is shutting down:\n\n);
		
		save_config(FILE_CONFIG);
		printf("Configfile saved.\n");
		
		free_resources();
		gfx_shutdown();
		
		SDL_Quit();
		
		printf("Have a good time. Bye.\n");
		
}
		
		