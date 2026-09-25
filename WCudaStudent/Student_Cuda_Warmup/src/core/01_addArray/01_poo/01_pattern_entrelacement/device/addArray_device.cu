#include "Thread1D.cu.h"
#include "Thread2D.cu.h"
#include "cudas.h"

#include <stdio.h>

// --------------------------------------------------------------------------------------
// Implementation
// --------------------------------------------------------------------------------------

/**
 * output : void required, because kernel is asynchrone
 */
__global__ void addArray(float *ptrGMV1, float *ptrGMV2, float *ptrGMW, int n)
    {
    const int NB_THREAD = Thread2D::nbThread();
    const int TID = Thread2D::tid();

    // Debug, facultatif
    //    if (TID == 0)
    //	{
    //	printf("Coucou from device tid = %d", TID);
    //	}

    // pattern entrelacement

    // TODO addArray
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
