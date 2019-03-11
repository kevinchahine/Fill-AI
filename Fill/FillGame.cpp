#include "FillGame.h"

FillGame::FillGame(const FillBoard & board, const FillPath & path) :
	board(board),
	path(path)
{
}

FillGame::FillGame(const FillBoard && board, const FillPath && path) :
	board(board),
	path(path)
{
}

FillGame::FillGame(const FillGame & fillGame) :
	board(fillGame.board),
	path(fillGame.path)
{
}

FillGame::~FillGame() {}

void FillGame::moveUp()
{
	path.moveUp();
}

void FillGame::moveDown()
{
}

void FillGame::moveRight()
{
}

void FillGame::moveLeft()
{
}

coord_t FillGame::moveBack()
{
	return coord_t();
}

void FillGame::print() const
{
	board.print();
}
