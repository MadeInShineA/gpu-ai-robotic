#pragma once

#include <assert.h>
#include <iostream>

#include "Couts.h"
#include "Grid.h"
#include "Hardware.h"
#include "real_mandelbrot.h"

// --------------------------------------------------------------------------------------
// Implementation
// --------------------------------------------------------------------------------------

namespace mandelbrot
    {

    class BestGrid
        {

      public:
        static Grid get()
            {
            const int MP = Hardware::getMPCount();
            const int CORE_MP = Hardware::getCoreCountMP();

// fp64 (float 64 bits)
#ifdef MANDELBROT_DOUBLE
                // TODO Mandelbrot
                //  to remove once coded
                {
                Couts::redln("aie aie aie, your best grid won t build itself");
                assert(false);
                }
#endif

// fp32 (float 32 bits)
#ifdef MANDELBROT_FLOAT
                // TODO Mandelbrot
                //  to remove once coded
                {
                Couts::redln("aie aie aie, your best grid won t build itself");
                assert(false);
                }
#endif

// fp16 (float 32 bits)
#ifdef MANDELBROT_HALF
                // TODO Mandelbrot
                //  to remove once coded
                {
                Couts::redln("aie aie aie, your best grid won t build itself");
                assert(false);
                }
#endif
            }
        };
    } // namespace mandelbrot

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
