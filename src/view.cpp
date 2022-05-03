#include "../include/view.hpp"

void View::CHECKFORERROR(bool error, string msg) {
	if (error) {
		cerr << ("Could not initialize SDL: %s.\n", SDL_GetError());
		exit(1);
	}
}

View::View() {
	cout << "view instantiated" << endl;

	/* initialize sdl */
	CHECKFORERROR(SDL_INIT_VIDEO != 0, SDL_GetError());

	/* initialize window and renderer */
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_RENDERER_PRESENTVSYNC, &_window, &_renderer);
	CHECKFORERROR(_window == NULL, SDL_GetError());
	CHECKFORERROR(_renderer == NULL, SDL_GetError());

	SDL_SetWindowTitle(_window, WINDOW_TITLE);
}