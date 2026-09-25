#pragma once

#include <assert.h>
#include <iostream>

#include "Couts.h"
#include "Grid.h"
#include "Hardware.h"
#include "entier_montecarlo.h"

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

namespace montecarloMulti
    {

    class BestGrid
        {

      public:
        static Grid get()
            {
            const int MP = Hardware::getMPCount();

#ifdef DAR_INT
            // TODO MontecarloMulti
#endif

#ifdef DAR_LONG
            // TODO MontecarloMulti
#endif

                // to remove once coded
                {
                Couts::redln("aie aie aie, your best grid won t build itself");
                assert(false);
                }
            }
        };

    } // namespace montecarloMulti

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
