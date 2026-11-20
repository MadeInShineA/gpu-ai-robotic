#include "ReductionAdd.cu.h"
#include "Thread1D.cu.h"
#include "Thread2D.cu.h"

#include "cudas.h"

#include <stdio.h>

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

static __device__ void reductionIntraThread(float* tabSM, int nbSlice);
static __device__ float f(float x);

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

__global__ void sliceSM(int nbSlice, float* ptrPiHatGM)
    {
    // TODO SliceSM

    // Reception tabSM
    // ReductionIntraThread
    // Reduction de tabSM (use tools ReductionAdd)

    // __syncthreads(); necessaire? ou? pas a la fin en tout cas
    extern __shared__ float tabSM[];
    reductionIntraThread(tabSM, nbSlice);
    __syncthreads();
    ReductionAdd::reduce(tabSM, ptrPiHatGM);
    }

// ---------------------------------
//  Private
// ---------------------------------

/**
 * remplit la sm
 */
__device__ void reductionIntraThread(float* tabSM, int nbSlice)
    {
    // TODO SliceSM

    // Warning: Il faut employer TID et TID_LOCAL
    const int NB_THREAD = Thread2D::nbThread();
    const int TID = Thread2D::tid();
    const int TID_LOCAL = Thread2D::tidLocal();

    const float dx = 1.0f / float(nbSlice);

    int work = TID;

    tabSM[TID_LOCAL] = 0.0f;

    while (work < nbSlice)
        {
        tabSM[TID_LOCAL] += f(work * dx);
        work += NB_THREAD;
        }
    }

__device__ float f(float x)
    {
    return 4.f / (1.f + x * x);
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
