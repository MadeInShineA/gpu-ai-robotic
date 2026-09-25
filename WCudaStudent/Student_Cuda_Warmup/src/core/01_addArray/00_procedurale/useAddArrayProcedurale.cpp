// Attention : Extension .cpp

#include <iostream>
#include <stdio.h>

#include "ArrayTools.h"

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Extern
// --------------------------------------------------------------------------------------

extern void addArray_procedurale(float *ptrV1, float *ptrV2, float *ptrW, int n);

// --------------------------------------------------------------------------------------
// Implementation
// --------------------------------------------------------------------------------------

bool exemple_addArray_procedurale()
    {
    // Exemple de data
    int n = 8;
    float *ptrV1 = ArrayTools::createV1(n); // create and fill
    float *ptrV2 = ArrayTools::createV2(n); // create and fill
    float *ptrW = new float[n];

    addArray_procedurale(ptrV1, ptrV2, ptrW, n); // by cuda

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

    return true;
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
