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

bool FillSolver_Test::deadEnds()
{
	FillSolver solver(FillBoard(4, 4), FillRoute(coord_t(0, 0), 16));

	solver.print();

	while (true) {
		char move;
		cout << "Enter a move (u, d, l, r, b)";
		cin >> move;

		switch (move) {
		case 'u':
			solver.moveUp();
			break;
		case 'd':
			solver.moveDown();
			break;
		case 'l':
			solver.moveLeft();
			break;
		case 'r':
			solver.moveRight();
			break;
		case 'b':
			solver.moveBack();
			break;
		default:
			cout << move << " was not accepted try again" << endl;
			continue;
		}

		solver.print();

		cout << "To test this function, set the access modifier"
			<< "of FillSolver::deadEnds() to public" << endl;
		/*cout << (solver.deadEnds() ?
			"Too many dead ends" :
			"Safe number of dead ends") << endl;*/
	}

	return false;
}
