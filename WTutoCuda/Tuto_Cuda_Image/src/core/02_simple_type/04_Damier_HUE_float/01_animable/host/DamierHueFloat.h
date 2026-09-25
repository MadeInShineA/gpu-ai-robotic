#pragma once

#include "Maths.h"
#include "cudas.h"

#include "Animable_I.h"
#include "Variateur.cu.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class DamierHueFloat : public Animable_I<float>
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    DamierHueFloat(const Grid &grid, uint w, uint h, float dt, uint n, const DomaineMath &domaineMath, bool isVerbose);
    virtual ~DamierHueFloat();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    /**
     * Call periodicly by the api
     */
    virtual void process(float *tabPixelsGM, uint w, uint h, const DomaineMath &domaineMath);

    /**
     * Call periodicly by the api
     */
    virtual void animationStep();

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs
    uint n;

    // Tools
    Variateur<float> variateurAnimation;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
