#pragma once

#include "cudas.h"
#include <iostream>

#include "Animable_I.h"
#include "IteratorImageGray_I.h"
#include "Texture2D_GM.h"

using std::string;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class TutoTextureGM : public Animable_I<uchar>
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    TutoTextureGM(const Grid &gridDilatation, IteratorImageGray_I *ptrIteratorImage, uint seuil0255);
    virtual ~TutoTextureGM();

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
    // Inputs
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
    Texture2D_GM<uchar> texture2D_GM;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
