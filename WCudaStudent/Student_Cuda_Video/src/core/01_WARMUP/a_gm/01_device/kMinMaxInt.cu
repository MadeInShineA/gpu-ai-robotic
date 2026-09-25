#include "Lock.cu.h"
#include "Maths.h"
#include "Reduction.cu.h"
#include "Thread1D.cu.h"
#include "Thread2D.cu.h"
#include "cudas.h"

// --------------------------------------------------------------------------------------
//  Declarations
// --------------------------------------------------------------------------------------

static __device__ void reductionIntraThread(uchar *tabPixelsGM, uint wh, int *tabMinSM, int *tabMaxSM);

// --------------------------------------------------------------------------------------
//  Tools
// --------------------------------------------------------------------------------------

// ---------------------------------
//  min/max
// ---------------------------------

__device__ void max(int *ptrA, int b)
    {
    *ptrA = MAX(*ptrA, b);
    }

__device__ void min(int *ptrA, int b)
    {
    *ptrA = MIN(*ptrA, b);
    }

// ---------------------------------
//  min/max	ATOMIC
// ---------------------------------

__device__ void minAtomic(int *ptrA, int b)
    {
    atomicMin(ptrA, b);
    }

__device__ void maxAtomic(int *ptrA, int b)
    {
    atomicMax(ptrA, b);
    }

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

/**
 * Tips:
 * 	(T1) char to int car atomicMin n'existe pas pour uchar (Cuda11)
 * 	(T2) atomicMin necessaire pour la reduction InterBlock de notre classe Reduce generic qui recoit deux pointeur de fonctions:
 * 			- un binaryOperator
 * 			- un binaryOperator "Thread-safe", que l'on donne sous la forme d'un atomicXXX (XXX=add, min, max, ...)
 */
__global__ void kMinMaxInt(uchar *tabPixelsGM, uint wh, int *ptrMinGM, int *ptrMaxGM)
    {
    // 2 tableaux en SM depuis un 1 tableau 2x plus grand
    extern __shared__ int tabSM[];
    int *tabMinSM = tabSM;
    int *tabMaxSM = tabSM + Thread2D::nbThreadBlock(); // car il y a autant de case en SM que de thread par block

    // 1) reduction IntraThread (min et max en meme temps dans tabMinSM et respectivement tabMaxSM)
    // 2) reduction (inra-block et inter-block) de tabMinSM : resultat dans ptrMinGM
    // 3) reduction (inra-block et inter-block) de tabMaxSM : resultat dans ptrMaxGM

    // TODO kMinMaxInt
    }

__device__ void reductionIntraThread(uchar *tabPixelsGM, uint wh, int *tabMinSM, int *tabMaxSM)
    {
    // on travaille en int, car atomicMin/atomicMax n'existe pas en uchar (cuda11)
    int min = 255;
    int max = 0;

    // TODO
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
