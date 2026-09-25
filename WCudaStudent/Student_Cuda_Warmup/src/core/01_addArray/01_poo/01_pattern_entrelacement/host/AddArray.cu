#include "AddArray.h"

#include <assert.h>
#include <iostream>

#include "GM.h"
#include "Kernel.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;

// --------------------------------------------------------------------------------------
// Extern
// --------------------------------------------------------------------------------------

extern __global__ void addArray(float *ptrGMV1, float *ptrGMV2, float *ptrGMW, int n);

// --------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------

AddArray::AddArray(const Grid &grid, float *ptrV1, float *ptrV2, float *ptrW, int n)
    : ptrV1(ptrV1), //
      ptrV2(ptrV2), //
      ptrW(ptrW),   //
      n(n),         //
      dg(grid.dg),  //
      db(grid.db)
    {
    this->sizeVector = -1; // TODO addArray // octet

        // MM (malloc Device)
        {
        GM::malloc(&ptrGMV1, sizeVector);
        // TODO addArray
        }
    }

AddArray::~AddArray()
    { // MM (device free)
        {
        GM::free(ptrGMV1);
        // TODO addArray
        }
    }

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

/**
 * override
 */
void AddArray::run()
    { // MM (copy Host->Device)
        {
        GM::memcpyHToD(ptrGMV1, ptrV1, sizeVector);
        // TODO addArray
        }

        // TODO addArray // call kernel // assynchrone

        // Kernel::synchronize();// inutile

        // MM (Device -> Host)
        {
        // TODO addArray // MM barier de synchronisation implicite
        }
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
