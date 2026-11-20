#include "ReductionIntI.h"

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

extern __global__ void KIntProtocoleI(int* ptrSumGM);

// ---------------------------------------------------------------------------------------------
// Constructors
// ---------------------------------------------------------------------------------------------

ReductionIntI::ReductionIntI(const Grid& grid, int* ptrSum, bool isVerbose)
    : // RunnableGPU(grid, "Redude_Generic_IntI_" + to_string(grid.threadCounts()),isVerbose), // classe parente
      RunnableGPU(grid, "Reduce_Generic_IntI", isVerbose), // classe parente
      ptrSum(ptrSum)
    {
    // TODO ReductionIntI
    this->sizeSM = sizeof(int) * grid.threadByBlock();

    GM::mallocInt0(&ptrSumGM);
    }

ReductionIntI::~ReductionIntI()
    {
    // TODO ReductionIntI
    GM::free(ptrSumGM);
    }

// ----------------------------------------------------------------------------------
// Methodes
// ----------------------------------------------------------------------------------

void ReductionIntI::run()
    {
    // TODO ReductionIntI
    KIntProtocoleI<<<grid.dg, grid.db, this->sizeSM>>>(ptrSumGM);

    GM::memcpyDToH_int(ptrSum, ptrSumGM);
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
