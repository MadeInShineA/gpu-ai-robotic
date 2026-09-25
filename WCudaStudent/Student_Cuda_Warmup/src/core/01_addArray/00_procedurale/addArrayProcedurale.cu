// Attention : Extension .cu

#include <assert.h>
#include <iostream>
#include <stdio.h>

#include "GM.h"
#include "Kernel.h"
#include "Thread1D.cu.h"
#include "Thread2D.cu.h"
#include "cudas.h"

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

static __global__ void kaddArray(float *ptrGMV1, float *ptrGMV2, float *ptrGMW, int n);

// --------------------------------------------------------------------------------------
// Host
// --------------------------------------------------------------------------------------

/**
 * si possible toujours en float sur un gpu
 * ptrW receptionne le resultat
 * n nombre de case
 */
__host__ void addArray_procedurale(float *ptrV1, float *ptrV2, float *ptrW, int n) // __host__ facultatif
    {
    // TODO addArray
    }

// --------------------------------------------------------------------------------------
// Device
// --------------------------------------------------------------------------------------

/**
 * output : void required, because kernel is asynchrone
 */
__global__ void kaddArray(float *ptrGMV1, float *ptrGMV2, float *ptrGMW, int n)
    {
    const int NB_THREAD = Thread2D::nbThread();
    const int TID = Thread2D::tid();

    // pattern entrelacement

    // TODO addArray
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
