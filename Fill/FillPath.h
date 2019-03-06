#pragma once

#include <iostream>
#include <vector>
#include <utility>

#include "E:\Documents\Programming\C++\ASCII\ASCII\ASCII.h"

using namespace std;

class FillPath
{
public:
	FillPath(pair<size_t, size_t> start, size_t initialCapacity = 16);
	FillPath(const vector<pair<size_t, size_t>> & path);
	FillPath(const FillPath & fillPath);
	~FillPath();
	
	char getChar(size_t pos) const;
	const pair<size_t, size_t> & getCoordinate(size_t pos) const;
	size_t size() const;

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	pair<size_t, size_t> moveBack();

protected:
	// pair<row, col>
	vector<pair<size_t, size_t>> path;
};

