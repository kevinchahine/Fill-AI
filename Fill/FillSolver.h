#pragma once

#include <stack>

#include "FillBoard.h"
#include "FillGame.h"

class FillSolver : public FillGame
{
public:
	FillSolver(const FillBoard & board, const A::FillPath & path);
	FillSolver(const FillBoard && board, const A::FillPath && path);
	FillSolver(const FillGame & fillGame);
	
	~FillSolver();

	void solve();

private:
	void solve1();

private:

};

