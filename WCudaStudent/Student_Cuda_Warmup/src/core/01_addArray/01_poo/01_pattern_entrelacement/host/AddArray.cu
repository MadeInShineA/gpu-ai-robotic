#include "AddArray.h"

#include <assert.h>
#include <iostream>

#include "GM.h"
#include "Hardware.h"
#include "Kernel.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;

// --------------------------------------------------------------------------------------
// Extern
// --------------------------------------------------------------------------------------

extern __global__ void addArray(float* ptrGMV1, float* ptrGMV2, float* ptrGMW, int n);

// --------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------

AddArray::AddArray(const Grid& grid, float* ptrV1, float* ptrV2, float* ptrW, int n)
    : ptrV1(ptrV1), //
      ptrV2(ptrV2), //
      ptrW(ptrW),   //
      n(n),         //
      dg(grid.dg),  //
      db(grid.db)
    {
    this->sizeVector = sizeof(float) * n; // TODO addArray // octet

        // MM (malloc Device)
        {
        GM::malloc(&this->ptrGMV1, this->sizeVector);
        GM::malloc(&this->ptrGMV2, this->sizeVector);
        GM::malloc(&this->ptrGMW, this->sizeVector);
        // TODO addArray
        }
    }

AddArray::~AddArray()
    { // MM (device free)
        {
        GM::free(ptrGMV1);
        GM::free(ptrGMV2);
        GM::free(ptrGMW);
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
        GM::memcpyHToD(this->ptrGMV1, this->ptrV1, this->sizeVector);
        GM::memcpyHToD(this->ptrGMV2, this->ptrV2, this->sizeVector);
        // TODO addArray
        }

    // TODO addArray // call kernel // assynchrone
    addArray<<<this->dg, this->db>>>(this->ptrGMV1, this->ptrGMV2, this->ptrGMW, this->n);

        // Kernel::synchronize();// inutile

        // MM (Device -> Host)
        {
        GM::memcpyDToH(ptrW, ptrGMW, this->sizeVector);
        // TODO addArray // MM barier de synchronisation implicite
        }
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
