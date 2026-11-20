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

extern __global__ void KAddIntProtocoleII(int* ptrSumGM);

// ---------------------------------------------------------------------------------------------
// Constructors
// ---------------------------------------------------------------------------------------------

ReductionAddIntII::ReductionAddIntII(const Grid& grid, int* ptrSum, bool isVerbose)
    : // RunnableGPU(grid, "Reduce_AddInt_II_" + to_string(grid.threadCounts()),isVerbose), // classe parente
      RunnableGPU(grid, "Reduce_AddInt_II", isVerbose), // classe parente
      ptrSum(ptrSum)
    {
    // TODO ReductionAddIntII
    this->sizeSM = sizeof(int) * grid.threadByBlock();
    GM::mallocInt0(&ptrSumGM);
    }

ReductionAddIntII::~ReductionAddIntII()
    {
    // TODO ReductionAddIntII
    GM::free(ptrSumGM);
    }

// ----------------------------------------------------------------------------------
// Methodes
// ----------------------------------------------------------------------------------

void ReductionAddIntII::run()
    {
    // TODO ReductionAddIntII
    KAddIntProtocoleII<<<grid.dg, grid.db, this->sizeSM>>>(ptrSumGM);

    GM::memcpyDToH_int(ptrSum, ptrSumGM);
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
