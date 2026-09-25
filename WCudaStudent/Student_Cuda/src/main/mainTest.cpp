#include <iostream>
#include <stdlib.h>

// Slice
#include "VTSliceGM.h"
#include "VTSliceGMHOST.h"
#include "VTSliceMulti.h"
#include "VTSliceSM.h"

// Montecarlo
#include "VTMontecarlo.h"
#include "VTMontecarloStream.h"
#include "VTMontecarloThread.h"
#include "entier_montecarlo.h"

// Vector Stream
#include "VTVector.h"
#include "VTVectorBistream.h"
#include "VTVectorTristream.h"

using std::cout;
using std::endl;
using std::string;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

static void slice();
static void montercarlos();
static void vectorStream();

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

int mainTest()
    {
    // activer ci-dessous seulement le TP voulu (pas tous)

    slice(); // voir code ci-dessous pour activer la version voulue
    // montercarlos(); 	// voir code ci-dessous pour activer la version voulue
    // vectorStream(); 	// voir code ci-dessous pour activer la version voulue

    return EXIT_SUCCESS;
    }

// ---------------------------------
//  Private
// ---------------------------------

/**
 * activer ci-dessous la version souhaiter
 */
void slice()
    {
    VTSliceGMHOST test1;
    // VTSliceGM test2;
    // VTSliceSM test3;
    // VTSliceMulti test4;

    test1.run();
    // test2.run();
    // test3.run();
    // test4.run();
    }

/**
 * activer ci-dessous la version souhaiter
 * Warning: a lancer une fois en int une fois en long  (TODO cbi a checker
 */
void montercarlos()
    {
    VTMontecarlo test1;
    // VTMontecarloThread test2;
    // VTMontecarloStream test3;

    test1.run();
    // test2.run();
    // test3.run();
    }

/**
 * activer ci-dessous la version souhaiter
 */
void vectorStream()
    {
    VTVector test1;
    // VTVectorBistream test2;
    // VTVectorTristream test3;

    test1.run();
    // test2.run();
    // test3.run();
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
