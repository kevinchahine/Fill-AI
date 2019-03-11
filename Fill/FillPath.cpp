#include "FillPath.h"

FillPath::FillPath(coord_t start, size_t initialCapacity)
{
	path.reserve(initialCapacity);
	path.push_back(start);
}

FillPath::FillPath(const vector<coord_t>& path)
{
	this->path.reserve(path.capacity());

	for (auto p : path) {
		this->path.push_back(p);
	}
}

FillPath::FillPath(const FillPath & fillPath)
{
	this->path.reserve(fillPath.path.capacity());

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
			return 0xF9;	// Dot char
		}

		coord_t curr = path.at(0);
		coord_t next = path.at(1);

		// Is it horizontal?
		if (curr.first == next.first) {
			return ASCII::HORIZONTAL;
		}
		else {
			char c = ASCII::VERTICAL;
			cout << '\t' << c << endl;
			return ASCII::VERTICAL;
		}
		return 0xA8;
	}

	// ------------ Is this the last char -----------------
	if (pos == path.size() - 1) {
		coord_t prev = path.at(path.size() - 2);
		coord_t curr = path.at(path.size() - 1);

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
		coord_t prev = path.at(pos - 1);
		coord_t curr = path.at(pos);
		coord_t next = path.at(pos + 1);

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

		uint8_t temp =
			(up ? ASCII::UP : 0x00) |
			(down ? ASCII::DOWN : 0x00) |
			(left ? ASCII::LEFT : 0x00) |
			(right ? ASCII::RIGHT : 0x00);

		return ASCII::lines[
				temp
		];
	}

	return 0xA8;
}

const coord_t& FillPath::getCoordinate(size_t pos) const
{
	return path.at(pos);
}

size_t FillPath::size() const
{
	return path.size();
}

void FillPath::moveUp()
{
	coord_t temp = path.back();
	temp.first--;

	path.push_back(temp);
}

void FillPath::moveDown()
{
	coord_t temp = path.back();
	temp.first++;

	path.push_back(temp);
}

void FillPath::moveRight()
{
	coord_t temp = path.back();
	temp.second++;

	path.push_back(temp);
}

void FillPath::moveLeft()
{
	coord_t temp = path.back();
	temp.second--;

	path.push_back(temp);
}

coord_t FillPath::moveBack()
{
	coord_t temp = path.back();
	path.pop_back();
	return temp;
}

stringstream FillPath::toStream() const
{
	stringstream ss;

	for (size_t i = 0; i < path.size(); i++) {
		coord_t coord = getCoordinate(i);

		ss << coord.first << ", " << coord.second
			<< ' ' << getChar(i) << endl;
	}

	return ss;
}
