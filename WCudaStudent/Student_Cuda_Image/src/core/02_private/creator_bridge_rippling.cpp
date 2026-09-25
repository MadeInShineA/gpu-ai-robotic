#include <iostream>

#include "Rippling.h"
#include "Rippling_BestGrid.h"

using std::cerr;
using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

extern Animable_I<uchar4> *createRippling(const Grid &grid, uint w, uint h, float dt, bool isVerbose)
    {
    return new Rippling(grid, w, h, dt, isVerbose);
    }

extern Grid bestGridRippling()
    {
    return rippling::BestGrid::get();
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
