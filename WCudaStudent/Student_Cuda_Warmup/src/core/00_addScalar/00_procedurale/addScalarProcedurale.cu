// Attention : Extension .cu

#include "GM.h"
#include "Kernel.h"
#include "cudas.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Declaration
// --------------------------------------------------------------------------------------

__global__ static void kaddScalar(int a, int b, int* ptrSumGM);

// --------------------------------------------------------------------------------------
// Host
// --------------------------------------------------------------------------------------

__host__ int addScalar_procedurale(int a, int b) // __host__ facultatif
    {
    int sum;            // variable pour le resultat cite host
    int* ptrSum = &sum; // on host (CPU)
    int* ptrSumGM;      // on device (GPU)

    // MM (memory managment)
    size_t size = sizeof(int);   // [octet]
    GM::malloc(&ptrSumGM, size); // Device memory allocation (*)

    // Grid : Specifier number thread : ici 1 thread au total !
    dim3 dg(1, 1, 1);
    dim3 db(1, 1, 1);

    kaddScalar<<<dg, db>>>(a, b, ptrSumGM); // assynchrone, call le kernel GPU addScalar

    Kernel::synchronize(); // inutile

        // MM (memory management)
        {
        GM::memcpyDToH(ptrSum, ptrSumGM, size); // Device -> Host, MM = barrier de synchronisation
        GM::free(ptrSumGM);                     //  free memory create in (*)
        }

    return sum;
    }

// --------------------------------------------------------------------------------------
// Device
// --------------------------------------------------------------------------------------

/**
 * Hyp : 1 seul thread, ie dg(1,1,1) et db (1,1,1)
 */
__global__ void kaddScalar(int a, int b, int* ptrSumGM)
    {
    *ptrSumGM = a + b; // Hyp: 1 seul thread (pas besoin de plus, pour additioner 2 nombre)

    // debug (1 seule thread ici)
    printf("[Hello : Device side : addScalar procedurale] %d + %d = %d", a, b, *ptrSumGM);
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
