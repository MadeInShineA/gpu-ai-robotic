#pragma once

#include "Maths.h"
#include "cudas.h"

#include "Animable_I.h"
#include "Variateur.cu.h"

// ---------------------------------------------------------------------------
// Declaration
// ---------------------------------------------------------------------------

class Mandelbrot : public Animable_I<uchar4>
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    Mandelbrot(const Grid &grid, uint w, uint h, const DomaineMath &domaineMath, bool isVerbose, int nMin, int nMax);
    virtual ~Mandelbrot(void);

    // ---------------------------------------------------------------------------
    // Override
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
    int nMin;
    int nMax;

    // Tools
    Variateur<int> variateurT;
    };

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
