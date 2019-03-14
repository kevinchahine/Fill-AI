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

	bool simpleUpdate();

private:
	FillGame * currentGamePtr;

};

