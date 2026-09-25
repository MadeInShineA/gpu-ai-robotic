#include "ImageSpecialiser.h"

#include <iostream>

#include "MouseKeyListenerGlue_I.h"

using std::cout;
using std::endl;
using std::string;

// --------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------

ImageSpecialiser::ImageSpecialiser(Animable_I<uchar4> *ptrAnimable, ColorRGB_01 colorTexte)
    :                                                    //
      ImageAnimable_RGBA_uchar4(ptrAnimable, colorTexte) //
    {
    // Tools
    listener(ptrAnimable);
    }

ImageSpecialiser::~ImageSpecialiser()
    {
    delete ptrMouseKeyListener;
    }

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

/**
 * Override
 * call periodicly by the api
 */
void ImageSpecialiser::paintPrimitives(Graphic2D &graphic2D)
    {
    ImageAnimable_RGBA_uchar4::paintPrimitives(graphic2D);

    float r = 0;
    float g = 0;
    float b = 1;
    graphic2D.setColorRGB(r, g, b);
    graphic2D.setFont(TIMES_ROMAN_24);

        // Top
        {
        float t = getAnimable()->getAnimationPara();

        string title = getAnimable()->getTitle();

        graphic2D.drawTitleBottom(title);
        }

        // Bottom
        {
        graphic2D.drawTitleTop("Advanced : Click on the windows, and look message in the console");
        }
    }

// ---------------------------------
//  Private
// ---------------------------------

#include "TutoEvent.h"

void ImageSpecialiser::listener(Animable_I<uchar4> *ptrAnimable)
    {
    MouseKeyListenerGlue_I *ptrMouseKeyListenerGlue = (MouseKeyListenerGlue_I *)ptrAnimable;

    this->ptrMouseKeyListener = new MouseKeyListener(ptrMouseKeyListenerGlue);

    setKeyListener((KeyListener_I *)ptrMouseKeyListener);
    setMouseListener((MouseListener_I *)ptrMouseKeyListener);
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
