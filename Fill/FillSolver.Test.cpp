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

// --------------
bool FillSolver_Test::Partition_Test::full()
{
	Partition p;

	// Add some new subPartitions to p

	return false;
}

bool FillSolver_Test::Partition_Test::addSubPartitions()
{
	Partition p;

	// Make sub partitions 0, 1 and 2 in the same partition
	cout << "add 0, 1 and 2 to the same partition" << endl;
	p.addNewSubPartition(0, 0);
	p.showPartitions();
	cout << endl;

	p.addNewSubPartition(1, 0);
	p.showPartitions();
	cout << endl;

	p.addNewSubPartition(2, 0);
	p.showPartitions();
	cout << endl;

	// Make sub partitions 3, 4, 5 and 6 in the samep partitions
	cout << "add 3, 4, 5 and 6 to the same partition" << endl;
	p.addNewSubPartition(3, 3);
	p.showPartitions();
	cout << endl;

	p.addNewSubPartition(4, 3);
	p.showPartitions();
	cout << endl;

	p.addNewSubPartition(5, 4);
	p.showPartitions();
	cout << endl;

	p.addNewSubPartition(6, 3);
	p.showPartitions();
	cout << endl;

	// Make sub partitions 7 by itself
	cout << "add 7 to its own partition" << endl;
	p.addNewSubPartition(7, 7);
	p.showPartitions();
	cout << endl;

	// Make sub partitions 8 part of 0, 1 and 2s
	cout << "add 8 to 0, 1 and 2s partition" << endl;
	p.addNewSubPartition(8, 0);
	p.showPartitions();
	cout << endl;

	return false;
}

bool FillSolver_Test::Partition_Test::mergePartitions()
{
	Partition p;

	p.addNewSubPartition(0, 0);
	p.addNewSubPartition(1, 0);
	p.addNewSubPartition(2, 0);
	p.addNewSubPartition(3, 3);
	p.addNewSubPartition(4, 3);
	p.addNewSubPartition(5, 4);
	p.addNewSubPartition(6, 3);
	p.addNewSubPartition(7, 7);
	p.addNewSubPartition(8, 0);
	p.addNewSubPartition(9, 7);
	p.addNewSubPartition(10, 7);

	p.showPartitions();
	cout << endl;

	// Merge partitions for sub partitions 0 and 10
	p.mergePartitions(0, 10);
	p.showPartitions();
	cout << endl;

	return false;
}

bool FillSolver_Test::Partition_Test::getNPartitions()
{
	Partition p;

	p.addNewSubPartition(0, 0);
	p.addNewSubPartition(1, 0);
	p.addNewSubPartition(2, 0);
	p.addNewSubPartition(3, 3);
	p.addNewSubPartition(4, 3);
	p.addNewSubPartition(5, 4);
	p.addNewSubPartition(6, 3);
	p.addNewSubPartition(7, 7);
	p.addNewSubPartition(8, 0);
	p.addNewSubPartition(9, 7);
	p.addNewSubPartition(10, 7);

	p.showPartitions();

	cout << "There are " << p.getNPartitions() << " partitions" << endl;

	return false;
}

bool FillSolver_Test::Partition_Test::getNSubPartitions()
{
	Partition p;

	p.addNewSubPartition(0, 0);
	p.addNewSubPartition(1, 0);
	p.addNewSubPartition(2, 0);
	p.addNewSubPartition(3, 3);
	p.addNewSubPartition(4, 3);
	p.addNewSubPartition(5, 4);
	p.addNewSubPartition(6, 3);
	p.addNewSubPartition(7, 7);
	p.addNewSubPartition(8, 0);
	p.addNewSubPartition(9, 7);
	p.addNewSubPartition(10, 7);

	p.showPartitions();

	cout << "There are " << p.getNSubPartitions() << " sub partitions" << endl;

	return false;
}
