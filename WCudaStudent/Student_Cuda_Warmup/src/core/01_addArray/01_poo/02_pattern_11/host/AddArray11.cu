#include "AddArray11.h"

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

extern __global__ void addArray11(float *ptrGMV1, float *ptrGMV2, float *ptrGMW, int n);

// --------------------------------------------------------------------------------------
// Implementation
// --------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------

AddArray11::AddArray11(const Grid &grid, float *ptrV1, float *ptrV2, float *ptrW, int n)
    : ptrV1(ptrV1), //
      ptrV2(ptrV2), //
      ptrW(ptrW),   //
      n(n),         //
      dg(grid.dg),  //
      db(grid.db)
    {
    this->sizeVector = -1; // TODO addArray11 // octet

    // TODO addArray11
    }

AddArray11::~AddArray11()
    {
    // TODO addArray11
    }

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

/**
 * override
 */
void AddArray11::run()
    {
        // MM (copy Host->Device)
        {
        // TODO addArray11
        }

    assert(dg.x * dg.y * dg.z * db.x * db.y * db.z == n);
        // TODO addArray11 call kernel

        // MM (Device -> Host)
        {
        // TODO addArray11
        }
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
