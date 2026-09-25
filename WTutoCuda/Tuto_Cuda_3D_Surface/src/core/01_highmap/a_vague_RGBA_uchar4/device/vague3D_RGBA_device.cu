#include "Indices.cu.h"
#include "Thread2D.cu.h"
#include "Vague3DMath_RGBA.h"

#include "cudas.h"

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

/**
 * w nbPoint en x
 * h nbPoint en y
 */
__global__ void vague3DCuda(float3 *tabVerticesXYZGM, uchar4 *tabVerticesColorGM, int w, int h, int t)
    {
    Vague3DMath_RGBA vagueMath(h, t);

    const int TID = Thread2D::tid();
    const int NB_THREAD = Thread2D::nbThread();

    const int WH = w * h;

    int i;
    int j;

    int s = TID;
    while (s < WH)
        {
        Indices::toIJ(s, w, &i, &j); // update (i, j)

        vagueMath.xyz(&tabVerticesXYZGM[s], &tabVerticesColorGM[s], i, j);

        s += NB_THREAD;
        }
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
