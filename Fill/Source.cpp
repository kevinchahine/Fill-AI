#include <iostream>
#include <iomanip>

#include "FillBoard.h"
#include "FillGame.h"
#include "FillPath.h"

#include "UserInterface.h"

#include "FillBoard.Test.h"
#include "FillPath.Test.h"
#include "FillGame.Test.h"

using namespace std;

int main(int argc, char ** argv)
{
	///FillBoard_Test::init();
	///FillPath_Test::full();
	///FillGame_Test::full();
	
	FillGame game(FillBoard(10, 10), FillPath(coord_t(3, 3), 100));

	UserInterface interface;

	interface.setCurrentGamePtr(&game);

	while (interface.simpleUpdate()) {

	}

	system("pause");
	return 0;
}