// Attention : Extension .cpp

#include <assert.h>
#include <iostream>

#include "AddScalar.h"

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Extern
// --------------------------------------------------------------------------------------

extern int addScalar_procedurale(int a, int b);

// --------------------------------------------------------------------------------------
// Implementation
// --------------------------------------------------------------------------------------

bool exemple_addScalar_procedurale()
    {
    int a = 10;
    int b = 1;

    int sum = addScalar_procedurale(a, b); // by cuda

    cout << "\n[Hello : Host   side : addScalar procedurale] " << a << " + " << b << " = " << sum << endl;

    return sum == a + b;
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
