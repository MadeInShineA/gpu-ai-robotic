#pragma once

#include <assert.h>
#include <iostream>

#include "Couts.h"
#include "Grid.h"
#include "Hardware.h"
#include "memoryType.h"

// --------------------------------------------------------------------------------------
// Implementtaions
// --------------------------------------------------------------------------------------

namespace raytracing
    {

    class BestGrid
        {

      public:
        static Grid get(MemoryType memoryType)
            {
            const int MP = Hardware::getMPCount();
            const int CORE_MP = Hardware::getCoreCountMP();

            switch (memoryType)
                {
            case GM:
                {
                    // to remove once coded
                    {
                    Couts::redln("aie aie aie, your best grid won t build itself");
                    assert(false);
                    }

                // TODO Raytracing
                }
            case CM:
                {
                    // to remove once coded
                    {
                    Couts::redln("aie aie aie, your best grid won t build itself");
                    assert(false);
                    }
                // TODO Raytracing
                }
            case SM:
                {
                    // to remove once coded
                    {
                    Couts::redln("aie aie aie, your best grid won t build itself");
                    assert(false);
                    }
                // TODO Raytracing
                }
            case CM2SM:
                {
                    // to remove once coded
                    {
                    Couts::redln("aie aie aie, your best grid won t build itself");
                    assert(false);
                    }
                // TODO Raytracing
                }
            default:
                {
                assert(false);
                }
                } // switch end
            }
        };
    } // namespace raytracing

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
