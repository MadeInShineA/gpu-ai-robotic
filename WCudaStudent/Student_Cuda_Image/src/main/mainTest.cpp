#include <iostream>
#include <stdlib.h>

#include "VTMandelbrot.h"
#include "VTRippling.h"

#include "VTRaytracingCM.h"
#include "VTRaytracingCM2SM.h"
#include "VTRaytracingGM.h"
#include "VTRaytracingSM.h"

#include "real_mandelbrot.h"

using std::cout;
using std::endl;
using std::string;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

static void rippling();
static void mandelbrot();
static void raytracing();

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

int mainTest()
    {
    // activer ci-dessous seulement le TP voulu (pas tous)

    rippling();
    // mandelbrot(); // fp16 only
    // raytracing(); // voir code ci-dessous pour activer la version voulue

    return EXIT_SUCCESS;
    }

// ---------------------------------
// Private
// ---------------------------------

void rippling()
    {
    VTRippling test1;

    test1.run();
    }

/**
 * fp16 only
 */
void mandelbrot()
    {
    assert(mandelbrotReal::isFp16());

    VTMandelbrot test1;

    test1.run();
    }

/**
 * activer ci-dessous la version souhaiter
 */
void raytracing()
    {
    VTRaytracingGM test1;
    // VTRaytracingSM test2;
    // VTRaytracingCM test3;
    // VTRaytracingCM2SM test4;

    test1.run();
    //    test2.run();
    //    test3.run();
    //    test4.run();
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
