#pragma once

#include <iostream>
#include <vector>

#include "constant.hpp"

using namespace std;

typedef int(*Array)[SIZE];

class Puzzle {
public:
	Puzzle();

	Array get_grid();

	int get_value(int, int) const;

	void set_value(int, int, int);

	void print_grid() const;

private:
	int grid[SIZE][SIZE];
};