#include "FillSolver.h"

FillSolver::FillSolver(const FillBoard & board, const FillPath & path) :
	FillGame(board, path) {}

FillSolver::FillSolver(const FillBoard && board, const FillPath && path) :
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
	// 'u' - up
	// 'd' - down
	// 'r' - right
	// 'l' - left
	// 'b' - back
	stack<char> fringe;
	if (isMoveUpValid()) {
		fringe.push('u');
	}
	if (isMoveDownValid()) {
		fringe.push('d');
	}
	if (isMoveRightValid()) {
		fringe.push('r');
	}
	if (isMoveLeftValid()) {
		fringe.push('l');
	}

	while (!fringe.empty()) {
		//print();
		//system("pause");

		char node = fringe.top();
		fringe.pop();

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

		if (path.size() == 25) {
			print();
			system("pause");
		}
		if (path.size() > 25) {
			cout << "\t\t-------" << endl;
		}
		if (board.isSolved()) {
			cout << "Solved" << endl;
			print();
			system("pause");
			break;
		}

		if (isMoveBackValid()) {
			fringe.push('b');
		}
		if (isMoveUpValid()) {
			fringe.push('u');
		}
		if (isMoveDownValid()) {
			fringe.push('d');
		}
		if (isMoveRightValid()) {
			fringe.push('r');
		}
		if (isMoveLeftValid()) {
			fringe.push('l');
		}
	}

	cout << "Loop broken" << endl;
	print();
}
