#include "../include/sudoku.hpp"

Sudoku::Sudoku() {
	// instantiating the grid of cells
	for (int i = 0; i < SIZE; i++)
	{
		// construct a vector of ints with the given default value
		vector<Cell> v;
		for (int j = 0; j < SIZE; j++) {
			v.push_back(Cell());
		}

		// push back above one-dimensional vector
		grid.push_back(v);
	}

	// parser = make_unique<Parser>();
	generator = make_unique<Generator>();
	// view = make_unique<View>();
}

void Sudoku::print_grid() const {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
}


void Sudoku::Sudoku::create_interface_layout()
{
	// Define thick and thin borders
	const int thinBorder = 2;
	const int thickBorder = thinBorder + 6;

	/*----------------------------------------Display Stopwatch------------------------------------------*/
	// Treat stopwatch as a button that can't be clicked
	int buttonStartRow = 0;
	int buttonWidth = mGridWidth - 2 * thickBorder;
	// mWindowHeight = buttonHeight + 6 * thinBorder + 6 * thickBorder (rearange this equation)
	int buttonHeight = (HEIGHT - 6 * thinBorder - 6 * thickBorder) / 11;

	buttonStartRow += thickBorder;
	int buttonStartCol = 0;
	buttonStartCol += thickBorder;
	// Set button position and dimensions
	SDL_Rect buttonRect = { buttonStartCol, buttonStartRow, buttonWidth, buttonHeight };

	/*----------------------------------Create buttons for each cell-------------------------------------*/
	// Define cell button dimensions
	// mGridWidth = 6 * thinBorder + 4 * thickBorder + 9 * buttonWidth (rearrange this equation)
	buttonWidth = (mGridWidth - 6 * thinBorder - 4 * thickBorder) / SIZE;

	// Carry on from previous starting row
	buttonStartRow += buttonHeight;

	// Set cell button position and dimensions
	for (int gridRow = 0; gridRow < SIZE; gridRow++)
	{
		// Add to starting row
		if (gridRow == 0) buttonStartRow += thickBorder;
		else if (gridRow % 3 == 0) buttonStartRow += buttonHeight + thickBorder;
		else buttonStartRow += buttonHeight + thinBorder;

		// Reset starting column
		int buttonStartCol = 0;

		for (int gridCol = 0; gridCol < SIZE; gridCol++)
		{
			// Add to starting column
			if (gridCol == 0) buttonStartCol += thickBorder;
			else if (gridCol % 3 == 0) buttonStartCol += buttonWidth + thickBorder;
			else buttonStartCol += buttonWidth + thinBorder;

			// Set button position and dimensions
			SDL_Rect buttonRect = { buttonStartCol, buttonStartRow, buttonWidth, buttonHeight };
			grid[gridRow][gridCol].set_button_rect(buttonRect);

		}
	}

	/*----------------------------------Create check, and new buttons-------------------------------------*/
	const int numberOfOtherButtons = 2;
	mCheckButton.setTexture(mTextureCache[10]);
	mNewButton.setTexture(mTextureCache[11]);
	Button* otherButtons[numberOfOtherButtons] = { &mCheckButton, &mNewButton };

	// Redefine button width
	// mGridWidth = 3 * thickBorder + 9 * numberOfOtherButtons (rearrange this equation)
	buttonWidth = (mGridWidth - 3 * thickBorder) / numberOfOtherButtons;

	// Carry on from previous starting row
	buttonStartRow += buttonHeight + thickBorder;

	// Reset starting column
	int borderWidthTotal = 0;

	// Set check, solve, and new buttons (last row)
	for (int button = 0; button < numberOfOtherButtons; button++) // colBlock is every 3 columns of cells
	{
		// Add border width to total
		if (button == 0) borderWidthTotal += thickBorder;
		else borderWidthTotal += thickBorder;
		int buttonStartCol = button * buttonWidth + borderWidthTotal;

		// Set button position and dimensions
		SDL_Rect buttonRect = { buttonStartCol, buttonStartRow, buttonWidth, buttonHeight };
		otherButtons[button]->setButtonRect(buttonRect);
	}
}


int Sudoku::play()
{
	// generator->generate(level, grid);
	// print_grid();


	create_interface_layout();

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
}


// Problem: Getting the SDL window when running

/*
	Sudoku functionalities 
	1) GUI
	2) Generate Unsolved Sudoku puzzles (instead of reading from txt) 
	3) Save/Load (professor)
	4) Select complexity (Easy/Middle/Hard)
	5) SOLVE btn - solves the puzzle
	6) Get Hint for particular square 
	7) Next puzzle
*/

