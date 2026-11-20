#include "Thread1D.cu.h"
#include "Thread2D.cu.h"
#include "cudas.h"

#include "ReductionAdd.cu.h"

#include <stdio.h>

// ---------------------------------------------------------------------------------------------
// Declaration
// ---------------------------------------------------------------------------------------------

static __device__ void reductionIntraThread(int* tabSM);

// ---------------------------------------------------------------------------------------------
// Implementation
// ---------------------------------------------------------------------------------------------

/**
 * TID partout en tabSM
 */
__global__ void KAddIntProtocoleII(int* ptrSumGM)
    {
    // TODO ReductionAddIntII
    extern __shared__ int tabSM[];

    reductionIntraThread(tabSM);
    __syncthreads();

    ReductionAdd::reduce(tabSM, ptrSumGM);
    }

// ---------------------------------
// Private
// ---------------------------------

/**
 * TID partout en tabSM
 */
__device__ void reductionIntraThread(int* tabSM)
    {
    const int LOCAL_TID = Thread2D::tidLocal();
    const int TID = Thread2D::tid();

    tabSM[LOCAL_TID] = TID;
    // TODO ReductionAddIntII
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
