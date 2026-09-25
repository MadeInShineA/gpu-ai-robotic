#pragma once

#include <curand_kernel.h>

#include "Grid.h"
#include "RunnableGPU.h"
#include "cudas.h"
#include "entier_montecarlo.h"

// --------------------------------------------------------------------------------------
// Declaration
// --------------------------------------------------------------------------------------

class Montecarlo : public RunnableGPU
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    /**
     * Hyp : db power 2
     */
    Montecarlo(const Grid &grid, montecarlo::entier nbDarTotalAsk, double *ptrPiHat, float h, bool isVerbose);

    virtual ~Montecarlo(void);

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    /**
     * override
     */
    virtual void run();

    /**
     * override
     */
    virtual double getInputGO();

    /**
     * #dar effectivement tirer, !=nbDarTotalAsk car division entiere
     */
    montecarlo::entier getNbDarTotalEffective();

    montecarlo::entier getNbDarUnderCurve();

    /*----------------------*\
    |* helper multiGPU-stream*|
     \*---------------------*/

    /**
     * usefull for multiGPU, stream version
     * assynchrone
     */
    void kernel_async(cudaStream_t cudaStream = 0);

    /**
     * usefull for multiGPU, stream version
     * assynchrone
     */
    void DtoH_async(cudaStream_t cudaStream = 0);

  private:
    /**
     * tools
     */
    static std::string title(montecarlo::entier nbDarTotalAsk, float h);

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs
    montecarlo::entier nbDarTotalAsk;
    float h; // hauteur de la cible

    // Inputs/Outputs
    double *ptrPiHat;

    // Outputs
    montecarlo::entier nbDarTotalEffective;
    montecarlo::entier nbDarUnderCurve;

    // Tools
    montecarlo::entier *ptrNbDarUnderGM;
    size_t sizeNbDarUnderGM;
    size_t sizeSM;

    curandState *tabDevGeneratorGM;

    montecarlo::entier nbDarByThread;
    };

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
