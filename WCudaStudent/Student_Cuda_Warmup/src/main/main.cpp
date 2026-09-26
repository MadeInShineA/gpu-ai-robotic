#include <iostream>
#include <stdlib.h>

#include "Couts.h"
#include "Hardware.h"

using std::cerr;
using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

// ---------------------------------
// Extern
// ---------------------------------

// Scalar
extern bool exemple_addScalar_procedurale();
extern bool exemple_addScalar_object();

// Array
extern bool exemple_addArray_procedurale();
extern bool exemple_addArray_object();
extern bool exemple_addArray_11();

// ---------------------------------
// Private
// ---------------------------------

static void array(bool& isOk);
static void scalar(bool& isOk);

// --------------------------------------------------------------------------------------
// Implementation
// --------------------------------------------------------------------------------------

int main(int argc, char** argv)
    {
        // Facultatif
        {
        Hardware::loadCudaDriverAll();
        Hardware::printAllSimple();

        const int DEVICE_ID = 0;
        Hardware::setDevice(DEVICE_ID);
        }

    const int IS_VERBOSE = true;

        // run
        {
        bool isOk = true;

        // Commenter ce dont vous n'avez pas besoin ci-dessous
        // scalar(isOk); // commenter dans la methode ci-dessous ce que vous ne voulez pas lancer
        array(isOk); // commenter dans la methode ci-dessous ce que vous ne voulez pas lancer

        Couts::statusln(isOk);

        return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
        }
    }

// ---------------------------------
// Private
// ---------------------------------

static void scalar(bool& isOk)
    {
    isOk &= exemple_addScalar_procedurale();
    // isOk &= exemple_addScalar_object();
    }

static void array(bool& isOk)
    {
    isOk &= exemple_addArray_procedurale();
    //  isOk &= exemple_addArray_object();
    //  isOk &= exemple_addArray_11();
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
