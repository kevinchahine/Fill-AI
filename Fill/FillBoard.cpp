#include "FillBoard.h"

FillBoard::FillBoard(size_t nRows, size_t nCols)
{
	board.resize(nRows);

	for (auto & row : board) {
		// Initialize board with empty spaces
		row.resize(nCols, Space::Empty);
	}
}

FillBoard::FillBoard(const vector<vector<Space>>& board)
{
	// Resize nRows
	const size_t nRows = board.size();
	this->board.resize(nRows);

	// Incase board is jagged (and that is not a 
	// good thing for this class), find longest row
	// and use that as nCols
	size_t nCols = 0;
	for (auto & row : board) {
		if (row.size() > nCols) {
			nCols = row.size();
		}
	}
	
	// Resize nCols and copy elements over
	for (size_t r = 0; r < nRows; r++) {
		this->board[r].resize(nCols);

		// Copy elements
		for (size_t c = 0; c < board.size(); c++) {
			this->board[r][c] = board[r][c];
		}

		// Fill remaining spaces (if any) with Obstacles
		for (size_t c = board.size(); c < nCols; c++) {
			this->board[r][c] = Space::Obstacle;
		}
	}
}

FillBoard::FillBoard(const FillBoard & fillBoard)
{
	const vector<vector<Space>> & board2 = fillBoard.board;

	// What are the dimentions of the board?
	const size_t nRows = board2.size();
	const size_t nCols = (nRows > 0 ? board2[0].size() : 0);

	this->board.resize(nRows);
	
	for (size_t r = 0; r < nRows; r++) {
		this->board[r].resize(nCols);

		for (size_t c = 0; c < nCols; c++) {
			this->board[r][c] = board2[r][c];
		}
	}
}

FillBoard::~FillBoard() {}

void FillBoard::print(size_t indent) const
{
	size_t nRows = this->board.size();
	size_t nCols = (nRows > 0 ? this->board[0].size() : 0);

	for (size_t r = 0; r < nRows; r++) {
		// Indent
		cout << setw(indent) << (char) 0;

		for (size_t c = 0; c < nCols; c++) {
			cout << (char) this->board[r][c];
		}
		cout << endl;
	}
	cout << endl;
}
