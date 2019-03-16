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
	///solve1();
	solve2();
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
			if (nSolutions % 60 == 0) {
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

void FillSolver::solve2()
{
	print();

	const size_t nCells = board.getNCols() * board.getNRows();

	// 'u' - up
	// 'd' - down
	// 'r' - right
	// 'l' - left
	// 'b' - back
	vector<char> fringe;
	fringe.reserve(4 * nCells);

	// 1.) Initialize fringe
	if (isMoveUpValid() && !forwardChecking('u')) {
		fringe.push_back('u');
	}
	if (isMoveDownValid() && !forwardChecking('d')) {
		fringe.push_back('d');
	}
	if (isMoveRightValid() && !forwardChecking('r')) {
		fringe.push_back('r');
	}
	if (isMoveLeftValid() && !forwardChecking('l')) {
		fringe.push_back('l');
	}

	clock_t startTime = clock();
	int nSolutionsFound = 0;

	// 2.) Search
	while (!fringe.empty()) {
		char node = fringe.back();
		fringe.pop_back();

		switch (node) {
		case 'u':	moveUp_Fast();		break;
		case 'd':	moveDown_Fast();	break;
		case 'r':	moveRight_Fast();	break;
		case 'l':	moveLeft_Fast();	break;
		case 'b':	moveBack_Fast();	continue;
		default:
			cerr << "default case: "
				<< __FILE__ << " line " << __LINE__
				<< endl;
			system("pause");
			break;
		}

		// 2-2.) Test for a solution
		if (path.size() >= nCells) {
			nSolutionsFound++;
			//cout << '.';
			/*if (nSolutionsFound % 60 == 0) {
				cout << endl;
			}*/
			
			///print();
		}
	
		// 2-3.) Push next possile moves to fringe
		if (isMoveBackValid()) {
			fringe.push_back('b');
		}
		if (isMoveUpValid() && !forwardChecking('u')) {
			fringe.push_back('u');
		}
		if (isMoveDownValid() && !forwardChecking('d')) {
			fringe.push_back('d');
		}
		if (isMoveRightValid() && !forwardChecking('r')) {
			fringe.push_back('r');
		}
		if (isMoveLeftValid() && !forwardChecking('l')) {
			fringe.push_back('l');
		}
	} // end while (...

	clock_t endTime = clock();

	cout << nSolutionsFound << " solutions found" << endl
		<< "in " << (endTime - startTime) << " mSec" << endl;
}

bool FillSolver::forwardChecking(char move)
{
	switch (move) {
	case 'u':
		moveUp();
		break;
	case 'd':
		moveDown();
		break;
	case 'r':
		moveRight();
		break;
	case 'l':
		moveLeft();
		break;
	case 'b':
		cerr << "Error:" << __FILE__ << " line " << __LINE__ << endl
			<< "Should not test moveing back in forward checking" << endl;
		return false;
	default:
		cerr << "Error:" << __FILE__ << " line " << __LINE__ << endl;
	}

	bool fc = deadEnds();

	moveBack();

	return fc;
}

bool FillSolver::deadEnds() const
{
	uint8_t nDeadEnds = 0;
	const size_t N_ROWS = board.getNRows();
	const size_t N_COLS = board.getNCols();
	const coord_t HEAD_POS = path.getCoordinate_back();

	for (int r = 0; r < N_ROWS; r++) {
		for (int c = 0; c < N_COLS; c++) {
			// Only apply dead ends check to empty spaces.
			// a space has to be empty to be counted as 
			// a dead end obviously
			if (board.getSpace(coord_t(r, c)) == FillBoard::Empty) {
				uint8_t emptys = 0;

				coord_t cellPos;

				// !!! Do Bounds Checking !!!
				
				// Is the above cell empty?
				cellPos = coord_t(r - 1, c);
				if (r > 0 && (
					board.getSpace(cellPos) == 
					FillBoard::Empty ||
					cellPos == HEAD_POS)) {
					emptys++;
				}
				// Is the below cell empty?
				cellPos = coord_t(r + 1, c);
				if (r + 1 < N_ROWS && (
					board.getSpace(cellPos) == 
					FillBoard::Empty ||
					cellPos == HEAD_POS)) {
					emptys++;
				}
				// Is the right cell empty?
				cellPos = coord_t(r, c + 1);
				if (c + 1 < N_COLS && (
					board.getSpace(cellPos) == 
					FillBoard::Empty ||
					cellPos == HEAD_POS)) {
					emptys++;
				}
				// Is the left cell empty?
				cellPos = coord_t(r, c - 1);
				if (c > 0 && (
					board.getSpace(cellPos) == 
					FillBoard::Empty ||
					cellPos == HEAD_POS)) {
					emptys++;
				}
			
				// Do we have 0 or 1 openings?
				// 0 or 1 openings means dead end
				// 2 3 or 4 openings means no dead end
				if (emptys < 2) {
					nDeadEnds++;
				}
			}

			// Do we have 2 or more dead ends?
			if (nDeadEnds > 1) {
				// Yes, we have found atleast 2 dead ends.
				// This path cannot possibly make a solution
				return true;
			}
		}
	}

	// We have not found 2 or more dead ends.
	// Therefore this path may possibly create a solution
	return false;
}
