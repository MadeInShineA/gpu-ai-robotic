#include <iostream>
#include <stdlib.h>
#include <string>

// add
#include "VTReductionAddIntI.h"
#include "VTReductionAddIntII.h"

// generic
#include "VTReductionGenericI.h"
#include "VTReductionGenericII.h"
#include "VTReductionGenericLongII.h"

using std::cout;
using std::endl;
using std::string;

// ---------------------------------------------------------------------------------------------
// Declarations
// ---------------------------------------------------------------------------------------------

static void add();
static void generic();

// ---------------------------------------------------------------------------------------------
// Implementation
// ---------------------------------------------------------------------------------------------

int mainTest()
    {
    // activer ci-dessous seulement le TP voulu (pas tous)

    add();
    // generic();

    return EXIT_SUCCESS;
    }

// ---------------------------------
// Private
// ---------------------------------

/**
 * activer ci-dessous la version souhaiter
 */
void add()
    {
    VTReductionAddIntI test1;
    VTReductionAddIntII test2;

    test1.run();
    // test2.run();
    }

/**
 * activer ci-dessous la version souhaiter
 */
void generic()
    {
    VTReductionGenericI test1;
    VTReductionGenericII test2;
    VTReductionGenericLongII test3;

    test1.run();
    //    test2.run();
    //    test3.run();
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
