#include "FillPath.h"

FillPath::FillPath(pair<size_t, size_t> start, size_t initialCapacity)
{
	path.reserve(initialCapacity);
	path.push_back(start);
}

FillPath::FillPath(const vector<pair<size_t, size_t>>& path)
{
	this->path.resize(path.size());

	for (auto p : path) {
		this->path.push_back(p);
	}
}

FillPath::FillPath(const FillPath & fillPath)
{
	this->path.reserve(fillPath.path.size());

	for (auto p : fillPath.path) {
		this->path.push_back(p);
	}
}

FillPath::~FillPath() {}

char FillPath::getChar(size_t pos) const
{
	// ------------ Is this the 1st char? -----------------
	if (pos == 0) {
		if (path.size() == 1) {
			return 0xF9;
		}

		pair<size_t, size_t> curr = path.at(0);
		pair<size_t, size_t> next = path.at(1);

		// Is it horizontal?
		if (curr.first == next.first) {
			return ASCII::HORIZONTAL;
		}
		else {
			return ASCII::VERTICAL;
		}
		return 0xA8;
	}

	// ------------ Is this the last char -----------------
	if (pos == path.size() - 1) {
		pair<size_t, size_t> prev = path.at(path.size() - 2);
		pair<size_t, size_t> curr = path.at(path.size() - 1);

		// Is it horizontal?
		if (prev.first == curr.first) {
			return ASCII::HORIZONTAL;
		}
		else {
			return ASCII::VERTICAL;
		}
		return 0xA8;
	}

	// ------------ Is this in the middle -----------------
	if (pos < path.size() - 1) {
		pair<size_t, size_t> prev = path.at(pos - 1);
		pair<size_t, size_t> curr = path.at(pos);
		pair<size_t, size_t> next = path.at(pos + 1);

		bool up =
			(prev.first == curr.first - 1) ||
			(next.first == curr.first - 1);
		bool down =
			(prev.first == curr.first + 1) ||
			(next.first == curr.first + 1);
		bool right =
			(prev.second == curr.second + 1) ||
			(next.second == curr.second + 1);
		bool left =
			(prev.second == curr.second - 1) ||
			(next.second == curr.second - 1);
	}

	return 0xA8;
}

const pair<size_t, size_t>& FillPath::getCoordinate(size_t pos) const
{
	return path.at(pos);
}

size_t FillPath::size() const
{
	return path.size();
}

void FillPath::moveUp()
{
	pair<size_t, size_t> temp = path.back();
	temp.first--;

	path.push_back(temp);
}

void FillPath::moveDown()
{
	pair<size_t, size_t> temp = path.back();
	temp.first++;

	path.push_back(temp);
}

void FillPath::moveRight()
{
	pair<size_t, size_t> temp = path.back();
	temp.second++;

	path.push_back(temp);
}

void FillPath::moveLeft()
{
	pair<size_t, size_t> temp = path.back();
	temp.second--;

	path.push_back(temp);
}

pair<size_t, size_t> FillPath::moveBack()
{
	pair<size_t, size_t> temp = path.back();
	path.pop_back();
	return temp;
}
