#include <iostream>
#include <stdlib.h>

#include "BruteForce.h"
#include "Hardware.h"
#include "Matlab.h"
#include "ProviderUse_I.h"

// Slice
#include "SliceProviderGM.h"
#include "SliceProviderGMHOST.h"
#include "SliceProviderMulti.h"
#include "SliceProviderSM.h"

// Montecarlo
#include "MontecarloProvider.h"
#include "MontecarloStreamProvider.h"
#include "MontecarloThreadProvider.h"
#include "entier_montecarlo.h"

// Vector
#include "AddVectorBistreamProvider.h"
#include "AddVectorProvider.h"
#include "AddVectorTristreamProvider.h"
#include "VectorTools.h"

using std::cout;
using std::endl;
using std::string;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

// Slice
static void sliceGMHOST(Matlab *ptrMatlab);
static void sliceGM(Matlab *ptrMatlab);
static void sliceSM(Matlab *ptrMatlab);
static void sliceMulti(Matlab *ptrMatlab);

// Montecarlo
static void montecarloMono(Matlab *ptrMatlab);
static void montecarloThread(Matlab *ptrMatlab);
static void montecarloStream(Matlab *ptrMatlab);

// Vector Stream
static void addvector(Matlab *ptrMatlab);
static void addvectorBistream(Matlab *ptrMatlab);
static void addvectorTristream(Matlab *ptrMatlab);
static void addvectorTristream1a(Matlab *ptrMatlab);
static void addvectorTristream1b(Matlab *ptrMatlab);
static void addvectorTristream2a(Matlab *ptrMatlab);
static void addvectorTristream2b(Matlab *ptrMatlab);
static void addvectorTristreamDebug(Matlab *ptrMatlab);

// Tools
static void bruteforce(ProviderUse_I *ptrProviderUse, Matlab *ptrMatlab, const PlotType &plotType, double durationMaxS);
static void bruteforceReduction(ProviderUse_I *ptrProviderUse, Matlab *ptrMatlab, const PlotType &plotType, double durationMaxS);

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

int mainBrutforce()
    {
    Matlab matlab;

        // one at a time!

        // Slice
        {
        sliceGMHOST(&matlab);
        //	sliceGM(&matlab);
        //	sliceSM(&matlab);
        //	sliceMulti(&matlab);
        }

        // Montecarlo
        {
            //	montecarloMono(&matlab); // lent en long
            //	montecarloThread(&matlab);
            //	montecarloStream(&matlab);
        }

        // vector
        {
        //	addvector(&matlab);
        //	addvectorBistream(&matlab);
        //	addvectorTristream(&matlab);
        }

    matlab.play();

    return EXIT_SUCCESS;
    }

// ---------------------------------
//  Private
// ---------------------------------

void sliceGMHOST(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    SliceProviderGMHOST provider;

    bruteforce(&provider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void sliceGM(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    SliceProviderGM provider;

        // brutefore: cas special dg et db power 2
        {
        const int WARP_SIZE = Hardware::getWarpSize();

        // dg
        Iterator iteratorDGx(WARP_SIZE, 1024, 2, Operator::MULTIPLY); // (min,max,step) // power 2

        // db
        Iterator iteratorDBx(WARP_SIZE, 1024, 2, Operator::MULTIPLY); // (min,max,step) // power 2

        // gridMaillage
        GridMaillage gridMaillage(iteratorDGx, iteratorDBx);

        BruteForce::run(&provider, &gridMaillage, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
        }
    }

void sliceSM(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    SliceProviderSM provider;

    bruteforceReduction(&provider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void sliceMulti(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    SliceProviderMulti provider;

    bruteforceReduction(&provider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void montecarloMono(Matlab *ptrMatlab)
    {
#ifdef DAR_INT
    const double DURATION_MAX_S = 0.9;
#endif

#ifdef DAR_LONG
    const double DURATION_MAX_S = 0.0009;
#endif

    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    MontecarloProvider provider;

    bruteforceReduction(&provider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void montecarloThread(Matlab *ptrMatlab)
    {
#ifdef DAR_INT
    const double DURATION_MAX_S = 0.9;
#endif

#ifdef DAR_LONG
    const double DURATION_MAX_S = 0.0009;
#endif

    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    MontecarloThreadProvider provider;

    bruteforceReduction(&provider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void montecarloStream(Matlab *ptrMatlab)
    {
#ifdef DAR_INT
    const double DURATION_MAX_S = 0.9;
#endif

#ifdef DAR_LONG
    const double DURATION_MAX_S = 0.0009;
#endif

    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    MontecarloStreamProvider provider;

    bruteforceReduction(&provider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void addvector(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    AddVectorProvider provider;

    bruteforce(&provider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

void addvectorBistream(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    AddVectorBistreamProvider provider;

    bruteforce(&provider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

// ---------------------------------
// Tristream
// ---------------------------------

/**
 * Selon le cas il faut changer la taille du vecteur dans VectorTools.cpp, VectorTools::n()
 * Why? On veut se simplifier la vie, et pourvoir avoir des slices de tranches égales
 */
void addvectorTristream(Matlab *ptrMatlab)
    {
    // addvectorTristream1a(ptrMatlab);
    addvectorTristream1b(ptrMatlab);
    // addvectorTristream2a(ptrMatlab);
    // addvectorTristream2b(ptrMatlab);

    // addvectorTristreamDebug(ptrMatlab);
    }

/**
 * cas 1.a : #slice : 3 4 5 6 7 8 9 10 11 12 13 14 15
 */
void addvectorTristream1a(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    for (int nbSlice = 3; nbSlice <= 15; nbSlice++) // hyper long
        {
        AddVectorTristreamProvider addVectorTristreamProvider(nbSlice);

        bruteforce(&addVectorTristreamProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
        }
    }
/**
 * cas 1.b : #slice in [5,75] par pas de 5
 */
void addvectorTristream1b(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    for (int nbSlice = 5; nbSlice <= 75; nbSlice += 5) // hyper long
        {
        AddVectorTristreamProvider addVectorTristreamProvider(nbSlice);

        bruteforce(&addVectorTristreamProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
        }
    }

/**
 * cas 2.a : #slice  : 10 20 30 40 50
 */
void addvectorTristream2a(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    for (int nbSlice = 10; nbSlice <= 50; nbSlice += 10) // hyper long
        {
        AddVectorTristreamProvider addVectorTristreamProvider(nbSlice);

        bruteforce(&addVectorTristreamProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
        }
    }

/**
 * cas 2.b : #slice  : 10 100 1000 10000 20000 30000 40000
 */
void addvectorTristream2b(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    const int N = 6;
    int tab[N];
    tab[0] = 10;
    tab[1] = 100;
    tab[2] = 1000;
    tab[3] = 10000;
    tab[4] = 20000;
    tab[5] = 30000;
    tab[6] = 40000;

    for (int i = 0; i < N; i++) // long
        {
        int nbSlice = tab[i];

        AddVectorTristreamProvider addVectorTristreamProvider(nbSlice);

        bruteforce(&addVectorTristreamProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
        }
    }

void addvectorTristreamDebug(Matlab *ptrMatlab)
    {
    const double DURATION_MAX_S = 0.9;
    const PlotType PLOT_TYPE = PlotType::ALL_GRAPHE;

    int nbSlice = 25; // 15 20 30 75 cas 1.b
    AddVectorTristreamProvider addVectorTristreamProvider(nbSlice);

    bruteforce(&addVectorTristreamProvider, ptrMatlab, PLOT_TYPE, DURATION_MAX_S);
    }

/*-----------------------------------*\
 |*		Tools	        	*|
 \*-----------------------------------*/

/**
 * db power2
 */
void bruteforceReduction(ProviderUse_I *ptrProviderUse, Matlab *ptrMatlab, const PlotType &plotType, double durationMaxS)
    {
    // Hardware
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();
    const int NB_THREAD_BLOCK_MAX = Hardware::getMaxThreadPerBlock();
    const int WARP_SIZE = Hardware::getWarpSize();

    // dg
    Iterator iteratorDGx(MP, 10 * MP, MP, Operator::ADD); // (min,max,step)

    // db
    //  Iterator iteratorDBx(WARP_SIZE, NB_THREAD_BLOCK_MAX, 2, Operator::MULTIPLY); // power2 (reduction)
    Iterator iteratorDBx(CORE_MP, NB_THREAD_BLOCK_MAX, 2, Operator::MULTIPLY); // power2 (reduction)

    // gridMaillage
    GridMaillage gridMaillage(iteratorDGx, iteratorDBx);

    BruteForce::run(ptrProviderUse, &gridMaillage, ptrMatlab, plotType, durationMaxS);
    }

void bruteforce(ProviderUse_I *ptrProviderUse, Matlab *ptrMatlab, const PlotType &plotType, double durationMaxS)
    {
    // Hardware
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();
    const int NB_THREAD_BLOCK_MAX = Hardware::getMaxThreadPerBlock();
    const int WARP_SIZE = Hardware::getWarpSize();

    // dg
    Iterator iteratorDGx(MP, 10 * MP, MP, Operator::ADD); // (min,max,step)

    // db
    Iterator iteratorDBx(CORE_MP, NB_THREAD_BLOCK_MAX, CORE_MP, Operator::ADD); // (min,max,step)

    // gridMaillage
    GridMaillage gridMaillage(iteratorDGx, iteratorDBx);

    BruteForce::run(ptrProviderUse, &gridMaillage, ptrMatlab, plotType, durationMaxS);
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
