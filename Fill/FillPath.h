#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

#include "E:\Documents\Programming\C++\ASCII\ASCII\ASCII.h"

using namespace std;

typedef pair<size_t, size_t> coord_t;

class FillPath
{
public:
	FillPath(coord_t start, size_t initialCapacity = 16);
	FillPath(const vector<coord_t> & path);
	FillPath(const FillPath & fillPath);
	~FillPath();
	
	char getChar(size_t pos) const;
	const coord_t & getCoordinate(size_t pos) const;
	size_t size() const;

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	coord_t moveBack();

	stringstream toStream() const;

protected:
	// pair<row, col>
	vector<coord_t> path;
};

