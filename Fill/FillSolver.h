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
	void solve1();

private:

};

