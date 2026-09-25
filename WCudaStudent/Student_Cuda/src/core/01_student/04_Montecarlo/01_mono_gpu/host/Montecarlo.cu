#include "Montecarlo.h"

#include <assert.h>
#include <iostream>
#include <math.h>
#include <typeinfo>

#include "GM.h"
#include "Hardware.h"
#include "Stream.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;

using montecarlo::entier;
using montecarlo::entierToString;

// --------------------------------------------------------------------------------------
//  Externs
// --------------------------------------------------------------------------------------

extern __global__ void createGenerator(curandState *tabGeneratorGM, int deviceId);

extern __global__ void kmontecarlo(curandState *tabGeneratorGM, entier nbDarByThread, entier *ptrNbDarUnderGM, float h);

// --------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------

Montecarlo::Montecarlo(const Grid &grid, entier nbDarTotalAsk, double *ptrPiHat, float h, bool isVerbose)
    : RunnableGPU(grid, title(nbDarTotalAsk, h), isVerbose), // classe parente
                                                             //
      nbDarTotalAsk(nbDarTotalAsk),                          //
      ptrPiHat(ptrPiHat),                                    //
      h(h)                                                   //

    {
    const entier NB_THREAD = grid.threadCounts(); // directement en entier pour éviter un cast

        // Math : Calculer le nombre de flechette effectivment tirer!
        {
        this->nbDarByThread = (nbDarTotalAsk / NB_THREAD);
        this->nbDarTotalEffective = NB_THREAD * nbDarByThread;

        assert(nbDarTotalAsk >= grid.threadCounts());
        assert(nbDarByThread > 0); // si =0, trop de threads et pas assez de dar!
        }

        // MM
        {
        this->sizeNbDarUnderGM = -1; // [octet]

        // TODO Montecarlo  NbDarUnderGM (pas oublier de mettre a zero, avec un malloc0 par exemple)

        this->sizeSM = -1; // [octet]
        }

        // init : lancer le kernel de creation des generators
        {
        size_t sizeTabDevGeneratorGM = -1; // TODO Montecarlo

        // TODO Montecarlo  pou  tabDevGeneratorGM

        // TODO Montecarlo lancer le kernel createGenerator
        int deviceId = Hardware::getDeviceId();
        }
    }

Montecarlo::~Montecarlo(void)
    {
    // TODO Montecarlo
    }

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

/**
 * Lancer kernel
 * Recuperer resultat coter host
 * Finaliser le calcul de pi
 */
void Montecarlo::run()
    {
        // Version :  mono pure
        {
            // TODO Montecarlo
        }

        // Version : compatible with multiGPU, stream-version
        {
        // rien pour version mono pure
        // puis des la version MontecarloMulti-stream
        // commenter la version ci-dessus, et utiliser :
        //	- kernel_async
        //	- DtoH_async
        //	- Stream::synchronize(0);
        // Valider cette npuvelle version, d'abord en reexecutamt une Montecarlo(Mono)
        // TODO Montecarlo MontecarloMulti-stream
        }

    // calcule de Math
    // TODO Montecarlo
    }

// ---------------------------------
// helper multiGPU
// ---------------------------------

/**
 * usefull for multiGPU, stream version
 * assynchrone
 */
void Montecarlo::kernel_async(cudaStream_t cudaStream)
    {
    kmontecarlo<<<dg, db, sizeSM, cudaStream>>>(tabDevGeneratorGM, nbDarByThread, ptrNbDarUnderGM, h);
    }

/**
 * usefull for multiGPU, stream version
 * assynchrone
 */
void Montecarlo::DtoH_async(cudaStream_t cudaStream)
    {
    GM::memcpyAsyncDToH(&nbDarUnderCurve, ptrNbDarUnderGM, sizeNbDarUnderGM, cudaStream);
    }

// ---------------------------------
// get
// ---------------------------------

entier Montecarlo::getNbDarTotalEffective()
    {
    return nbDarTotalEffective;
    }

entier Montecarlo::getNbDarUnderCurve()
    {
    return nbDarUnderCurve;
    }

double Montecarlo::getInputGO()
    {
    return (nbDarTotalEffective / (double)1024 / (double)1024 / (double)1024) * sizeof(float) * 2;
    }

// ---------------------------------
// Private
// ---------------------------------

/**
 * static
 */
string Montecarlo::title(entier nbDarTotalAsk, float h)
    {
    return "Montecarlo_" + entierToString() + "_" + to_string(nbDarTotalAsk) + "_h" + to_string((int)h);
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
