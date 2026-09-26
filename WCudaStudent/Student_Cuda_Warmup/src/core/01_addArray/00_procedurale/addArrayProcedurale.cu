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

static __global__ void kaddArray(float* ptrGMV1, float* ptrGMV2, float* ptrGMW, int n);

// --------------------------------------------------------------------------------------
// Host
// --------------------------------------------------------------------------------------

/**
 * si possible toujours en float sur un gpu
 * ptrW receptionne le resultat
 * n nombre de case
 */
__host__ void addArray_procedurale(float* ptrV1, float* ptrV2, float* ptrW, int n) // __host__ facultatif
    {

    float* ptrGMV1;
    float* ptrGMV2;
    float* ptrGMW;

    size_t size = sizeof(float) * n;

    // Assign the Global Memory
    GM::malloc(&ptrGMV1, size);
    GM::malloc(&ptrGMV2, size);
    GM::malloc(&ptrGMW, size);

    // Move the array values to the Device
    GM::memcpyHToD(ptrGMV1, ptrV1, size);
    GM::memcpyHToD(ptrGMV2, ptrV2, size);

    // TODO: Put correct size
    dim3 dg(4, 4, 2);
    dim3 db(4, 4, 2);

    // Call the kernel
    kaddArray<<<dg, db>>>(ptrGMV1, ptrGMV2, ptrGMW, n);

    // Get back the results
    GM::memcpyDToH(ptrW, ptrGMW, size);

    // Free the Global memory
    GM::free(ptrGMV1);
    GM::free(ptrGMV2);
    GM::free(ptrGMW);
    }

// --------------------------------------------------------------------------------------
// Device
// --------------------------------------------------------------------------------------

/**
 * output : void required, because kernel is asynchrone
 */
__global__ void kaddArray(float* ptrGMV1, float* ptrGMV2, float* ptrGMW, int n)
    {
    const int NB_THREAD = Thread2D::nbThread();
    const int TID = Thread2D::tid();

    int work = TID;

    while (work < n)
        {
        ptrGMW[work] = ptrGMV1[work] + ptrGMV2[work];

        work += NB_THREAD;
        }
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
