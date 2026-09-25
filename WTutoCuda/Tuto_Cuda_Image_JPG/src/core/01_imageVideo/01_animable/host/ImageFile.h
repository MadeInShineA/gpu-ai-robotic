#pragma once

#include "cudas.h"
#include <iostream>

#include "Image.h"

#include "Animable_I.h"

using std::string;

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class ImageFile : public Animable_I<uchar4>
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    ImageFile(const Grid &grid, Image &image);
    virtual ~ImageFile();

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
    // Image
    Image image;

    // Tools
    size_t sizeImage;
    uchar4 *ptrTabPixelImage;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
