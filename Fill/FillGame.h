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

	coord_t moveUp();
	coord_t moveDown();
	coord_t moveRight();
	coord_t moveLeft();
	coord_t moveBack();

	coord_t moveUp_Fast();
	coord_t moveDown_Fast();
	coord_t moveRight_Fast();
	coord_t moveLeft_Fast();
	coord_t moveBack_Fast();

	bool isMoveUpValid() const;
	bool isMoveDownValid() const;
	bool isMoveRightValid() const;
	bool isMoveLeftValid() const;
	bool isMoveBackValid() const;

	void placeObstacle(coord_t location);

	void print();

private:
	void updateLines();

protected:
	FillBoard board;
	FillPath path;
};

