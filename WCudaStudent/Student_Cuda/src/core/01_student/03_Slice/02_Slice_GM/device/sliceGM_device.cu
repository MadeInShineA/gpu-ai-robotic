#include "Thread1D.cu.h"
#include "Thread2D.cu.h"
#include "cudas.h"

#include <stdio.h>

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

static __device__ float f(float x);

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

/**
 * <pre>
 * Chaque thread effecteur une reduction intrathread avec le patern d'entrelacement,
 * puis stocke son résultat dans SA case dans tabGM
 *
 * tabGM est un tableau promu, qui a autant de case que de thread
 * </pre>
 */
__global__ void reductionIntraThreadGM(float* tabGM, int nbSlice)
    {
    // TODO SliceGM (idem SliceGMHOST) pour cette partie
    const int NB_THREAD = Thread2D::nbThread();
    const int TID = Thread2D::tid();

    const float dx = 1.0f / float(nbSlice);

    int work = TID;
    tabGM[TID] = 0.0f;

    while (work < nbSlice)
        {
        tabGM[TID] += f(work * dx);
        work += NB_THREAD;
        }
    }

/**
 * <pre>
 * Effectue la reduction de tabGM cote device, par ecrasement 2 à 2 successif.
 * Ce kernel d ecrasement est appeler depuis le host dans une boucle, avec le bon nombre de thread
 *
 * Hypothese : |tabGM| est une puissance de 2
 *
 * Output: le resultat de la reduction est tans tabGM[0]
 * </pre>
 */
__global__ void ecrasementGM(float* tabGM, int moitier)
    {
    // TODO SliceGM
    const int TID = Thread2D::tid();

    if (TID < moitier)
        {
        tabGM[TID] += tabGM[moitier + TID];
        }
    }

// ---------------------------------
//  Private
// ---------------------------------

__device__ float f(float x)
    {
    return 4.f / (1.f + x * x);
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
