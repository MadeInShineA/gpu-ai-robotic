#pragma once

#include "Maths.h"
#include "cudas.h"
#include <math.h>

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class Vague3DMath_RGBA
    {

    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    __device__ Vague3DMath_RGBA(uint h, float t)
        :               // Inputs
          t(t),         //
          h(h),         //
          dim2(h >> 1), //
          // Tools
          K1(3 * 2.0f * PI_FLOAT / h), //
          K2(255.0f / 2.0f)
        {
        // rien
        }

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    __device__ void xyz(float3 *ptrSommetXYZ, uchar4 *ptrColorIJ, int i, int j)
        {
        float levelGrisFloat = levelGray0255(i, j);
        uchar levelGris = (uchar)levelGrisFloat;

            // color
            {
            ptrColorIJ->x = levelGris;
            ptrColorIJ->y = levelGris;
            ptrColorIJ->z = levelGris;
            ptrColorIJ->w = 255; // opaque
            }

            // sommet
            {
            ptrSommetXYZ->x = j - dim2; // warning j sur x
            ptrSommetXYZ->y = i - dim2; // warning i sur y
            ptrSommetXYZ->z = levelGrisFloat;
            }
        }

  private:
    // ---------------------------------
    // level gray
    // ---------------------------------

    __inline__ __device__ float levelGray0255(int i, int j)
        {
        float s = K1 * (i + t);
        return K2 * (cosf(s) + 1.0f);
        }

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Input
    int h;
    float t;

    // Tools
    int dim2;
    float K1;
    float K2;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
