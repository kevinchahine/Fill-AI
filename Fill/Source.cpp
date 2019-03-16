#include <iostream>
#include <iomanip>
#include <Windows.h>

#include "FillBoard.h"
#include "FillGame.h"
#include "FillPath.h"

#include "UserInterface.h"

#include "FillBoard.Test.h"
#include "FillGame.Test.h"
#include "FillPath.Test.h"
#include "FillSolver.Test.h"

using namespace std;

int main(int argc, char ** argv)
{
	///FillBoard_Test::init();
	///FillPath_Test::full();
	///FillGame_Test::full();
	///UserInterface_Test::full();

	FillSolver_Test::full();
	
	/*HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 16; i++) {
		uint8_t color = ((i << 4) | 15);

		SetConsoleTextAttribute(console, color);
		cout << "color " << i << endl;
	}*/

	system("pause");
	return 0;
}