#include "ReductionLongII.h"

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

extern __global__ void KLongProtocoleII(long* ptrSumGM);

// ---------------------------------------------------------------------------------------------
// Constructors
// ---------------------------------------------------------------------------------------------

ReductionLongII::ReductionLongII(const Grid& grid, long* ptrSum, bool isVerbose)
    : // RunnableGPU(grid, "Reduce_Generic_LongII_" + to_string(grid.threadCounts()),isVerbose), // classe parente
      RunnableGPU(grid, "Reduce_Generic_LongII", isVerbose), // classe parente
      ptrSum(ptrSum)
    {
    // TODO ReductionLongII
    this->sizeSM = sizeof(long) * grid.threadByBlock();
    GM::mallocLong0(&ptrSumGM);
    }

ReductionLongII::~ReductionLongII()
    {
    // TODO ReductionLongII
    GM::free(ptrSumGM);
    }

// ----------------------------------------------------------------------------------
// Methodes
// ----------------------------------------------------------------------------------

void ReductionLongII::run()
    {
    // TODO ReductionLongII
    KLongProtocoleII<<<grid.dg, grid.db, this->sizeSM>>>(ptrSumGM);
    GM::memcpyDToH_long(ptrSum, ptrSumGM);
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
