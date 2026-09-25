#pragma once

#include "ExampleDrawer2D.h"
#include "ImageFromAnimable.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

/**
 * Ne pas confondre avec Animable<> qui ne contient que le model
 * Ici ImageAnimable_RGBA_uchar4 est une classe de type vue. Elle doit etre instancier dans le provider
 *
 * ImageOverlay : à instancier dans OverlayProvider dans
 *
 * 	Image_I* OverlayProvider::createImageGL()
 *
 * Alors que Animable s'instancie dans l'autre methode
 *
 * 	virtual Animable_I<uchar4>* createAnimable();
 *
 * du OverlayProvider
 *
 * Pour d'autres types, see ImageAnimable_GPU.h
 *
 * 	ImageAnimable_RGBA_uchar4
 * 	ImageAnimable_HSBA_uchar4
 * 	...
 */
class ImageOverlay : public ImageAnimable_RGBA_uchar4
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    ImageOverlay(Animable_I<uchar4> *ptrAnimable, ColorRGB_01 titleColor);

    virtual ~ImageOverlay();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    /**
     * Call periodicly by the api
     * Override
     */
    virtual void paintPrimitives(Graphic2D &graphic2D);

  private:
    void exampleDirecte(Graphic2D &graphic2D);
    void exampleIndirecte(Graphic2D &graphic2D);

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs

    // Tools
    ExampleDrawer2D *ptrExampleDrawer2D;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
