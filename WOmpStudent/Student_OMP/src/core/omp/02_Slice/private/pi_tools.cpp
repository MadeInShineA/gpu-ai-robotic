#include "pi_tools.h"

#include <iostream>
#include <math.h>

#include "ChronoFactory.h"
#include "Couts.h"
#include "Maths.h"

using std::cout;
using std::endl;
using std::string;

// -----------------------------------------------------------------------
// Declarations
// -----------------------------------------------------------------------

static bool equals(double x, double y, double epsilon = 1e-6);

// -----------------------------------------------------------------------
// Implementations
// -----------------------------------------------------------------------

bool test(AlgoPI algoPI, int n, string title)
    {
    cout << Couts::CYAN << Couts::REVERSE << title << Couts::RESET;

    // Calcul
    Chrono *ptrChrono = ChronoFactory::create();

    double piHat = algoPI(n);
    ptrChrono->stop();
    double timeS = ptrChrono->getElapseTimeS();
    double fps = 1 / timeS;

    delete ptrChrono;

    // affichage
    if (piHat == -1)
        {
        cout << Couts::YELLOW << " TODO" << Couts::RESET << endl << endl;
        return false;
        }
    else
        {
        bool isOk = equals(piHat, PI, 1e-6);
        cout << "\t";
        Couts::status(isOk, "success", "failed");

        cout << endl << endl;

        cout.precision(8);
        cout << "\tPi hat  = " << piHat << endl;
        cout << "\tPi true = " << PI << endl;

        cout.precision(3); // fps
        // cout << endl << "\tn    : " << n;
        cout << endl << "\ttime : " << timeS << " [s]";
        cout << endl << "\tfps  : " << fps << endl;
        cout << endl;

        return isOk;
        }
    }

// ---------------------------------
// Private
// ---------------------------------

bool equals(double x, double y, double epsilon)
    {
    return fabs(x - y) <= epsilon;
    }

// -----------------------------------------------------------------------
// End
// -----------------------------------------------------------------------