#include "../include/puzzle.hpp"

Puzzle::Puzzle()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			grid[i][j] = 0;
		}
	}
}

Array Puzzle::get_grid()
{
	return grid;
}

int Puzzle::get_value(int row, int col) const 
{
	return grid[row][col];
}

void Puzzle::set_value(int row, int col, int val) {
	grid[row][col] = val;
}

void Puzzle::print_grid() const
{
	for (auto& row : grid) {
		for (auto& elem : row) {
			cout << elem << " ";
		}
		cout << endl;
	}
}
