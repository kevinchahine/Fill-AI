#pragma once

#include <iostream>
#include <iomanip>

#include "E:\Documents\Programming\C++\ASCII\ASCII\ASCII.h"

#include "FillBoard.h"
#include "FillGame.h"
#include "FillPath.h"

using namespace std;

class UserInterface
{
public:
	UserInterface();
	~UserInterface();

	void setCurrentGamePtr(FillGame * gamePtr);
	FillGame * getCurrentGamePtr();
	const FillGame * getCurrentGamePtr() const;

	/*
		@return 
		0 game over - game is not won, but no further moves will allow for a win
		1 play on - further moves are possible, but game is not won
		2 game won - game is solved
	*/
	int simpleUpdate();

private:
	FillGame * currentGamePtr;

};

