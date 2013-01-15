

#include <SDL/SDL.h>
#include <sys/stat.h>

#include "universal.h"
#include "gfx.h"
#include "openglfunctions.h"

void gl_init(void) {
		load_opengl_functions();
		check_opengl_extensions_system_compability();
		
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		
		glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) { // I don't know for what yet...
		
		printf("- Battleships is initializing:\n
		
		if(SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("During SDL_Init ocurred an Error: %s, SDL_GetError());
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
		
		printf("-Loading Menu...");
		
		//create main menu
		
		printf("-- Loading complete");
		
		//entermenuloop
		
}
		
		
void battleships_shutdown(void) {
		printf("\n\nBattleships is shutting down:\n\n);
		
		save_config(FILE_CONFIG);
		printf("Configfile saved.");
		
		free_resources();
		gfx_shutdown();
		
		SDL_Quit();
		
		printf(" Have a good time. Bye.\n");
		
}
		
		