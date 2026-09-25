#pragma once

#include <math.h>

#include "Calibreur.cu.h"
#include "Colors.cu.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class Damier3DMath_RGBA
    {

    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    __device__ Damier3DMath_RGBA(int n, float t)
        : calibreur(Interval<float>(-1, 1), Interval<float>(0, 0.9)), //
          n(n),                                                       //
          t(t)
        {
        // rien
        }

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    __device__ void processIJ(float3 *ptrSommet, uchar4 *ptrColorRGBA, float x, float y)
        {
        float z = f(x, y);

            // sommet
            {
            ptrSommet->x = x;
            ptrSommet->y = y;
            ptrSommet->z = z;
            }

            // color
            {
            calibreur.calibrer(&z);
            float hue01 = z;
            Colors::HSB_TO_RVB(hue01, ptrColorRGBA);
            }
        }

  private:
    __inline__ __device__ float f(float x, float y)
        {
        return sinf(x * n + t) * cosf(y * n + t);
        }

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Input
    int n;
    float t;

    // Tools
    Calibreur<float> calibreur;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
