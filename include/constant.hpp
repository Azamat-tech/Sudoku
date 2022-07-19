#pragma once

using namespace std;

/* puzzle grid dimensions */
const int SIZE = 9;

/* square root for diagonal block division */
const int SQN = 3;

/* domain of every cell */
const int FROM = 1;
const int TO = 9;

/* number of hints */
const int FOR_EASY = 17;
const int FOR_MEDIUM = 33;
const int FOR_HARD = 49;

/* window size */
const int WIDTH = 1000;
const int HEIGHT = 700;

// Define Sudoku grid dimensions
const int mGridHeight = 680;
const int mGridWidth = 680;

/* window title */
inline const char* WINDOW_TITLE = "Sudoku";