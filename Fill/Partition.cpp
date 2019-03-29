#include "Partition.h"



Partition::Partition()
{
}


Partition::~Partition()
{
}

void Partition::addNewSubPartition(size_t newSubPartitionNumber)
{
	// 1.) Is this really a new partition?
	if (newSubPartitionNumber < subPartitions.size()) {
		// No, we already have it and have nothing to do
		return;
	}
	else if (newSubPartitionNumber == subPartitions.size()) {
		// Yes, it is new.
		// Resize subPartitions to fit it in
		subPartitions.resize(newSubPartitionNumber + 1);

		// Now is this in a new subPartition or one that already exists?

	}
	else {
		// Yes, it is new
		// But we can't add it because it skips previous sub partitions
#if __DEBUG__
		cerr << "subPartition skipps values" << __FILE__ << " line " << __LINE__ << endl;
#endif
		return;
	}
}
