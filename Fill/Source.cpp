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

	///FillSolver_Test::full();	// <--- !!! Might me empty
	///FillSolver_Test::_NxM_grid(5, 5);
	///FillSolver_Test::_NxM_grid(6, 6);
	///FillSolver_Test::_NxM_grid(7, 7);
	///FillSolver_Test::_NxM_grid(8, 8);

	FillSolver_Test::deadEnds();
	
	system("pause");
	return 0;
}