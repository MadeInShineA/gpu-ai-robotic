#include "Damier3DMath_RGBA.h"
#include "Indices.cu.h"
#include "Thread2D.cu.h"

#include "cudas.h"

#include "DomainMath3D_GPU.h"
using namespace gpu;

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

/**
 * w nbPoint en x
 * h nbPoint en y
 */
__global__ void damier3DCuda(float3 *tabVerticesXYZGM, uchar4 *tabVerticesColorGM, int w, int h, DomainMath3D domaineMath, int n, float t)
    {
    Damier3DMath_RGBA damierMath(n, t);

    const int TID = Thread2D::tid();
    const int NB_THREAD = Thread2D::nbThread();

    const int WH = w * h;

    float x;
    float y;
    float DX;
    float DY;

    int vertexI;
    int vertexJ;

    domaineMath.delta(w, h, &DX, &DY);

    int s = TID;
    while (s < WH)
        {
        Indices::toIJ(s, w, &vertexI, &vertexJ); // update (vertexI, vertexJ)

        domaineMath.toXY(DX, DY, vertexI, vertexJ, &x, &y);

        damierMath.processIJ(&tabVerticesXYZGM[s], &tabVerticesColorGM[s], x, y); // update (sommet s , color s)

        s += NB_THREAD;
        }
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
