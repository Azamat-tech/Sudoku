#pragma once

#include <iostream>
#include <memory>

#include "parser.hpp"
#include "generator.hpp"
#include "level.hpp"

using namespace std;

class Sudoku {
public:
	Sudoku();

	int play();

private:
	unique_ptr<Parser> parser;
	unique_ptr<Generator> generator;
	Level level = Level::EASY;
};