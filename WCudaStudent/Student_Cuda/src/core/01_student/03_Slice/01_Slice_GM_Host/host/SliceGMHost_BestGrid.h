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
            const int CORE_COUNT = Hardware::getCoreCountMP();

            dim3 dg = (MP, 32, 32);
            dim3 db = (CORE_COUNT, 256, 256);

            return Grid(dg, db);
            }
        };

    } // namespace sliceGMHost

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
