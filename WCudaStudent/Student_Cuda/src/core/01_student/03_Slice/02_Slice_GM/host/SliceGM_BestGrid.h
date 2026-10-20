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
            const int CORE_COUNT = Hardware::getCoreCountMP();

            dim3 dg = (MP, 128, 128);
            dim3 db = (CORE_COUNT, 512, 512);

            Grid grid(dg, db, IS_CHECK_HEURISTIC); // all power 2

            return grid;
            }
        };

    } // namespace sliceGM

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
