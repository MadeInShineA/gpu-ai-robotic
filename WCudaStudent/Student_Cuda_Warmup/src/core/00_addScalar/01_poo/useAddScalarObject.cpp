// Attention : Extension .cpp

#include <assert.h>
#include <iostream>

#include "AddScalar.h"

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Implementation
// --------------------------------------------------------------------------------------

bool exemple_addScalar_object()
    {
    float a = 8;
    float b = 80;
    float sum;

        // Cuda
        {
        AddScalar addcuda(a, b, &sum);
        addcuda.run();
        }

    cout << "\n[Hello : Host   side : addScalar object] " << a << " + " << b << " = " << sum << endl;

    return sum == a + b;
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
