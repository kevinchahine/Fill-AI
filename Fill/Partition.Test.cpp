#include "Partition.Test.h"

bool Partition_Test::full()
{
	Partition p;

	// Add some new subPartitions to p
	
	return false;
}

bool Partition_Test::addSubPartitions()
{
	Partition p;

	// Make sub partitions 0, 1 and 2 in the same partition
	cout << "add 0, 1 and 2 to the same partition" << endl;
	p.addNewSubPartition(0, 0);
	p.showPartitions();
	cout << endl;

	p.addNewSubPartition(1, 0);
	p.showPartitions();
	cout << endl;

	p.addNewSubPartition(2, 0);
	p.showPartitions();
	cout << endl;

	// Make sub partitions 3, 4, 5 and 6 in the samep partitions
	cout << "add 3, 4, 5 and 6 to the same partition" << endl;
	p.addNewSubPartition(3, 3);
	p.showPartitions();
	cout << endl;

	p.addNewSubPartition(4, 3);
	p.showPartitions();
	cout << endl;

	p.addNewSubPartition(5, 4);
	p.showPartitions();
	cout << endl;

	p.addNewSubPartition(6, 3);
	p.showPartitions();
	cout << endl;

	// Make sub partitions 7 by itself
	cout << "add 7 to its own partition" << endl;
	p.addNewSubPartition(7, 7);
	p.showPartitions();
	cout << endl;

	// Make sub partitions 8 part of 0, 1 and 2s
	cout << "add 8 to 0, 1 and 2s partition" << endl;
	p.addNewSubPartition(8, 0);
	p.showPartitions();
	cout << endl;

	return false;
}

bool Partition_Test::mergePartitions()
{
	Partition p;

	p.addNewSubPartition(0, 0);
	p.addNewSubPartition(1, 0);
	p.addNewSubPartition(2, 0);
	p.addNewSubPartition(3, 3);
	p.addNewSubPartition(4, 3);
	p.addNewSubPartition(5, 4);
	p.addNewSubPartition(6, 3);
	p.addNewSubPartition(7, 7);
	p.addNewSubPartition(8, 0);
	p.addNewSubPartition(9, 7);
	p.addNewSubPartition(10, 7);

	p.showPartitions();
	cout << endl;

	// Merge partitions for sub partitions 0 and 10
	p.mergePartitions(0, 10);
	p.showPartitions();
	cout << endl;

	return false;
}

bool Partition_Test::getNPartitions()
{
	Partition p;

	p.addNewSubPartition(0, 0);
	p.addNewSubPartition(1, 0);
	p.addNewSubPartition(2, 0);
	p.addNewSubPartition(3, 3);
	p.addNewSubPartition(4, 3);
	p.addNewSubPartition(5, 4);
	p.addNewSubPartition(6, 3);
	p.addNewSubPartition(7, 7);
	p.addNewSubPartition(8, 0);
	p.addNewSubPartition(9, 7);
	p.addNewSubPartition(10, 7);
	
	p.showPartitions();

	cout << "There are " << p.getNPartitions() << " partitions" << endl;

	return false;
}

bool Partition_Test::getNSubPartitions()
{
	Partition p;

	p.addNewSubPartition(0, 0);
	p.addNewSubPartition(1, 0);
	p.addNewSubPartition(2, 0);
	p.addNewSubPartition(3, 3);
	p.addNewSubPartition(4, 3);
	p.addNewSubPartition(5, 4);
	p.addNewSubPartition(6, 3);
	p.addNewSubPartition(7, 7);
	p.addNewSubPartition(8, 0);
	p.addNewSubPartition(9, 7);
	p.addNewSubPartition(10, 7);

	p.showPartitions();

	cout << "There are " << p.getNSubPartitions() << " sub partitions" << endl;

	return false;
}
