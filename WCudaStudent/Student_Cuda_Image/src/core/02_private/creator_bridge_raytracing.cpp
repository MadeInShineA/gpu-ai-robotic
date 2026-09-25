#include <iostream>

#include "Raytracing.h"
#include "Raytracing_BestGrid.h"

using std::cerr;
using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

extern Animable_I<uchar4> *createRaytracing(const Grid &grid, uint w, uint h, float dt, bool isVerbose, int nbSpheres, MemoryType memoryType)
    {
    return new Raytracing(grid, w, h, dt, isVerbose, nbSpheres, memoryType);
    }

extern Grid bestGridRaytracing(MemoryType memoryType)
    {
    return raytracing::BestGrid::get(memoryType);
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
