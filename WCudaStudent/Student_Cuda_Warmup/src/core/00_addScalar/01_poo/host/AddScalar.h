#pragma once

#include "Grid.h"
#include "cudas.h"

/**
 * On passse la grille à AddScalar pour pouvoir facilement la faire varier de l'extérieur pour trouver l'optimum, ou faire des tests avec des grilles
 * différentes
 */
class AddScalar
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    /**
     * ptrSum receptionne le resultat a+b
     */
    AddScalar(float a, float b, float *ptrSum);

    virtual ~AddScalar();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    void run();

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs
    float a;
    float b;

    // Inputs/Outputs
    float *ptrSum;

    // Tools
    float *ptrSumGM;
    size_t sizeFloat;
    };

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
