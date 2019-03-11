#pragma once

#include "FillBoard.h"
#include "FillPath.h"

using namespace std;

class FillGame
{
public:
	FillGame(const FillBoard & board, const FillPath & path);
	FillGame(const FillBoard && board, const FillPath && path);
	FillGame(const FillGame & fillGame);
	~FillGame();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	coord_t moveBack();

	void print() const;

protected:
	FillBoard board;
	FillPath path;
};

