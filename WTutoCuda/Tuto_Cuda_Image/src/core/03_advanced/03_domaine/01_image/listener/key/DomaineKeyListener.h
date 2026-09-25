#pragma once

#include "KeyListener_I.h"

#include "DomaineMath.h"
#include "Image_GPU.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class DomaineKeyListener : public KeyListener_I
    {
  public:
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

    DomaineKeyListener(Image_RGBA_uchar4 *ptrImage);

    virtual ~DomaineKeyListener();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    /**
     * Override
     */
    virtual void onKeyPressed(const KeyEvent &event);

    /**
     * Override
     */
    void onKeyReleased(const KeyEvent &event);

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs
    Image_RGBA_uchar4 *ptrImage;

    // Tools
    DomaineMath domaine1;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
