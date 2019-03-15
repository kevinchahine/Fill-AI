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

void FillBoard::setSpaceAs(coord_t coord, Space val)
{
	board.at(coord.first).at(coord.second) = val;
}

void FillBoard::resize(size_t nRows, size_t nCols)
{
	board.resize(nRows);

	for (auto row : board) {
		row.resize(nCols, Space::Empty);
	}
}

FillBoard::Space FillBoard::getSpace(coord_t coord) const
{
	return board.at(coord.first).at(coord.second);
}

size_t FillBoard::getNRows() const
{
	return board.size();
}

size_t FillBoard::getNCols() const
{
	return board.front().size();
}

bool FillBoard::isSolved() const
{
	// Is every space filled (meaning no empty spaces)?
	for (auto row : board) {
		for (auto val : row) {
			if (val == Space::Empty) {
				return false;
			}
		}
	}

	return true;
}

void FillBoard::print(size_t indent) const
{
	// Remember the fill char (and set the new one at the same time)
	char prevFillCh = cout.fill(ASCII::lines[ASCII::HORIZONTAL_DOUBLE]);
	
	size_t nRows = this->board.size();
	size_t nCols = (nRows > 0 ? this->board[0].size() : 0);

	// Print Top Boarder
	
	cout << setw(indent) << ASCII::lines[ASCII::DOWN_DOUBLE | ASCII::RIGHT_DOUBLE]
		<< setw(nCols + 1)
		<< ASCII::lines[ASCII::DOWN_DOUBLE | ASCII::LEFT_DOUBLE]
		<< endl;
	
	for (size_t r = 0; r < nRows; r++) {
		// Indent
		cout << setw(indent) 
			<< ASCII::lines[ASCII::VERTICAL_DOUBLE];

		for (size_t c = 0; c < nCols; c++) {
			char textColor = WHITE;
			char backColor = (r % 2 == 0 || c % 2 == 0);

			/*SetConsoleTextAttribute(
				GetStdHandle(
					STD_OUTPUT_HANDLE),
				textColor + (backColor << 4));*/
			// the 2nd argument represents the color of the text. 
			// See above for numerical equivalace of colors

			cout << (char)this->board[r][c];
		}
		cout << ASCII::lines[ASCII::VERTICAL_DOUBLE]
			<< endl;
	}

	cout << setfill(ASCII::lines[ASCII::HORIZONTAL_DOUBLE])
		<< setw(indent) 
		<< ASCII::lines[ASCII::UP_DOUBLE | ASCII::RIGHT_DOUBLE]
		<< setw(nCols + 1)
		<< ASCII::lines[ASCII::UP_DOUBLE | ASCII::LEFT_DOUBLE] << endl;
	
	// Restore the previous fill character
	cout.fill(prevFillCh);
}
