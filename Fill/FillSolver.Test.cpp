#include "FillSolver.Test.h"

void FillSolver_Test::full()
{
	FillSolver solver(FillBoard(5, 5), FillRoute(coord_t(2, 2), 25));

	solver.solve();
}
