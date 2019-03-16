#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <Windows.h>

#include "FillPath.h"

#include "E:\Documents\Programming\C++\ASCII\ASCII\ASCII.h"

using namespace std;

class FillBoard
{
private:
	const char	BLACK = 0;
	const char	BLUE = 1;
	const char	GREEN = 2;
	const char	CYAN = 3;
	const char	RED = 4;
	const char	MAGENTA = 5;
	const char	BROWN = 6;
	const char	LIGHTGREY = 7;
	const char	DARKGREY = 8;
	const char	LIGHTBLUE = 9;
	const char	LIGHTGREEN = 10;
	const char	LIGHTCYAN = 11;
	const char	LIGHTRED = 12;
	const char	LIGHTMAGENTA = 13;
	const char	YELLOW = 14;
	const char	WHITE = 15;
	const char	BLINK = 128;

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
	void setColor(HANDLE console, uint8_t color) const;
	bool getColor(uint8_t & color) const;

protected:
	vector<vector<Space>> board;
};

