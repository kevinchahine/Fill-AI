#pragma once

#include <time.h>
#include <stack>

#include "FillBoard.h"
#include "FillGame.h"

using namespace std;

class FillSolver : public FillGame
{
public:
	FillSolver(const FillBoard & board, const FillRoute & path);
	FillSolver(const FillBoard && board, const FillRoute && path);
	FillSolver(const FillGame & fillGame);
	
	~FillSolver();

	void solve();

private:
	// Solves using a breadth first search until it finds
	// every solution.
	void solve1();

	// Solves using a breadth first search and forward checking
	// until it finds every solution.
	void solve2();

	// Solves using a A* search and forward checking
	// until it finds every solution.
	void solve3();

	// ============ Forward Checking ======================
	bool forwardChecking(char move);

	// Returns true if it finds 2 or more deadends in the board
	// False otherwise
	bool deadEnds() const;

	// Returns true if it finds a divide in the board
	// False otherwise
	bool isThereADivide() const;

private:

};

