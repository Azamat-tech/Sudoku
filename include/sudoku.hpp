#pragma once

#include <SDL.h>
#include <iostream>
#include <memory>
#include <vector>

#include "generator.hpp"
#include "level.hpp"
#include "view.hpp"
#include "cell.hpp"
#include "button.hpp"

using namespace std;

class Sudoku {
public:
	Sudoku();

	int play();

private:
	// defaut level
	Level level = Level::EASY;
	// sudoku grid
	vector<vector<Cell>> grid;
	// buttons: Check, Next, Hint
	
	// unique_ptr<Parser> parser;
	unique_ptr<Generator> generator;
	unique_ptr<View> view;


	void print_grid() const;
	void create_interface_layout();
};

