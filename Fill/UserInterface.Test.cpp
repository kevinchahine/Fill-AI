#include "UserInterface.Test.h"

void UserInterface_Test::full()
{
	FillGame game(FillBoard(6, 6), A::FillPath(coord_t(0, 0), 100));

	UserInterface interfacee;

	interfacee.setCurrentGamePtr(&game);

	while (interfacee.simpleUpdate() == 1) {

	}
}
