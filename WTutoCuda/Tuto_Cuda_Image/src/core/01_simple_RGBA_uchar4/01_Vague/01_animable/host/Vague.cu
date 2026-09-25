#include "Vague.h"

#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// ---------------------------------------------------------------------------
// Extern
// ---------------------------------------------------------------------------

extern __global__ void vague(uchar4 *tabPixelsGM, uint w, uint h, int t);

// ---------------------------------------------------------------------------
// Constructors
// ---------------------------------------------------------------------------

Vague::Vague(const Grid &grid, uint w, uint h, int dt, bool isVerbose, string title)
    : Animable_I<uchar4>(grid, w, h, title, isVerbose), //
      dt(dt)
    {
    // Tools
    this->t = 0; // protected dans Animable
    }

Vague::~Vague()
    {
    // rien
    }

// ---------------------------------------------------------------------------
// Methodes
// ---------------------------------------------------------------------------

/**
 * Override
 * Call periodicly by the API
 *
 * Note : domaineMath pas use car pas zoomable
 */
void Vague::process(uchar4 *tabPixelsGM, uint w, uint h, const DomaineMath &domaineMath)
    {
    vague<<<dg, db>>>(tabPixelsGM, w, h, t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void Vague::animationStep()
    {
    t += dt;
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
