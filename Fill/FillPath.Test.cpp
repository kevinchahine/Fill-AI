#include "FillPath.Test.h"

bool FillPath_Test::init()
{
	vector<coord_t> p(16);
	p.push_back(coord_t(5, 6));
	p.push_back(coord_t(5, 7));
	p.push_back(coord_t(4, 7));

	FillPath path(coord_t(4, 4));
	FillPath pathFull(p);
	FillPath pathCopy(path);

	return true;
}

bool FillPath_Test::move()
{
	FillPath path(coord_t(3, 3));

	path.moveDown();
	path.moveRight();
	path.moveDown();
	path.moveLeft();
	path.moveLeft();
	path.moveLeft();
	path.moveUp();

	cout << path.toStream().str() << endl;

	return false;
}

bool FillPath_Test::full()
{
	bool constructor = FillPath_Test::init();

	bool move = FillPath_Test::move();

	return constructor && move;
}
