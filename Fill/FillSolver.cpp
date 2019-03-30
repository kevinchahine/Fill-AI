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
			if (nSolutionsFound % 1000 == 0) {
				cout << nSolutionsFound << '\n';
			}
			/*cout << '.';
			if (nSolutionsFound % 60 == 0) {
				cout << endl;
			}
			*/
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
		<< "in " << (endTime - startTime) / 1000.0f << " sec" << endl;
}

bool FillSolver::forwardChecking(char move)
{
	return false;	// no FC

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

	bool deadEndsFC = deadEnds();
	bool partitionFC = partitions();

	bool fc = deadEndsFC && partitionFC;

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

bool FillSolver::partitions() const
{
	// value means cell is empty and has not been assigned
	const uint16_t UNASSIGNED_CELL = UINT16_MAX - 1;

	// value means cell is occupied by a line or obstacle
	
	const uint16_t OCCUPIED_CELL = UINT16_MAX;
	// 1.) Create a copy of the board so that 
	//		we don't mess it up
	const size_t N_ROWS = board.getNRows();
	const size_t N_COLS = board.getNCols();

	vector<vector<uint16_t>> b;
	b.resize(N_ROWS);
	for (size_t r = 0; r < N_ROWS; r++) {
		b[r].resize(N_COLS, UNASSIGNED_CELL);
	}
	
	// 2.) Fill cells that are occupied with lines or obstacles
	for (size_t r = 0; r < N_ROWS; r++) {
		for (size_t c = 0; c < N_COLS; c++) {
			// Is cell r, c occupied?
			if (board.getSpace(coord_t(r, c)) != FillBoard::Space::Empty) {
				// Yes it is occupied, 
				//	then set the corresponding element in b to occupied
				b[r][c] = OCCUPIED_CELL;
			}
		}
	}
	// 2.) Now all cells in b is a reflection of board.
	//		All cells in board that are filled are filled in b.

	// 3.) Create vector that will keep track of the partitions.
	
	Partition p;
	// ex: 
	// +-------------------+	Actual Partitions:
	// |     000           |	0 - contains 0
	// |11                 |	1 - 1s, 2s, 3s and 4s
	// |1111111222222333333|	2 - 5s
	// |111144444          |
	// |            555    |
	// +-------------------+
	//
	// subPartitions[0] = 0	// The 0s on the board belong to partition 0
	// subPartitions[1] = 1 // The 1s on the board belong to partition 1
	// subPartitions[2] = 1 // The 2s on the board belong to partition 1
	// subPartitions[3] = 1 // The 3s on the board belong to partition 1
	// subPartitions[4] = 1 // The 4s on the board belong to partition 1
	// subPartitions[5] = 2 // The 5s on the board belong to partition 2
	//
	// Expect to have no more than 8 partitions.
	// As long as we keep track of our partitions, we should
	//  rarely have more than 2 or 3.
	
	// 4.) Find the sub partitions
	for (size_t r = 0; r < N_ROWS; r++) {
		for (size_t c = 0; c < N_COLS; c++) {
			// 4-1.) Evaluate the status of the cell (b[r][c])

			if (b[r][c] == UNASSIGNED_CELL) {
				// See if there is cell assigned to a sub partition 
				// nearby. Only need to test ABOVE and to the LEFT
				
				// Is the ABOVE cell assigned to a sub partition? 
				if (r != 0 && b[r - 1][c] < UNASSIGNED_CELL) {
					// Yes, the ABOVE cell is assigned to a sub
					// partition
					//	Then THIS cell should also be in 
					//  the ABOVE cells sub partition.
					const size_t aboveSubPar = b[r - 1][c];
					b[r][c] = aboveSubPar;

					// Is the LEFT cell assigned to a sub partition?
					if (c != 0 && b[r][c - 1] < UNASSIGNED_CELL) {
						// Yes, both ABOVE AND LEFT cells are assigned
						// to sub partitions.
						// How about this question, are they in the 
						// !!!SAME!!! sub partition?
						
						const size_t leftSubPar = b[r][c - 1];
						if (aboveSubPar != leftSubPar) {
							// Oh no their in different sub partitions.
							// Since the two sub partitions are touching,
							// we need to merge them.
							p.mergePartitions(aboveSubPar, leftSubPar);
						}
					}
				}
				// Is the ABOVE cell assigned to a sub partition? 
				else {
					// No the ABOVE cell is not assigned to a sub partition.
					
					// Then is the LEFT cell assigned to a sub partition?
					if (c != 0 && b[r][c - 1] < UNASSIGNED_CELL) {
						// Yes, the LEFT cell is in a partition
						//	Then THIS cell should also be in 
						//  the LEFT cells sub partition.
						const size_t leftSubPar = b[r][c - 1];
						b[r][c] = leftSubPar;
					}
					else {
						// Nope, neither the ABOVE NOR THE LEFT cells
						// are assigned to sub partitions.
						// So we must assign a new sub partition to 
						// this cell
						size_t newSub = p.getNSubPartitions();
						b[r][c] = newSub;
						p.addNewSubPartition(newSub, newSub);
					}
				}
			}
		}
	}

	// 5.) Now we need to count and make sure we only have a single
	//	partition. Any more than 1 partition means we have cells that
	//  we cannot connect :(
	const size_t nPartitions = p.getNPartitions();

	return nPartitions > 1;
}
