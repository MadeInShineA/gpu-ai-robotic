#pragma once

#include "cudas.h"
#include <iostream>

#include "IteratorImageGray_I.h"

#include "Animable_I.h"

using std::string;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class Warmup : public Animable_I<uchar>
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    Warmup(const Grid &gridDilatation, IteratorImageGray_I *ptrIteratorImage, uint seuil0255);
    virtual ~Warmup();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    /**
     * Call periodicly by the api
     */
    virtual void process(uchar *tabPixelsGM, uint w, uint h, const DomaineMath &domaineMath);

    /**
     * Call periodicly by the api
     */
    virtual void animationStep();

  public:
    static Grid bestGridSeuillage();

  private:
    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inpus
    Grid gridSeuillage;
    Grid gridDilatation;
    uint seuil0255;

    // Tools
    IteratorImageGray_I *ptrIteratorImage;
    int wh;
    size_t sizeImage;

    // Tools image
    uchar *tabPixelVideo;
    uchar *tabPixelSeuillerGM;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
