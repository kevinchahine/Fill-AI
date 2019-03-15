#include "UserInterface.Test.h"

void UserInterface_Test::full()
{
	FillGame game(FillBoard(6, 6), FillPath(coord_t(0, 0), 100));

	UserInterface interface;

	interface.setCurrentGamePtr(&game);

	while (interface.simpleUpdate() == 1) {

	}
}
