#pragma once

#include "Animable_I.h"
#include "cudas.h"

#include "Sphere.h"
#include "memoryType.h"

// ---------------------------------------------------------------------------
// Declaration
// ---------------------------------------------------------------------------
class Raytracing : public Animable_I<uchar4>
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    Raytracing(const Grid &grid, uint w, uint h, float dt, bool isVerbose, int nbSpheres, MemoryType memoryType);
    virtual ~Raytracing(void);

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

    /**
     * Override
     */
    virtual double getInputGO();

  private:
    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

    void uploadToDevice(Sphere *tabSpheres);

  private:
    // Inputs
    int nbSpheres;
    float dt; // animation

    // Tools
    size_t sizeSpheres;
    Sphere *tabSpheresGM;
    MemoryType memoryType;
    };

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
