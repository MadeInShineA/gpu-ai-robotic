#pragma once

#include "Grid.h"
#include "RunnableGPU.h"
#include "cuda_fp16.h"
#include "cudas.h"

// --------------------------------------------------------------------------------------
// Declaration
// --------------------------------------------------------------------------------------

class AddVector : public RunnableGPU
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    /**
     * update w by v1+v2
     */
    AddVector(const Grid &grid, int *ptrV1, int *ptrV2, int *ptrW, int n, bool isVerbose);

    virtual ~AddVector(void);

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
    virtual double getOutputGO();

    /**
     * override
     */
    virtual double getInputGO();

  private:
    std::string title();

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs
    int *ptrV1;
    int *ptrV2;
    int n;

    // Inputs/Outputs
    int *ptrW;

    // Tools
    int *ptrGMV1;
    int *ptrGMV2;
    int *ptrGMW;
    size_t sizeVector; //[octet]
    };

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
