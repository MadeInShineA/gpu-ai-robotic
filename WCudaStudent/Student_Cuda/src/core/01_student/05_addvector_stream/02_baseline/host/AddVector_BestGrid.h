#pragma once

#include <assert.h>
#include <iostream>

#include "Couts.h"
#include "Grid.h"
#include "Hardware.h"

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

namespace addVector
    {

    class BestGrid
        {

      public:
        static Grid get()
            {
            const int MP = Hardware::getMPCount();
            const int CORE_MP = Hardware::getCoreCountMP();

            dim3 dg(1, 1, 1);
            dim3 db(1, 1, 1); // contrainte : max(db.x*db.y*db.z)<=1024
            Grid grid(dg, db);

                // TODO addVector grid

                // to remove once coded
                {
                Couts::redln("aie aie aie, your best grid won t build itself");
                assert(false);
                }

            return grid;
            }
        };
    } // namespace addVector

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
