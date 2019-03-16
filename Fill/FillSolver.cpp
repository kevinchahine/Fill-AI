#include "FillSolver.h"

FillSolver::FillSolver(const FillBoard & board, const FillRoute & path) :
	FillGame(board, path) {}

FillSolver::FillSolver(const FillBoard && board, const FillRoute && path) :
	FillGame(board, path) {}

FillSolver::FillSolver(const FillGame & fillGame) :
	FillGame(fillGame) {}

FillSolver::~FillSolver() {}

void FillSolver::solve()
{
	solve1();
}

void FillSolver::solve1()
{
	print();

	// 'u' - up
	// 'd' - down
	// 'r' - right
	// 'l' - left
	// 'b' - back
	vector<char> fringe;
	fringe.reserve(4 * board.getNCols() * board.getNRows());

	if (isMoveUpValid()) {
		fringe.push_back('u');
	}
	if (isMoveDownValid()) {
		fringe.push_back('d');
	}
	if (isMoveRightValid()) {
		fringe.push_back('r');
	}
	if (isMoveLeftValid()) {
		fringe.push_back('l');
	}

	int nSolutions = 0;

	clock_t startTime = clock();

	while (!fringe.empty()) {
		//print();
		//system("pause");

		char node = fringe.back();
		fringe.pop_back();

		switch (node) {
		case 'u':
			moveUp_Fast();
			break;
		case 'd':
			moveDown_Fast();
			break;
		case 'r':
			moveRight_Fast();
			break;
		case 'l':
			moveLeft_Fast();
			break;
		case 'b':
			moveBack_Fast();
			continue;
		default:
			cerr << "default case: "
				<< __FILE__ << " line " << __LINE__
				<< endl;
			system("pause");
			break;
		}

		if (path.size() == board.getNCols() * board.getNRows()) {
			nSolutions++;
			cout << '.';
			if (nSolutions % 30 == 0) {
				cout << '\n';
			}
			if (nSolutions < 3) 
				print();
			//system("pause");
		}
		if (path.size() > board.getNCols() * board.getNRows()) {
			cout << "\t\t-------" << endl;
		}
		/*if (board.isSolved()) {
			cout << "Solved" << endl;
			print();
			system("pause");
			break;
		}*/

		if (isMoveBackValid()) {
			fringe.push_back('b');
		}
		if (isMoveUpValid()) {
			fringe.push_back('u');
		}
		if (isMoveDownValid()) {
			fringe.push_back('d');
		}
		if (isMoveRightValid()) {
			fringe.push_back('r');
		}
		if (isMoveLeftValid()) {
			fringe.push_back('l');
		}
	}

	clock_t endTime = clock();

	cout << "# solutions found = " << nSolutions << endl;
	cout << "time elapsed = " << (endTime - startTime) / 1000.0f << "mSec" << endl;
	cout << "Loop broken" << endl;

	print();
}
