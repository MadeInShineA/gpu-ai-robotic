#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

// ReductionTools add
#include "ReductionAddIntI.h"
#include "ReductionAddIntII.h"

// ReductionTools generic
#include "ReductionIntI.h"
#include "ReductionIntII.h"
#include "ReductionLongII.h"

// ---------------------------------------------------------------------------------------------
// Implementations
// ---------------------------------------------------------------------------------------------

RunnableGPU *createReductionAddIntI(const Grid &grid, int *ptrSum, bool isVerbose)
    {
    return new ReductionAddIntI(grid, ptrSum, isVerbose);
    }

RunnableGPU *createReductionAddIntII(const Grid &grid, int *ptrSum, bool isVerbose)
    {
    return new ReductionAddIntII(grid, ptrSum, isVerbose);
    }

RunnableGPU *createReductionIntI(const Grid &grid, int *ptrSum, bool isVerbose)
    {
    return new ReductionIntI(grid, ptrSum, isVerbose);
    }

RunnableGPU *createReductionIntII(const Grid &grid, int *ptrSum, bool isVerbose)
    {
    return new ReductionIntII(grid, ptrSum, isVerbose);
    }

RunnableGPU *createReductionLongII(const Grid &grid, long *ptrSum, bool isVerbose)
    {
    return new ReductionLongII(grid, ptrSum, isVerbose);
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
