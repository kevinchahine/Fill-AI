#pragma once

#include "FillSolver.h"
#include "Partition.h"

namespace FillSolver_Test {
	void full();

	void _5x5_grid();

	void _50x50_grid();

	void _NxM_grid(int n, int m);

	bool deadEnds();
	
	namespace Partition_Test {
		bool full();

		bool addSubPartitions();

		bool mergePartitions();

		bool getNPartitions();

		bool getNSubPartitions();
	}
}
