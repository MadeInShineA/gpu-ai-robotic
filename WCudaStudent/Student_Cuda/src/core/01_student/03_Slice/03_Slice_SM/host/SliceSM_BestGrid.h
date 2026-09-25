#pragma once

#include <assert.h>
#include <iostream>

#include "Couts.h"
#include "Grid.h"
#include "Hardware.h"

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

namespace sliceSM
    {

    class BestGrid
        {

      public:
        static Grid get()
            {
            const int MP = Hardware::getMPCount();

            // TODO SliceGMHOST grid

            dim3 dg(1, 1, 1); // TODO
            dim3 db(1, 1, 1); // TODO contrainte : power 2
            Grid grid(dg, db);

                // to remove once coded
                {
                Couts::redln("aie aie aie, your best grid won t build itself");
                assert(false);
                }

            return grid;
            }
        };
    } // namespace sliceSM

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
