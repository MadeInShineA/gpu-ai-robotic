#include <iostream>
#include <stdlib.h>

#include "Benchmark.h"

// Slice
#include "SliceGmHostUse.h"
#include "SliceGmUse.h"
#include "SliceMultiUse.h"
#include "SliceSmUse.h"

// Montecarlo
#include "MontecarloStreamUse.h"
#include "MontecarloThreadUse.h"
#include "MontecarloUse.h"
#include "entier_montecarlo.h"

// Vector Stream
#include "AddVectorBistreamUse.h"
#include "AddVectorTristreamUse.h"
#include "AddVectorUse.h"
#include "VectorTools.h"

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

// Slice
static void sliceGMHOST();
static void sliceGM();
static void sliceSM();
static void sliceMulti();

// Montecarlo
static void montecarloMono();
static void montecarloThread();
static void montecarloStream();

// Vector Stream
static void addvector();
static void addvectorBistream();
static void addvectorTristream();

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

int mainBenchmark()
    {
        // one at a time!

        // Slice
        {
        sliceGMHOST();
        //	sliceGM();
        //	sliceSM();
        //	sliceMulti();
        }

        // Montecarlo
        {
            //	montecarloMono();
            //	montecarloThread();
            //	montecarloStream();
        }

        // Vector
        {
        //	addvector();
        //	addvectorBistream();
        //	addvectorTristream();
        }

    return EXIT_SUCCESS;
    }

// ---------------------------------
//  Private
// ---------------------------------

void sliceGMHOST()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    SliceGmHostUse use(IS_VERBOSE);

    Benchmark::run(use.getRunnableGPU(), DURATION_MAX_S);
    }

void sliceGM()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    SliceGmUse use(IS_VERBOSE);

    Benchmark::run(use.getRunnableGPU(), DURATION_MAX_S);
    }

void sliceSM()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    SliceSmUse use(IS_VERBOSE);

    Benchmark::run(use.getRunnableGPU(), DURATION_MAX_S);
    }

void sliceMulti()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    SliceMultiUse use(IS_VERBOSE);

    Benchmark::run(use.getRunnableGPU(), DURATION_MAX_S);
    }

void montecarloMono()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    MontecarloUse use(IS_VERBOSE);

    Benchmark::run(use.getRunnableGPU(), DURATION_MAX_S);
    }

void montecarloThread()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    MontecarloThreadUse use(IS_VERBOSE);

    Benchmark::run(use.getRunnableGPU(), DURATION_MAX_S);
    }

void montecarloStream()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    MontecarloStreamUse use(IS_VERBOSE);

    Benchmark::run(use.getRunnableGPU(), DURATION_MAX_S);
    }

void addvector()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    AddVectorUse use(IS_VERBOSE);

    Benchmark::run(use.getRunnableGPU(), DURATION_MAX_S);
    }

void addvectorBistream()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    AddVectorBistreamUse use(IS_VERBOSE);

    Benchmark::run(use.getRunnableGPU(), DURATION_MAX_S);
    }

void addvectorTristream()
    {
    const double DURATION_MAX_S = 10;
    const bool IS_VERBOSE = false;

    int nbSlice = 20;

    AddVectorTristreamUse use(nbSlice, IS_VERBOSE);

    Benchmark::run(use.getRunnableGPU(), DURATION_MAX_S);
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
