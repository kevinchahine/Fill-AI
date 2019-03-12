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
		
	board.setSpaceAs(path.getCoordinate(path.size() - 2), (FillBoard::Space) path.getChar(path.size() - 2));
	
	return temp;
}

coord_t FillGame::moveDown()
{
	coord_t temp = path.moveDown();

	board.setSpaceAs(temp, (FillBoard::Space) path.getChar_back());
	board.setSpaceAs(path.getCoordinate(path.size() - 2), (FillBoard::Space) path.getChar(path.size() - 2));

	return temp;
}

coord_t FillGame::moveRight()
{
	coord_t temp = path.moveRight();

	board.setSpaceAs(temp, (FillBoard::Space) path.getChar_back());
	board.setSpaceAs(path.getCoordinate(path.size() - 2), (FillBoard::Space) path.getChar(path.size() - 2));

	return temp;
}

coord_t FillGame::moveLeft()
{
	coord_t temp = path.moveLeft();

	board.setSpaceAs(temp, (FillBoard::Space) path.getChar_back());
	board.setSpaceAs(path.getCoordinate(path.size() - 2), (FillBoard::Space) path.getChar(path.size() - 2));

	return temp;
}

bool FillGame::isMoveUpValid() const
{
	return false;
}

bool FillGame::isMoveDownValid() const
{
	return false;
}

bool FillGame::isMoveRightValid() const
{
	return false;
}

bool FillGame::isMoveLeftValid() const
{
	return false;
}

bool FillGame::isMoveBackValid() const
{
	return false;
}

coord_t FillGame::moveBack()
{
	coord_t temp = path.moveBack();

	board.setSpaceAs(temp, (FillBoard::Space) path.getChar_back());
	
	return temp;
}

coord_t FillGame::moveUp_Fast()
{
	return coord_t();
}

coord_t FillGame::moveDown_Fast()
{
	return coord_t();
}

coord_t FillGame::moveRight_Fast()
{
	return coord_t();
}

coord_t FillGame::moveLeft_Fast()
{
	return coord_t();
}

coord_t FillGame::moveBack_Fast()
{
	return coord_t();
}

void FillGame::print() const
{
	board.print();
}

