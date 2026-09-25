#pragma once

#include "Provider_uchar_A.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class VagueGrayProvider : public Provider_uchar_A
    {
  public:
    /**
     * Override
     */
    virtual Grid grid();

    /**
     * Override
     */
    virtual Animable_I<uchar> *createAnimable(const Grid &grid, bool isVerbose = false);
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
