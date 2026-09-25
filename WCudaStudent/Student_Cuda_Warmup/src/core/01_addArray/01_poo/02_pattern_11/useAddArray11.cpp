// Attention : Extension .cpp

#include <iostream>
#include <stdio.h>

#include "AddArray11.h"
#include "ArrayTools.h"
#include "Couts.h"
#include "Hardware.h"

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

static Grid createGrid(int n);

// --------------------------------------------------------------------------------------
// Implementation
// --------------------------------------------------------------------------------------

bool exemple_addArray_11()
    {
    // Exemple de data
    int n = 8;
    float *ptrV1 = ArrayTools::createV1(n); // create and fill
    float *ptrV2 = ArrayTools::createV2(n); // create and fill
    float *ptrW = new float[n];

        // Cuda
        {
        Grid grid = createGrid(n);
        AddArray11 cudaCode(grid, ptrV1, ptrV2, ptrW, n);
        cudaCode.run();
        }

    // Check justesse
    bool isOk = ArrayTools::isAddVector_Ok(ptrV1, ptrV2, ptrW, n);

        // Print
        {
        ArrayTools::print(ptrV1, n);
        ArrayTools::print(ptrV2, n);
        cout << "--------------------------------------------------------------------" << endl;
        ArrayTools::print(ptrW, n);
        cout << endl;
        }

        // Delete
        {
        delete ptrV1;
        delete ptrV2;
        delete ptrW;
        }

    return isOk;
    }

// ---------------------------------
// Private
// ---------------------------------

/**
 * static
 */
static Grid createGrid(int n)
    {
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    dim3 dg(1, 1, 1);         // TODO addArray
    dim3 db(1, 1, 1);         // TODO addArray  // produit <=1024
    Grid grid(dg, db, false); // false -> dont check heuristic

        // to remove once coded
        {
        Couts::redln("aie aie aie, your best grid won t build itself");
        assert(false);
        }

    assert(grid.threadCounts() == n);

    return grid;
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
