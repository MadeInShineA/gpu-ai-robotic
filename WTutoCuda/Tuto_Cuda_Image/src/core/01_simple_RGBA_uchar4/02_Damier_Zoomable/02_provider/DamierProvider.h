#pragma once

#include "Provider_uchar4_A.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class DamierProvider : public Provider_uchar4_A
    {
  public:
    /**
     * Override
     */
    virtual Grid grid();

    /**
     * Override
     */
    virtual Animable_I<uchar4> *createAnimable(const Grid &grid, bool isVerbose = false);

    /**
     * Override facultatif
     */
    ColorRGB_01 colorTitle();
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
