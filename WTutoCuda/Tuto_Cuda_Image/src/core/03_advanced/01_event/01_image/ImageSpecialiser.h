#pragma once

#include "ImageFromAnimable.h"

#include "MouseKeyListener.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

/**
 * see ImageAnimable_GPU.h
 *
 * 	ImageAnimable_RGBA_uchar4
 * 	ImageAnimable_HSBA_uchar4
 * 	...
 */
class ImageSpecialiser : public ImageAnimable_RGBA_uchar4
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    ImageSpecialiser(Animable_I<uchar4> *ptrAnimable, ColorRGB_01 titleColor);

    virtual ~ImageSpecialiser();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    /*-------------------------*\
    |*   Override Animable_I   *|
     \*------------------------*/

    /**
     * Call periodicly by the api
     * Override
     */
    virtual void paintPrimitives(Graphic2D &graphic2D);

  private:
    void listener(Animable_I<uchar4> *ptrAnimable);

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs

    // Tools
    MouseKeyListener *ptrMouseKeyListener;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
