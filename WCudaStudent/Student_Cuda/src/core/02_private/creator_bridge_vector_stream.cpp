#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

#include "AddVector.h"
#include "AddVector_BestGrid.h"

#include "AddVectorBistream.h"
#include "AddVectorBistream_BestGrid.h"

#include "AddVectorTristream.h"
#include "AddVectorTristream_BestGrid.h"

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

// ---------------------------------
// base line
// ---------------------------------

RunnableGPU_I *createAddVector(const Grid &grid, int *ptrV1, int *ptrV2, int *ptrW, int n, bool isVerbose)
    {
    return new AddVector(grid, ptrV1, ptrV2, ptrW, n, isVerbose);
    }

Grid bestGridAddVector()
    {
    return addVector::BestGrid::get();
    }

// ---------------------------------
// bi-stream
// ---------------------------------

RunnableGPU_I *createAddVectorBistream(const Grid &grid, int *ptrV1, int *ptrV2, int *ptrW, int n, bool isVerbose)
    {
    return new AddVectorBistream(grid, ptrV1, ptrV2, ptrW, n, isVerbose);
    }

Grid bestGridAddVectorBistream()
    {
    return addVectorBistream::BestGrid::get();
    }

// ---------------------------------
// tri-stream
// ---------------------------------

RunnableGPU_I *createAddVectorTristream(const Grid &grid, int *ptrV1, int *ptrV2, int *ptrW, int n, int nbSlice, bool isVerbose)
    {
    return new AddVectorTristream(grid, ptrV1, ptrV2, ptrW, n, nbSlice, isVerbose);
    }

Grid bestGridAddVectorTriStream()
    {
    return addVectorTristream::BestGrid::get();
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
