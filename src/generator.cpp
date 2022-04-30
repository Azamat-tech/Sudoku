#include "../include/generator.hpp"
#include "../include/constant.hpp"

Generator::Generator()
{
	srand((unsigned int)time(NULL));
	solved = make_unique<Puzzle>();
	unsolved = make_unique<Puzzle>();
}

int Generator::randomNumber(int n) {
	return rand() % n + 1;
}

// checks if the random number is inside the block
bool Generator::safe_block(int row, int col, int rnd_num) const
{
	auto m = solved->get_grid();

	for (int i = 0; i < SQN; i++) {
		for (int j = 0; j < SQN; j++) {
			if (m[row + i][col + j] == rnd_num) {
				return false;
			}
		}
	}
	return true;
}


int Generator::get_block_value(int row, int col)
{
	int rnd_num = randomNumber(SIZE);

	while (!safe_block(row, col, rnd_num)) {
		rnd_num = randomNumber(SIZE);
	}

	return rnd_num;
}


// fill diagonal square
void Generator::fill_square(int row, int col)
{
	for (int i = 0; i < SQN; i++)
	{
		for (int j = 0; j < SQN; j++)
		{
			int value = get_block_value(row, col);
			solved->set_value(row + i, col + j, value);
		}
	}
}

bool Generator::safe_row(int i, int val) const
{
	auto m = solved->get_grid();

	for (int j = 0; j < SIZE; j++) {
		if (m[i][j] == val) {
			return false;
		}
	}
	return true;
}

bool Generator::safe_col(int j, int val) const
{
	auto m = solved->get_grid();

	for (int i = 0; i < SIZE; i++) {
		if (m[i][j] == val) {
			return false;
		}
	}
	return true;
}

bool Generator::safe(int row, int col, int val) const
{
	return safe_row(row, val) && safe_col(col, val) && 
			safe_block(row - row % SQN, col - col % SQN, val);
}

bool Generator::fill_remaining(int row, int col)
{
	// if every col in the row is filled but row is not at the end
	// we want to move to the next row
	if (col >= SIZE && row < SIZE - 1) {
		col = 0;
		row += 1;
	}

	if (row >= SIZE && col >= SIZE) {
		return true;
	}

	if (row < SQN)
	{
		if (col < SQN) {
			col = SQN;
		}
	}
	else if (row < SIZE - SQN)
	{
		if (col == (row / SQN) * SQN)
			col += SQN;
	}
	else {
		if (col == SIZE - SQN)
		{
			row += 1;
			col = 0;
			if (row >= SIZE)
				return true;
		}
	}


	for (int val = 1; val <= 9; val++) {
		if (safe(row, col, val)) {
			solved->set_value(row, col, val);

			if (fill_remaining(row, col + 1)) {
				return true;
			}
			solved->set_value(row, col, 0);
		}
	}
	return false;
}

void Generator::generate_puzzle() 
{
	auto grid = solved->get_grid();
	// fill diagonal squares
	for (int i = 0; i < SIZE; i = i + SQN)
		// for diagonal box, start coordinates->i==j
		fill_square(i, i);

	fill_remaining(0, SQN);
}

void Generator::copy_puzzle() 
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			unsolved->set_value(i, j, solved->get_value(i, j));
		}
	}
}

void Generator::provide_hints(int n) 
{
	copy_puzzle();

	int hints = n;
	auto grid = unsolved->get_grid();

	while (hints > 0) {
		int random_cell = randomNumber(SIZE * SIZE) - 1;

		int row = random_cell / SIZE; // floor
		int col = random_cell % SIZE;

		// not empty
		if (grid[row][col] != 0) {
			grid[row][col] = 0;
			hints-=1;
		}
	}
}

unique_ptr<Puzzle> Generator::generate(Level level)
{
	generate_puzzle();

	switch (level) {
		case (Level::EASY):
			provide_hints(FOR_EASY);
			break;
		case (Level::MEDIUM):
			provide_hints(FOR_MEDIUM);
			break;
		case (Level::HARD):
			provide_hints(FOR_HARD);
			break;
	}

	return move(unsolved);
}

unique_ptr<Puzzle> Generator::get_solved()
{
	return move(solved);
}