#pragma once

#include "cudas.h"
#include <iostream>

#include "Animable_I.h"
#include "IteratorImageGray_I.h"
#include "Texture2D.h"

using std::string;

// --------------------------------------------------------------------------------------
//  Declarations
// --------------------------------------------------------------------------------------

class VideoTextureCuarray : public Animable_I<uchar>
    {
    // --------------------------------------------------------------------------------------
    // Constructors
    // --------------------------------------------------------------------------------------

  public:
    VideoTextureCuarray(const Grid &grid, IteratorImageGray_I *ptrIteratorImage);
    virtual ~VideoTextureCuarray();

    // --------------------------------------------------------------------------------------
    // Override
    // --------------------------------------------------------------------------------------

  public:
    /**
     * Call periodicly by the api
     */
    virtual void process(uchar *tabPixelsGM, uint w, uint h, const DomaineMath &domaineMath);

    /**
     * Call periodicly by the api
     */
    virtual void animationStep();

    // --------------------------------------------------------------------------------------
    // Attributes
    // --------------------------------------------------------------------------------------

  private:
    // Tools
    IteratorImageGray_I *ptrIteratorImage;
    uchar *tabPixelVideo;

    // Tools : texture
    Texture2D<uchar> texture2DVideo;
    };

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
