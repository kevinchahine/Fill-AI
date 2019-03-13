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
	if (isMoveUpValid()) {
		return moveUp_Fast();
	}
	else {
		return coord_t();
	}
}

coord_t FillGame::moveDown() {
	if (isMoveDownValid()) {
		return moveDown_Fast();
	}
	else {
		return coord_t();
	}
}

coord_t FillGame::moveRight() {
	if (isMoveRightValid()) {
		return moveRight_Fast();
	}
	else {
		return coord_t();
	}
}

coord_t FillGame::moveLeft() {
	if (isMoveLeftValid()) {
		return moveLeft_Fast();
	}
	else {
		return coord_t();
	}
}

coord_t FillGame::moveBack() {
	if (isMoveBackValid()) {
		return moveBack_Fast();
	}
	else {
		return coord_t();
	}
}

bool FillGame::isMoveUpValid() const
{
	// 1.) Check for out of bounds
	coord_t head = path.getCoordinate_back();
	
	if (head.first == 0) {
		return false;
	}

	// 2.) Check for Collision with body or object on board
	head.first--;

	if (board.getSpace(head) != FillBoard::Empty) {
		return false;
	}

	return true;
}

bool FillGame::isMoveDownValid() const
{
	// 1.) Check for out of bounds
	coord_t head = path.getCoordinate_back();

	if (head.first == board.getNRows() - 1) {
		return false;
	}

	// 2.) Check for Collision with body or object on board
	head.first++;

	if (board.getSpace(head) != FillBoard::Empty) {
		return false;
	}

	return true;
}

bool FillGame::isMoveRightValid() const
{
	// 1.) Check for out of bounds
	coord_t head = path.getCoordinate_back();

	if (head.second == board.getNCols() - 1) {
		return false;
	}

	// 2.) Check for Collision with body or object on board
	head.second++;

	if (board.getSpace(head) != FillBoard::Empty) {
		return false;
	}

	return true;

}

bool FillGame::isMoveLeftValid() const
{
	// 1.) Check for out of bounds
	coord_t head = path.getCoordinate_back();

	if (head.second == 0) {
		return false;
	}

	// 2.) Check for Collision with body or object on board
	head.second--;

	if (board.getSpace(head) != FillBoard::Empty) {
		return false;
	}

	return true;

}

bool FillGame::isMoveBackValid() const
{
	return path.size() > 1;
}

coord_t FillGame::moveUp_Fast()
{
	coord_t temp = path.moveUp();

	board.setSpaceAs(temp, FillBoard::Dot);

	return temp;
}

coord_t FillGame::moveDown_Fast()
{
	coord_t temp = path.moveDown();

	board.setSpaceAs(temp, FillBoard::Dot);

	return temp;
}

coord_t FillGame::moveRight_Fast()
{
	coord_t temp = path.moveRight();

	board.setSpaceAs(temp, FillBoard::Dot);

	return temp;
}

coord_t FillGame::moveLeft_Fast()
{
	coord_t temp = path.moveLeft();

	board.setSpaceAs(temp, FillBoard::Dot);

	return temp;
}

coord_t FillGame::moveBack_Fast()
{
	coord_t temp = path.moveBack();

	board.setSpaceAs(temp, (FillBoard::Space) path.getChar_back());

	return temp;
}

void FillGame::print() const
{
	board.print();
}

