#pragma once

#include <assert.h>
#include <iostream>

#include "Couts.h"
#include "Grid.h"
#include "Hardware.h"

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

namespace sliceGM
    {

    class BestGrid
        {

      public:
        static Grid get()
            {
            const bool IS_CHECK_HEURISTIC = false;

            const int MP = Hardware::getMPCount();

            dim3 dg(1, 1, 1);                      // power 2 // TODO SliceGM grid
            dim3 db(1, 1, 1);                      // power 2 // TODO SliceGM grid
            Grid grid(dg, db, IS_CHECK_HEURISTIC); // all power 2

                // to remove once coded
                {
                Couts::redln("aie aie aie, your best grid won t build itself");
                assert(false);
                }

            return grid;
            }
        };

    } // namespace sliceGM

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
