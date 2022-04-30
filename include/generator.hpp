#pragma once

#include <time.h>       /* time */
#include <memory>
#include <random>

#include "puzzle.hpp"
#include "constant.hpp"
#include "level.hpp"

class Generator {
public:
	Generator();

	unique_ptr<Puzzle> generate(Level level);
	unique_ptr<Puzzle> get_solved();
private:
	// generator generates the puzzle 
	unique_ptr<Puzzle> solved;
	unique_ptr<Puzzle> unsolved;
	
	void copy_puzzle();
	void generate_puzzle();
	void provide_hints(const int);

	void fill_square(int , int );
	bool fill_remaining(int, int);

	bool safe(int, int, int) const;
	bool safe_row(int, int) const;
	bool safe_col(int, int) const;
	bool safe_block(int , int , int ) const;

	int get_block_value(int , int );

	int randomNumber(int);
};



