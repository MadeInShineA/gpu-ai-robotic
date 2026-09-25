#include "Thread1D.cu.h"
#include "Thread2D.cu.h"
#include "cudas.h"

#include "ReductionAdd.cu.h"

#include <stdio.h>

// ---------------------------------------------------------------------------------------------
// Declarations
// ---------------------------------------------------------------------------------------------

static __device__ void reductionIntraThread(int *tabSM);

// ---------------------------------------------------------------------------------------------
// Implementation
// ---------------------------------------------------------------------------------------------

/**
 * 1 partout en tabSM
 */
__global__ void KAddIntProtocoleI(int *ptrSumGM)
    {
    // TODO ReductionAddIntI

    // Reception tabSM
    // ReductionIntraThread
    // ReductionAdd

    // __syncthreads(); // des threads de meme block!// Question : utile? ou?
    }

// ---------------------------------
// Private
// ---------------------------------

/**
 * 1 partout en tabSM
 */
__device__ void reductionIntraThread(int *tabSM)
    {
    // TODO ReductionAddIntI
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
