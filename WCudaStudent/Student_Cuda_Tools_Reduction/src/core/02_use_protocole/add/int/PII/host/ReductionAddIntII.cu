#include "ReductionAddIntII.h"

#include "GM.h"
#include "Grid.h"

#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;
using std::to_string;

// ---------------------------------------------------------------------------------------------
// Declaration
// ---------------------------------------------------------------------------------------------

extern __global__ void KAddIntProtocoleII(int *ptrSumGM);

// ---------------------------------------------------------------------------------------------
// Constructors
// ---------------------------------------------------------------------------------------------

ReductionAddIntII::ReductionAddIntII(const Grid &grid, int *ptrSum, bool isVerbose)
    : // RunnableGPU(grid, "Reduce_AddInt_II_" + to_string(grid.threadCounts()),isVerbose), // classe parente
      RunnableGPU(grid, "Reduce_AddInt_II", isVerbose), // classe parente
      ptrSum(ptrSum)
    {
    // TODO ReductionAddIntII
    this->sizeSM = -1;
    }

ReductionAddIntII::~ReductionAddIntII()
    {
    // TODO ReductionAddIntII
    }

// ----------------------------------------------------------------------------------
// Methodes
// ----------------------------------------------------------------------------------

void ReductionAddIntII::run()
    {
    // TODO ReductionAddIntII
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
