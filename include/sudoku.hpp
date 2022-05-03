#pragma once

#include <SDL.h>
#include <iostream>
#include <memory>

#include "parser.hpp"
#include "generator.hpp"
#include "level.hpp"
#include "view.hpp"

using namespace std;

class Sudoku {
public:
	Sudoku();

	int play();

private:
	unique_ptr<Parser> parser;
	unique_ptr<Generator> generator;
	unique_ptr<View> view;

	Level level = Level::EASY;
};