#include "Partition.h"

Partition::Partition() {}

Partition::~Partition() {}

void Partition::addNewSubPartition(size_t newSubPartitionNumber, size_t mutualSubPartitionNumber)
{
	const size_t SIZE = this->subPartitions.size();
	size_t newSub = newSubPartitionNumber;
	size_t mutSub = mutualSubPartitionNumber;

	if (newSub == SIZE) {
		if (mutSub == SIZE) {
			// Add a new sub partition number to a new partition
			this->subPartitions.push_back(highestPartitionNumber++);
		}
		else if (mutSub < SIZE) {
			size_t temp = this->subPartitions.at(mutSub);
			this->subPartitions.push_back(temp);
		}
		else {
			cerr << __FILE__ << " line " << __LINE__ << endl
				<< "\tsubPartitions are:";

			for (size_t s = 0; s < this->subPartitions.size(); s++) {
				cerr << ' ' << this->subPartitions.at(s);
			}
		}
	}
	else if (newSub > SIZE) {
		cerr << "newSubPartition is to great (" << newSub << ") "
			<< __FILE__ << " line " << __LINE__ << endl
			<< "\tsubPartitions are:";

		for (size_t s = 0; s < this->subPartitions.size(); s++) {
			cerr << ' ' << this->subPartitions.at(s);
		}
	}
}

size_t Partition::subPartitionToPartition(size_t subPartitionNumber) const
{
	return this->subPartitions.at(subPartitionNumber);
}

void Partition::mergePartitions(size_t subPar1, size_t subPar2)
{
	size_t par1 = this->subPartitions[subPar1];
	size_t par2 = this->subPartitions[subPar2];

	// Take all subpartitions that are in partition par2
	// And put them in partition par1
	for (size_t i = 0; i < this->subPartitions.size(); i++) {
		if (this->subPartitions[i] == par2) {
			this->subPartitions[i] = par1;
		}
	}
}

size_t Partition::getNPartitions() const
{
	return (subPartitions.size() == 0 ?
		0 : this->subPartitions.back() + 1);
}

size_t Partition::getNSubPartitions() const
{
	return this->subPartitions.size();
}

void Partition::showPartitions() const
{
	for (size_t s = 0; s < this->subPartitions.size(); s++) {
		cout << "sub partition " << setw(5) << s 
			<< " belongs to partition " << this->subPartitions.at(s) << endl;
	}
}
