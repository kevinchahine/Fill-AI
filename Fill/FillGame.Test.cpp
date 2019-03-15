#include "FillGame.Test.h"

bool FillGame_Test::full()
{
	FillGame game(FillBoard(8, 8), A::FillPath(coord_t(3, 3), 64));

	game.placeObstacle(coord_t(2, 3));
	game.placeObstacle(coord_t(3, 4));
	game.placeObstacle(coord_t(5, 3));
	game.placeObstacle(coord_t(4, 1));
	game.placeObstacle(coord_t(0, 0));
	game.placeObstacle(coord_t(7, 7));

	game.print();		
	system("pause");

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
	game.moveUp();
	game.moveUp();
	game.moveUp();
	game.moveRight();
	game.moveRight();
	game.moveRight();
	game.moveRight();
	game.moveRight();
	game.moveDown();
	game.moveDown();
	game.moveDown();
	game.moveDown();
	game.moveDown();
	game.moveDown();
	game.moveDown();
	game.moveDown();
	game.moveDown();
	game.moveDown();
	game.moveDown();

	game.print();

	return true;
}
