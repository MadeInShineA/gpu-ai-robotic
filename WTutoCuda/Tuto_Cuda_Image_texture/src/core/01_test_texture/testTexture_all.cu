#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Extern
// --------------------------------------------------------------------------------------

extern bool useTexture_int();
extern bool useTexture_float();

// extern bool useTexture_half(); // pas de texture en long (Cuda 11) // TODO a etudier

extern bool useTexture_uchar();
extern bool useTexture_char();

// extern bool useTexture_long(); 	// pas de texture en long (Cuda 11) // TODO a etudier
// extern bool useTexture_double(); 	// pas de texture en double (Cuda 11) // TODO a etudier

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

bool useTexture()
    {
    bool isOk = true;

    // 4 octets
    isOk &= useTexture_float();
    isOk &= useTexture_int();

    // 1 octets
    isOk &= useTexture_uchar();
    isOk &= useTexture_char();

    // 2 octest
    // isOk &=useTexture_half();

    // 8 octets : existe pas (Cuda 11)
    // isOk&= useTexture_long();
    // isOk&= useTexture_double();

    return isOk;
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
