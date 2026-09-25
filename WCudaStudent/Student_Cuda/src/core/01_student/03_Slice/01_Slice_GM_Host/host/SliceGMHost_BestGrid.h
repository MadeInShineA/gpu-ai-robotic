#pragma once

#include <assert.h>
#include <iostream>

#include "Couts.h"
#include "Grid.h"
#include "Hardware.h"

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

namespace sliceGMHost
    {

    class BestGrid
        {

      public:
        static Grid get()
            {
            const int MP = Hardware::getMPCount();

                // TODO SliceGMHOST grid

                // to remove once coded
                {
                Couts::redln("aie aie aie, your best grid won t build itself");
                assert(false);
                }
            }
        };

    } // namespace sliceGMHost

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
