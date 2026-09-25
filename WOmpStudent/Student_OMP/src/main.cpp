#include <iostream>
#include <stdlib.h>

#include "Couts.h"

using std::cerr;
using std::cout;
using std::endl;

// ------------------
//  Extern
// ------------------

extern bool usePI();
extern bool useHello();

// -----------------------------------------------------------------------
// Implementations
// -----------------------------------------------------------------------

int main()
    {
    bool isOk = true;

    // isOk &= useHello();
    isOk &= usePI();

    if (isOk)
        {
        cout << Couts::REVERSE << Couts::GREEN << "SUCCESS, Congratulation!" << Couts::RESET << endl << endl;
        }
    else
        {
        cout << Couts::REVERSE << Couts::RED << "FAILED, Sorry!" << Couts::RESET << endl << endl;
        }

    // return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
    return EXIT_SUCCESS;
    }

// -----------------------------------------------------------------------
// End
// -----------------------------------------------------------------------