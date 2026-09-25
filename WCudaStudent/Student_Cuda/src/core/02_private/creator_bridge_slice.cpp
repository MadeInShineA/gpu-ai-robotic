#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

#include "SliceGMHOST.h"
#include "SliceGMHost_BestGrid.h"

#include "SliceGM.h"
#include "SliceGM_BestGrid.h"

#include "SliceSM.h"
#include "SliceSM_BestGrid.h"

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

// ---------------------------------
// GM host
// ---------------------------------

extern RunnableGPU_I *createSliceGMHOST(Grid grid, int nbSlice, double *ptrPiHat, bool isVerbose)
    {
    return new SliceGMHOST(grid, nbSlice, ptrPiHat, isVerbose);
    }

extern Grid bestGridSliceGMHOST()
    {
    return sliceGMHost::BestGrid::get();
    }

// ---------------------------------
// GM
// ---------------------------------

extern RunnableGPU_I *createSliceGM(Grid grid, int nbSlice, double *ptrPiHat, bool isVerbose)
    {
    return new SliceGM(grid, nbSlice, ptrPiHat, isVerbose);
    }

extern Grid bestGridSliceGM()
    {
    return sliceGM::BestGrid::get();
    }

// ---------------------------------
// SM
// ---------------------------------

extern RunnableGPU_I *createSliceSM(Grid grid, int nbSlice, double *ptrPiHat, bool isVerbose)
    {
    return new SliceSM(grid, nbSlice, ptrPiHat, isVerbose);
    }

extern Grid bestGridSliceSM()
    {
    return sliceSM::BestGrid::get();
    }

// ---------------------------------
// multi
// ---------------------------------

extern RunnableGPU_I *createSliceMulti(Grid grid, int nbSlice, double *ptrPiHat, bool isVerbose)
    {
    // return new SliceMulti(grid, nbSlice, ptrPiHat, isVerbose);
    }

extern Grid bestGridSliceMulti()
    {
    // return sliceMulti::BestGrid::get();
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
