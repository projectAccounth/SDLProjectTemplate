#include "./include/window.h"
#include "./include/mainHeader.h"

// Definition of the createRenderer() function
SDL_Renderer* createRenderer(SDL_Window *targetWindow) {
	// The SDL_Renderer that will be returned
	return SDL_CreateRenderer(targetWindow, -1, SDL_RENDERER_PRESENTVSYNC);
}

void createWindow(int height, int width, bool isFullScreen, const char* title, SDL_Window* targetWindow, SDL_Renderer* targetRenderer) {
	// Initialize the program
	SDL_Init(SDL_INIT_EVERYTHING);
	// Create a window with the name of the passed argument title,
	// with the width and height of the passed arguments
	// and the window position at the center of the screen
	targetWindow = SDL_CreateWindow(title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height, 0);
	// Checking whether the window was created or not
	if (targetWindow == NULL) {
		std::cout << (stderr, "could not create window: %s\n", SDL_GetError());
		exit(1);
	}
	// Creating the renderer
	targetRenderer = createRenderer(targetWindow);
	// If you want to go to fullscreen mode by default, pass "true" as
	// the argument to isFullScreen
	if (isFullScreen) {
		SDL_SetWindowFullscreen(targetWindow, SDL_WINDOW_FULLSCREEN);
	}
}

void toggleFullScreen(SDL_Window* targetWindow) {
	// Use the bitwise AND to check whether FULLSCREEN is
	// one in the current flags of the window
	bool isFullScreen = SDL_GetWindowFlags(targetWindow) & SDL_WINDOW_FULLSCREEN;
	std::cout << isFullScreen << '\n' << SDL_GetWindowFlags(targetWindow) << "\n";
	// Use the ternary operator (replacing if-else) to toggle fullscreen
	if (isFullScreen == 0) {
		SDL_SetWindowFullscreen(targetWindow, SDL_WINDOW_FULLSCREEN);
		std::cout << SDL_GetError() << '\n';
	}
	else {
		SDL_SetWindowFullscreen(targetWindow, 0);
		std::cout << SDL_GetError() << '\n';
	}
}


// The function responsible for render whatever that is supposed to be rendered
void renderWindow(SDL_Renderer *renderer, Color3 color) {
	// Set a color for the renderer
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	// Clear the renderer
	SDL_RenderClear(renderer);

	// Things that need to be rendered go here

	// Make the renderer present
	SDL_RenderPresent(renderer);
}

void onQuit(SDL_Window *window, SDL_Renderer *renderer) {
	// Destroy window and renderer
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	// Quit all SDL subsystems
	SDL_Quit();
}