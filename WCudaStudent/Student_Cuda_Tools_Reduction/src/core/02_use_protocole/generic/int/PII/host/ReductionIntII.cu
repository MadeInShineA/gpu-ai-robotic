#include "ReductionIntII.h"

#include "GM.h"
#include "Grid.h"

#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;
using std::to_string;

// ---------------------------------------------------------------------------------------------
// Extern
// ---------------------------------------------------------------------------------------------

extern __global__ void KIntProtocoleII(int *ptrSumGM);

// ---------------------------------------------------------------------------------------------
// Constructors
// ---------------------------------------------------------------------------------------------

ReductionIntII::ReductionIntII(const Grid &grid, int *ptrSum, bool isVerbose)
    : // RunnableGPU(grid, "Reduce_Generic_IntII_" + to_string(grid.threadCounts()),isVerbose), // classe parente
      RunnableGPU(grid, "Reduce_Generic_IntII", isVerbose), // classe parente
      ptrSum(ptrSum)
    {
    // TODO ReductionIntII
    this->sizeSM = -1;
    }

ReductionIntII::~ReductionIntII()
    {
    // TODO ReductionIntII
    }

// ----------------------------------------------------------------------------------
// Methodes
// ----------------------------------------------------------------------------------

void ReductionIntII::run()
    {
    // TODO ReductionIntII
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
