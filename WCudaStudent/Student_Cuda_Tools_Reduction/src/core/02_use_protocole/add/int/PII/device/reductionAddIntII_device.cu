#include "Thread1D.cu.h"
#include "Thread2D.cu.h"
#include "cudas.h"

#include "ReductionAdd.cu.h"

#include <stdio.h>

// ---------------------------------------------------------------------------------------------
// Declaration
// ---------------------------------------------------------------------------------------------

static __device__ void reductionIntraThread(int *tabSM);

// ---------------------------------------------------------------------------------------------
// Implementation
// ---------------------------------------------------------------------------------------------

/**
 * TID partout en tabSM
 */
__global__ void KAddIntProtocoleII(int *ptrSumGM)
    {
    // TODO ReductionAddIntII
    }

// ---------------------------------
// Private
// ---------------------------------

/**
 * TID partout en tabSM
 */
__device__ void reductionIntraThread(int *tabSM)
    {
    // TODO ReductionAddIntII
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
