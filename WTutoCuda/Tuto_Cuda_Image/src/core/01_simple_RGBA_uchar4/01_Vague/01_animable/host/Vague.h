#pragma once

#include "Maths.h"
#include "cudas.h"

#include "Animable_I.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class Vague : public Animable_I<uchar4>
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    Vague(const Grid &grid, uint w, uint h, int dt, bool isVerbose, std::string title = "Vague-Cuda-RGBA-uchar4");
    virtual ~Vague();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    /**
     * Call periodicly by the api
     */
    virtual void process(uchar4 *tabPixelsGM, uint w, uint h, const DomaineMath &domaineMath);

    /**
     * Call periodicly by the api
     */
    virtual void animationStep();

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs
    int dt;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
