#pragma once

#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

// ---------------------------------
// Public
// ---------------------------------

// Choose one of the two (either/or):
// #define DAR_INT
#define DAR_LONG

// ---------------------------------
// Private
// ---------------------------------

namespace montecarlo
    {
#ifdef DAR_INT
    using entier = int;
#endif

#ifdef DAR_LONG
    using entier = long;
#endif

    static inline std::string entierToString()
        {
#ifdef DAR_INT
        return "int";
#endif

#ifdef DAR_LONG
        return "long";
#endif

        assert(false); // ne devrait jamais arriver
        return "";     // pour éviter warning
        }

    static inline bool isInt()
        {
#ifdef DAR_INT
        return true;
#endif

#ifdef DAR_LONG
        return false;
#endif

        assert(false); // ne devrait jamais arriver
        return false;
        }

    static inline bool isLong()
        {
#ifdef DAR_INT
        return false;
#endif

#ifdef DAR_LONG
        return true;
#endif

        assert(false); // ne devrait jamais arriver
        return false;
        }
    } // namespace montecarlo

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
