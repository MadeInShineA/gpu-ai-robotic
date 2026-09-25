#include "GM.h"
#include "Mandelbrot.h"

#include <assert.h>
#include <iostream>

#include "Hardware.h"

#include "real_mandelbrot.h"

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Extern
// --------------------------------------------------------------------------------------

extern __global__ void mandelbrot(uchar4 *tabPixelsGM, uint w, uint h, DomaineMath domaineMath, int n);

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

static string titre(int nMin, int nMax);

// --------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------

Mandelbrot::Mandelbrot(const Grid &grid, uint w, uint h, const DomaineMath &domaineMath, bool isVerbose, int nMin, int nMax)
    : Animable_I<uchar4>(grid, w, h, titre(nMin, nMax), domaineMath, isVerbose), // super classe
      variateurT(Interval<int>(nMin, nMax), 1),                                  // tools animation
      nMin(nMin),                                                                // Inputs animation
      nMax(nMax)                                                                 // Inputs animation
    {
    // Tools
    this->t = nMin;
    }

Mandelbrot::~Mandelbrot()
    {
    // rien
    }

// --------------------------------------------------------------------------------------
// Override
// --------------------------------------------------------------------------------------

/**
 * Override
 * Call periodicly by the API
 */
void Mandelbrot::process(uchar4 *tabPixelsGM, uint w, uint h, const DomaineMath &domaineMath)
    {
    int n = this->t; // t protected dans la classe parente, t parametre d'animation, que l'on renomme ici en n

    assert(false); // to be removed once implemented
    // TODO Mandelbrot
    // lauch kernel (you find at line 18)
    }

/**
 * Override
 * Call periodicly by the API
 */
void Mandelbrot::animationStep()
    {
    this->t = variateurT.varierAndGet();
    }

// ---------------------------------
// Private
// ---------------------------------

string titre(int nMin, int nMax)
    {
    return "Mandelbrot-Cuda-uchar4-" + mandelbrotReal::realToString() + "-nMin" + std::to_string(nMin) + "-nMax" + std::to_string(nMax);
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
