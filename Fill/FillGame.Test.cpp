#include "FillGame.Test.h"

bool FillGame_Test::full()
{
	FillGame game(FillBoard(8, 8), FillPath(coord_t(3, 3), 64));

	///game.print();

	game.moveUp();
	game.moveRight();
	game.moveDown();
	game.moveDown();
	game.moveDown();
	game.moveLeft();
	game.moveLeft();
	game.moveUp();
	game.moveLeft();
	game.moveLeft();
	game.moveUp();
	game.moveLeft();
	game.moveUp();
	game.moveUp();
	game.moveRight();

	game.print();

	return true;
}
