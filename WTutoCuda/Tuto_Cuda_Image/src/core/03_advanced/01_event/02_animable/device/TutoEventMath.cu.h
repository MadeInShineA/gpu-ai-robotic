#pragma once

#include "Maths.h"
#include <math.h>

#include "Colors.cu.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class TutoEventMath
    {

    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    __device__ TutoEventMath(int w, int h, int t)
        : h(h), //
          t(t)
        {
        // rien
        }

    // constructeur copie automatique car pas pointeur dans VagueMath

    __device__ virtual ~TutoEventMath()
        {
        // rien
        }

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    __device__ void colorIJ(uchar4 *ptrColor, int i, int j)
        {
        uchar levelGris;

        levelGray(&levelGris, i, j); // update levelGris

        ptrColor->x = levelGris;
        ptrColor->y = levelGris;
        ptrColor->z = levelGris;

        ptrColor->w = 255; // opaque
        }

  private:
    __inline__ __device__ void levelGray(uchar *ptrLevelGris, int i, int j)
        {
        *ptrLevelGris = 255.f * (i + t) / (float)h;
        }

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Tools
    int h;
    int t;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
