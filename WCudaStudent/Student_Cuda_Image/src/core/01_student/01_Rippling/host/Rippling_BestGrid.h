#pragma once

#include <assert.h>
#include <iostream>

#include "Couts.h"
#include "Grid.h"
#include "Hardware.h"

// --------------------------------------------------------------------------------------
// Implementation
// --------------------------------------------------------------------------------------

namespace rippling
    {

    class BestGrid
        {

      public:
        static Grid get()
            {
            const int MP = Hardware::getMPCount();
            const int CORE_MP = Hardware::getCoreCountMP();

            dim3 dg = {MP, 1, 1};
            dim3 db = {CORE_MP, 4, 1};

            Grid grid(dg, db);

            return grid;
            }
        };
    } // namespace rippling

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
