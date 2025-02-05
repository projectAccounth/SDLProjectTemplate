// C++ SDL2 Template for Visual Studio 2022

#include "../include/program.h"

int activeButtonId;
int activeSLFlag = 0;

SDL_Window* mainWindow = NULL;
SDL_Renderer* mainRenderer = NULL;

// window's color, change please
SDL_Color windowColor = {255, 255, 255 ,255};


int main(int argc, char* argv[]) {
	Program program;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	mainWindow = program.createWindow(WINDOW_HEIGHT, WINDOW_WIDTH, 0, "Program");
	mainRenderer = program.createRenderer(mainWindow);

	SDL_SetRenderDrawBlendMode(mainRenderer, SDL_BLENDMODE_BLEND);

	bool isRunning = true;

	while (isRunning) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			isRunning = program.processEvent(e);
		}
		
		SDL_SetRenderDrawColor(mainRenderer, windowColor.r, windowColor.g, windowColor.b, windowColor.a);
		SDL_RenderClear(mainRenderer);

		SDL_RenderPresent(mainRenderer);
	}
	program.onQuit(mainWindow, mainRenderer);

	return 0;
}