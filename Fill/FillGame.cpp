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

coord_t FillGame::moveUp()
{
	coord_t temp = path.moveUp();

	board.setSpaceAs(temp, (FillBoard::Space) path.getChar_back());

	return temp;
}

coord_t FillGame::moveDown()
{
	coord_t temp = path.moveDown();

	board.setSpaceAs(temp, (FillBoard::Space) path.getChar_back());

	return temp;
}

coord_t FillGame::moveRight()
{
	coord_t temp = path.moveRight();

	board.setSpaceAs(temp, (FillBoard::Space) path.getChar_back());

	return temp;
}

coord_t FillGame::moveLeft()
{
	coord_t temp = path.moveLeft();

	board.setSpaceAs(temp, (FillBoard::Space) path.getChar_back());

	return temp;
}

coord_t FillGame::moveBack()
{
	coord_t temp = path.moveBack();

	board.setSpaceAs(temp, (FillBoard::Space) path.getChar_back());

	return temp;
}

void FillGame::print() const
{
	board.print();
}
