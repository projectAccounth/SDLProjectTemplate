#include "./include/mainHeader.h"

// We had to use window here because using extern will cause the window to be invalid
void programControls() {
	// Getting keyboardState
	const Uint8* keyState = SDL_GetKeyboardState(nullptr);	
	// If the A key is pressed, log "A" to stdout
	if (keyState[SDL_SCANCODE_A]) {
		std::cout << "A" << '\n';
	}
}

// Definition of the main loop function
bool processEvent() {
	// Declaring a main game event
	SDL_Event event;
	// The boolean we'll need to return
	bool isRunning = true;
	// Polling event
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_WINDOWEVENT_CLOSE: {
				// In case the program is closed manually
				isRunning = false;
				break;
			}
			case SDL_QUIT: {
				// In case SQL_Quit() is called manually
				isRunning = false;
				break;
			}
		}
	}
	// Calling the program controls
	programControls();

	// returning the boolean
	return isRunning;
}

