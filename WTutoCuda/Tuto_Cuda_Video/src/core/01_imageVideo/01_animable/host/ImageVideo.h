#pragma once

#include "Maths.h"
#include "cudas.h"
#include <iostream>

#include "VideoProviderRGB.h"

#include "Animable_I.h"

using std::string;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class ImageVideo : public Animable_I<uchar4>
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    ImageVideo(const Grid &grid, uint w, uint h, string nameVideo, int nbImage);
    virtual ~ImageVideo();

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
    // Tools
    size_t sizeImage;
    VideoProviderRGB videoProviderRGB;
    uchar4 *ptrTabPixelVideo;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
