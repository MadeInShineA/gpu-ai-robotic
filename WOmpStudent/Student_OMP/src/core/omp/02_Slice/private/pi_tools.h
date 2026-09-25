#pragma once

#include <string>

// -----------------------------------------------------------------------
// Declarations
// -----------------------------------------------------------------------

// ptr fonction de type:		 double xxx(int n)
// ou xxx sera une methode de calcul de pi
typedef double (*AlgoPI)(int);

bool test(AlgoPI algoPI, int n, std::string title);

// -----------------------------------------------------------------------
// End
// -----------------------------------------------------------------------