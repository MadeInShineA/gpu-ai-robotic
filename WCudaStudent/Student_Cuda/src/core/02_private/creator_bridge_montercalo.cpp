#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

#include "Montecarlo.h"
#include "Montecarlo_BestGrid.h"

#include "MontecarloMulti_BestGrid.h"
#include "MontecarloStream.h"
#include "MontecarloThread.h"

#include "Limits.h"
#include "entier_montecarlo.h"
#include "entiertype_montecarlo.h"

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

// ---------------------------------
// Mono
// ---------------------------------

extern montecarlo::EntierType entierTypeMontecarlo()
    {
    if (montecarlo::isInt())
        {
        return montecarlo::EntierType::INT;
        }
    else if (montecarlo::isLong())
        {
        return montecarlo::EntierType::LONG;
        }
    else
        {
        assert(false);
        return montecarlo::EntierType::LONG;
        }
    }

extern RunnableGPU_I *createMontecarlo(const Grid &grid, long nbDarTotalAsk, double *ptrPiHat, float h, bool isVerbose)
    {
    if (montecarlo::isInt())
        {
        assert(nbDarTotalAsk <= Limits::MAX_INT);
        return new Montecarlo(grid, (int)nbDarTotalAsk, ptrPiHat, h, isVerbose);
        }
    else if (montecarlo::isLong())
        {
        return new Montecarlo(grid, nbDarTotalAsk, ptrPiHat, h, isVerbose);
        }
    else
        {
        assert(false);
        return NULL;
        }
    }

extern Grid bestGridMontecarlo()
    {
    return montecarlo::BestGrid::get();
    }

// ---------------------------------
// Thread
// ---------------------------------

extern RunnableGPU_I *createMontecarloThread(const Grid &grid, long nbDarTotalAsk, double *ptrPiHat, float h, bool isVerbose)
    {
    if (montecarlo::isInt())
        {
        assert(nbDarTotalAsk <= Limits::MAX_INT);
        return new MontecarloThread(grid, (int)nbDarTotalAsk, ptrPiHat, h, isVerbose);
        }
    else if (montecarlo::isLong())
        {
        return new MontecarloThread(grid, nbDarTotalAsk, ptrPiHat, h, isVerbose);
        }
    else
        {
        assert(false);
        return NULL;
        }
    }

extern Grid bestGridMontecarloThread()
    {
    return montecarloMulti::BestGrid::get();
    }

// ---------------------------------
// Stream
// ---------------------------------

extern RunnableGPU_I *createMontecarloStream(const Grid &grid, long nbDarTotalAsk, double *ptrPiHat, float h, bool isVerbose)
    {
    if (montecarlo::isInt())
        {
        assert(nbDarTotalAsk <= Limits::MAX_INT);
        return new MontecarloStream(grid, (int)nbDarTotalAsk, ptrPiHat, h, isVerbose);
        }
    else if (montecarlo::isLong())
        {
        return new MontecarloStream(grid, nbDarTotalAsk, ptrPiHat, h, isVerbose);
        }
    else
        {
        assert(false);
        return NULL;
        }
    }

extern Grid bestGridMontecarloStream()
    {
    return montecarloMulti::BestGrid::get();
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
