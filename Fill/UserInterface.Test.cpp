#include "UserInterface.Test.h"

void UserInterface_Test::full()
{
	FillGame game(FillBoard(6, 6), FillRoute(coord_t(0, 0), 100));

	UserInterface interfacee;

	interfacee.setCurrentGamePtr(&game);

	while (interfacee.simpleUpdate() == 1) {

	}
}
