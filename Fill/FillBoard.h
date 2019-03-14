#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

#include "FillPath.h"

#include "E:\Documents\Programming\C++\ASCII\ASCII\ASCII.h"

using namespace std;

class FillBoard
{
public:
	// Data Type of each space in the board
	enum Space : uint8_t {
		Empty = 0xB0, // ' ',
		Obstacle = 0xB1,
		Vertical = 0xB3,
		Horizontal = 0xC4,
		UpRight = 0xC0,
		DownRight = 0xDA,
		UpLeft = 0xD9,
		DownLeft = 0xBF,
		Dot = 0xF9,
	};
	
	FillBoard(size_t nRows = 5, size_t nCols = 5);
	FillBoard(const vector<vector<Space>> & board);
	FillBoard(const FillBoard & fillBoard);
	~FillBoard();

	// Sets a space on the board to one of a set of possible values
	// See FillBoard::Space
	void setSpaceAs(coord_t coord, Space val);
	void resize(size_t nRows, size_t nCols);

	Space getSpace(coord_t coord) const;
	size_t getNRows() const;
	size_t getNCols() const;

	bool isSolved() const;

	void print(size_t indent = 0) const;

protected:
	vector<vector<Space>> board;
};

