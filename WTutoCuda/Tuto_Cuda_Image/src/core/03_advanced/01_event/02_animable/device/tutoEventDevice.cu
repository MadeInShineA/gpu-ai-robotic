#include "Thread2D.cu.h"
#include "cudas.h"

#include "TutoEventMath.cu.h"

#include "Indices.cu.h"

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

__global__ void tutoEvent(uchar4 *tabPixelsGM, uint w, uint h, int t)
    {
    TutoEventMath math(w, h, t);

    const int WH = w * h;
    const int TID = Thread2D::tid();
    const int NB_THREAD = Thread2D::nbThread();

    int i; // in [0,h[
    int j; // in [0,w[

    int s = TID; // in [0,...
    while (s < WH)
        {
        Indices::toIJ(s, w, &i, &j); // update (i, j)

        math.colorIJ(&tabPixelsGM[s], i, j); // update ptrDevPixels[s]

        s += NB_THREAD;
        }
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
