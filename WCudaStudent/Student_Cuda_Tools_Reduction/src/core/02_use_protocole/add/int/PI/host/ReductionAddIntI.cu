#include "ReductionAddIntI.h"

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

extern __global__ void KAddIntProtocoleI(int* ptrSumGM);

// ---------------------------------------------------------------------------------------------
// Constructors
// ---------------------------------------------------------------------------------------------

ReductionAddIntI::ReductionAddIntI(const Grid& grid, int* ptrSum, bool isVerbose)
    : // RunnableGPU(grid, "Reduce_Add_IntI_" + to_string(grid.threadCounts()),isVerbose), // classe parente
      RunnableGPU(grid, "Reduce_Add_IntI", isVerbose), // classe parente
      ptrSum(ptrSum)
    {
    // TODO ReductionAddIntI
    // MM pour ptrSumGM (oubliez pas initialisation)
    this->sizeSM = sizeof(int) * grid.threadByBlock();
    GM::mallocInt0(&ptrSumGM);

    // Tip:  Il y a une methode dedier pour malloquer un int cote device et l'initialiser a zero
    //
    //		GM::mallocInt0(&ptrSumGM);
    }

ReductionAddIntI::~ReductionAddIntI()
    {
    // TODO ReductionAddIntIg
    GM::free(ptrSumGM);
    }
// ---------------------------------------------------------------------------------------------
// Methodes
// ---------------------------------------------------------------------------------------------

void ReductionAddIntI::run()
    {
    // TODO ReductionAddIntI
    // appeler le kernel
    // recuperer le resulat coter host

    KAddIntProtocoleI<<<grid.dg, grid.db, this->sizeSM>>>(ptrSumGM);

    GM::memcpyDToH_int(ptrSum, ptrSumGM);

    // Tip:  Il y a une methode dedier ramener coter host un int
    //
    //		GM::memcpyDtoH_int(ptrDestination, ptrSourceGM););
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
