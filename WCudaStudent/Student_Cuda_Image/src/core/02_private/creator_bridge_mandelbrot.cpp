#include <iostream>

#include "Mandelbrot.h"
#include "Mandelbrot_BestGrid.h"

using std::cerr;
using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

extern Animable_I<uchar4> *createMandelbrot(const Grid &grid, uint w, uint h, const DomaineMath &domaineMath, bool isVerbose, int nMin, int nMax)
    {
    return new Mandelbrot(grid, w, h, domaineMath, isVerbose, nMin, nMax);
    }

extern Grid bestGridMandelbrot()
    {
    return mandelbrot::BestGrid::get();
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
