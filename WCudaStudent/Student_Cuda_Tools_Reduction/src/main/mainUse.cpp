#include <iostream>
#include <stdlib.h>

using std::cerr;
using std::cout;
using std::endl;

#include "Couts.h"

// ReductionTools add
#include "UseReductionAddIntI.h"
#include "UseReductionAddIntII.h"

// ReductionTools generic
#include "UseReductionIntI.h"
#include "UseReductionIntII.h"
#include "UseReductionLongII.h"

// ---------------------------------------------------------------------------------------------
// Declarations
// ---------------------------------------------------------------------------------------------

static void reduction_add(bool &isOk);
static void reduction_generic(bool &isOk);

static void print(bool isSuccess);

// ---------------------------------------------------------------------------------------------
// Implementation
// ---------------------------------------------------------------------------------------------

static const int IS_VERBOSE = true;

int mainUse()
    {
    // activer ci-dessous seulement le TP voulu (pas tous)

    bool isOk = true;

    reduction_add(isOk); // voir code ci-dessous pour activer la version voulue
    // reduction_generic(isOk);	// voir code ci-dessous pour activer la version voulue

    print(isOk);

    return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
    }

// ---------------------------------------------------------------------------------------------
// TP
// ---------------------------------------------------------------------------------------------

/**
 * activer ci-dessous la version souhaiter
 */
void reduction_add(bool &isOk)
    {
        // InbI
        {
        UseReductionAddIntI algo(IS_VERBOSE);
        isOk &= algo.isOk(IS_VERBOSE);
        }

    // IntII
    //	{
    //	UseReductionAddIntII algo(IS_VERBOSE);
    //	isOk &= algo.isOk(IS_VERBOSE);
    //	}
    }

/**
 * activer ci-dessous la version souhaiter
 */
void reduction_generic(bool &isOk)
    { // InbI
        {
        UseReductionIntI algo(IS_VERBOSE);
        isOk &= algo.isOk(IS_VERBOSE);
        }

        // IntII
        {
        UseReductionIntII algo(IS_VERBOSE);
        isOk &= algo.isOk(IS_VERBOSE);
        }

        // LongII
        {
        UseReductionLongII algo(IS_VERBOSE);
        isOk &= algo.isOk(IS_VERBOSE);
        }
    }

// ---------------------------------------------------------------------------------------------
// Tools
// ---------------------------------------------------------------------------------------------

void print(bool isSuccess)
    {
    cout << endl << Couts::REVERSE;

    Couts::status(isSuccess, "Success, Congratulations !", "Failed, sorry!");

    cout << endl << Couts::RESET;
    }

// ---------------------------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------------------------
