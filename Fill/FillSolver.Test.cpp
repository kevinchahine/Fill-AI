#include "FillSolver.Test.h"

void FillSolver_Test::full()
{
	
}

void FillSolver_Test::_5x5_grid()
{
	FillSolver solver(FillBoard(5, 5), FillRoute(coord_t(2, 2), 25));

	solver.solve();
}

void FillSolver_Test::_50x50_grid()
{
	FillSolver solver(FillBoard(50, 50), FillRoute(coord_t(2, 2), 50 * 50));

	solver.solve();
}

void FillSolver_Test::_NxM_grid(int n, int m)
{
	FillSolver solver(FillBoard(n, m), FillRoute(coord_t(2, 2), n * m));

	solver.solve();
}
