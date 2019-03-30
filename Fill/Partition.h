#pragma once

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>

using namespace std;

class Partition
{
public:
	Partition();
	~Partition();
	
	// Takes a sub partition number and adds it to the same partitions as
	// mutualSubPartitionNumber.
	// If newSubPartitionNumber does not yet have a mutual subPartition then
	// Let mutualSubPartition equal newSubPartitionNumber
	// If newSubPartitionNumber is already in this object, then nothing will happen
	// If newSubPartitionNumber is more than 1 greater than the current highest 
	// subPartition number than function will trigger an error.
	// If mutalSubPartition number does not exist in object, then nothing will happen
	void addNewSubPartition(size_t newSubPartitionNumber, size_t mutualSubPartitionNumber);
	
	size_t subPartitionToPartition(size_t subPartitionNumber) const;

	void mergePartitions(size_t subPar1, size_t subPar2);

	size_t getNPartitions() const;
	size_t getNSubPartitions() const;

	void showPartitions() const;

private:
	vector<size_t> subPartitions;
	size_t highestPartitionNumber = 0;
};

