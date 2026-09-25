#include <iostream>
#include <limits.h>

#include "Couts.h"
#include "pi_tools.h"

using std::cout;
using std::endl;

// -----------------------------------------------------------------------
// Extern
// -----------------------------------------------------------------------

namespace PI::sequentiel
    {
    double loop(int n);
    } // namespace PI::sequentiel

namespace PI::OMP::entrelacement
    {
    double promotionTab(int n);
    double critical(int n);
    double atomic(int n);
    } // namespace PI::OMP::entrelacement

namespace PI::OMP::parallelfor
    {
    double critical(int n);
    double atomic(int n);
    double promotionTab(int n);
    double reduction(int n);
    } // namespace PI::OMP::parallelfor

// -----------------------------------------------------------------------
// Implementations
// -----------------------------------------------------------------------

bool usePI()
    {
    const int N = INT_MAX / 10;

    cout << endl << Couts::BOLD << Couts::BLUE << "[PI OMP]" << Couts::RESET;
    cout << Couts::MAGENTA << " n=" << N << Couts::RESET << endl << endl;

    bool isOk = true;

    isOk &= test(PI::sequentiel::loop, N, "Sequentiel");

    isOk &= test(PI::OMP::entrelacement::promotionTab, N, "OMP / Entrelacer promotionTab");
    isOk &= test(PI::OMP::entrelacement::critical, N, "OMP / Entrelacer critical");
    isOk &= test(PI::OMP::entrelacement::atomic, N, "OMP / Entrelacer atomic");

    isOk &= test(PI::OMP::parallelfor::critical, N, "OMP / for critical");
    isOk &= test(PI::OMP::parallelfor::atomic, N, "OMP / for atomic");
    isOk &= test(PI::OMP::parallelfor::promotionTab, N, "OMP / for promotion tab");
    isOk &= test(PI::OMP::parallelfor::reduction, N, "OMP / for reduction-integrer");

    return isOk;
    }

// -----------------------------------------------------------------------
// End
// -----------------------------------------------------------------------