#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class FillBoard
{
public:
	// Data Type of each space in the board
	enum Space : uint8_t {
		Empty = ' ',
		Obstacle = 0xF9,
		Vertical = 0xB3,
		Horizontal = 0xC4,
		UpRight = 0xC0,
		DownRight = 0xDA,
		UpLeft = 0xD9,
		DownLeft = 0xBF,
	};
	
	FillBoard(size_t nRows = 5, size_t nCols = 5);
	FillBoard(const vector<vector<Space>> & board);
	FillBoard(const FillBoard & fillBoard);
	~FillBoard();

	// Sets a space on the board to one of a set of possible values
	// See FillBoard::Space
	void setSpaceAs(size_t row, size_t col, Space val);
	void resize(size_t nRows, size_t nCols);

	Space getSpace(size_t row, size_t col) const;
	size_t getNRows() const;
	size_t getNCols() const;

	bool isSolved() const;

	void print(size_t indent = 0) const;

protected:
	vector<vector<Space>> board;
};

