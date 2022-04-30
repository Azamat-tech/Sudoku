#include "../include/sudoku.hpp"

Sudoku::Sudoku() {
	cout << "game instantiated" << endl;
	parser = make_unique<Parser>();
	generator = make_unique<Generator>();
}

int Sudoku::play()
{
	generator->generate(Level::EASY);
	return 0;
}

