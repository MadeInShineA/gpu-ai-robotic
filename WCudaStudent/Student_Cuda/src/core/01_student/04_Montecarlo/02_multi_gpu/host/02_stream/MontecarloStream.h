#pragma once

#include <curand_kernel.h>

#include "Grid.h"
#include "Montecarlo.h"
#include "RunnableGPU.h"
#include "cudas.h"
#include "entier_montecarlo.h"

// --------------------------------------------------------------------------------------
// Declaration
// --------------------------------------------------------------------------------------

class MontecarloStream : public RunnableGPU
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    /**
     * update piHat
     * Hyp : nbThread est une puissance de 2
     */
    MontecarloStream(const Grid &grid, montecarlo::entier nbDarTotalAsk, double *ptrPiHat, float h, bool isVerbose);

    virtual ~MontecarloStream(void);

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
     * #dar effectivement tirer
     */
    montecarlo::entier getNbDarTotalEffective();

    void setH(float h);

  private:
    std::string title(montecarlo::entier nbDarTotalAsk, float h);

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs
    montecarlo::entier nbDarTotalAsk;
    float h;

    // Inputs/Outputs
    double *ptrPiHat;

    // Tools
    montecarlo::entier nbDarTotalEffective;

    montecarlo::entier nbDarByDevice;
    Grid grid;

    // Toosl : multigpu
    cudaStream_t *tabStream;
    Montecarlo **tabMontecarlo;

    static int NB_DEVICE;
    };

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
