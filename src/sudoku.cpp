#include "../include/sudoku.hpp"

Sudoku::Sudoku() {
	cout << "game instantiated" << endl;
	parser = make_unique<Parser>();
	generator = make_unique<Generator>();
	view = make_unique<View>();
}

int Sudoku::play()
{
	SDL_Event event;
	bool game_running = true;

	while (game_running) {
		// register mouse press 
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				game_running = false;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {

			}
			else if (event.type == SDL_KEYDOWN) {

			}
		}
	}
	return 0;

	//generator->generate(Level::EASY);
}

