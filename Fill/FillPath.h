#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

#include "E:\Documents\Programming\C++\ASCII\ASCII\ASCII.h"

using namespace std;

typedef pair<size_t, size_t> coord_t;

namespace A {
	class FillPath
	{
	public:
		FillPath(coord_t start, size_t initialCapacity = 16);
		FillPath(const vector<coord_t> & path);
		FillPath(const A::FillPath & fillPath);
		~FillPath();

		char getChar(size_t pos) const;
		char getChar_back() const;
		const coord_t & getCoordinate(size_t pos) const;
		const coord_t & getCoordinate_back() const;
		size_t size() const;

		coord_t moveUp();
		coord_t moveDown();
		coord_t moveRight();
		coord_t moveLeft();

		coord_t moveBack();

		stringstream toStream() const;

	private:
		bool isInPath(coord_t location) const;

	protected:
		// pair<row, col>
		vector<coord_t> path;
	};
}
