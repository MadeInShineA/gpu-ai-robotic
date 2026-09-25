// Attention : Extension .cu

#include "AddScalar.h"

#include "GM.h"
#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Extern
// --------------------------------------------------------------------------------------

extern __global__ void addScalar(float a, float b, float *ptrSumGM);

// --------------------------------------------------------------------------------------
// Implementation
// --------------------------------------------------------------------------------------

/**
 * ptrSum receptionne le resultat
 */
AddScalar::AddScalar(float a, float b, float *ptrSum)
    : a(a), //
      b(b), //
      ptrSum(ptrSum)
    {
    this->sizeFloat = sizeof(float); // [octet]

        // MM
        {
        GM::malloc(&ptrSumGM, sizeFloat);
        }
    }

AddScalar::~AddScalar()
    { // MM
        {
        GM::free(ptrSumGM);
        }
    }

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

void AddScalar::run()
    {
    // Grid : specifier le nombre de thread
    dim3 dg(1, 1, 1);
    dim3 db(1, 1, 1);                                     // contrainte produit <=1024
    assert(dg.x * dg.y * dg.z * db.x * db.y * db.z == 1); // 1 seul thread suffit, ici

    addScalar<<<dg, db>>>(a, b, ptrSumGM); // assynchrone

        // Device::synchronize(); // inutile

        // MM (Device -> Host)
        {
        GM::memcpyDToH(ptrSum, ptrSumGM, sizeFloat); // MM = barriere synchronisation implicite
        }
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
