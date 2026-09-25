#pragma once

#include <assert.h>
#include <iostream>

#include "cuda_fp16.h"

// --------------------------------------------------------------------------------------
// Definitions
// --------------------------------------------------------------------------------------

// ---------------------------------
// Public
// ---------------------------------

// Choose one of the two (either/either):
// #define MANDELBROT_DOUBLE
// #define MANDELBROT_FLOAT
#define MANDELBROT_HALF

// ---------------------------------
// Private
// ---------------------------------

namespace mandelbrotReal
    {

// fp64 (float 64 bits)
#ifdef MANDELBROT_DOUBLE
    // #define real double
    using real = double;
#endif

// fp32 (float 32 bits)
#ifdef MANDELBROT_FLOAT
    // #define real float
    using real = float;
#endif

// fp16 (float 16 bits)
#ifdef MANDELBROT_HALF
    // #define real half
    using real = half;
#endif

    static std::string realToString()
        {

#ifdef MANDELBROT_DOUBLE
        return "fp64";
#endif

#ifdef MANDELBROT_FLOAT
        return "fp32";
#endif

#ifdef MANDELBROT_HALF
        return "fp16";
#endif
        }

    static bool isFp16()
        {

#ifdef MANDELBROT_DOUBLE
        return false;
#endif

#ifdef MANDELBROT_FLOAT
        return false;
#endif

#ifdef MANDELBROT_HALF
        return true;
#endif

        assert(false);
        }

    static bool isFp32()
        {

#ifdef MANDELBROT_DOUBLE
        return false;
#endif

#ifdef MANDELBROT_FLOAT
        return true;
#endif

#ifdef MANDELBROT_HALF
        return false;
#endif

        assert(false);
        }

    static bool isFp64()
        {

#ifdef MANDELBROT_DOUBLE
        return true;
#endif

#ifdef MANDELBROT_FLOAT
        return false;
#endif

#ifdef MANDELBROT_HALF
        return false;
#endif

        assert(false);
        }
    } // namespace mandelbrotReal

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
