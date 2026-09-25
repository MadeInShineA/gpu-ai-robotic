#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Extern
// --------------------------------------------------------------------------------------

extern bool useTextureGM_int();
extern bool useTextureGM_float();

extern bool useTextureGM_uchar();
extern bool useTextureGM_char();

// extern bool useTextureGM_half(); // pas de texture en long (Cuda 11) // TODO a etudier

// extern bool useTextureGM_long(); 	// pas de texture en long (Cuda 11) // TODO a etudier
// extern bool useTextureGM_double(); 	// pas de texture en double (Cuda 11) // TODO a etudier

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

bool useTextureGM()
    {
    bool isOk = true;

    // 4 octets
    isOk &= useTextureGM_float();
    isOk &= useTextureGM_int();

    // 1 octets
    isOk &= useTextureGM_uchar();
    isOk &= useTextureGM_char();

    // 2 octets
    // isOk &= useTextureGM_half();

    // 8 octets : existe pas (Cuda 11)
    // isOk&= useTextureGM_long();
    // isOk&= useTextureGM_double();

    return isOk;
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
