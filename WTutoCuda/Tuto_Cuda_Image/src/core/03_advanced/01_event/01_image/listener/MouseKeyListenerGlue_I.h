#pragma once

#include "KeyListener_I.h"
#include "MouseListener_I.h"

#include "KeyEvent.h"
#include "MouseEvent.h"
#include "MouseWheelEvent.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

// class MouseKeyListenerGlue_I
class MouseKeyListenerGlue_I : public MouseListener_I, public KeyListener_I // posait problem
    {

    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    MouseKeyListenerGlue_I()
        {
        // rien
        }

    virtual ~MouseKeyListenerGlue_I()
        {
        // rien
        }

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

    // ---------------------------------
    //  Mouse listener
    // ---------------------------------

  public:
    /**
     * Override
     */
    virtual void onMouseMoved(const MouseEvent &event) = 0;

    /**
     * Override
     */
    virtual void onMousePressed(const MouseEvent &event) = 0;

    /**
     * Override
     */
    virtual void onMouseReleased(const MouseEvent &event) = 0;

    /**
     * Override
     */
    virtual void onMouseWheel(const MouseWheelEvent &event) = 0;

    // ---------------------------------
    //  Key listener
    // ---------------------------------

    /**
     * Override
     */
    virtual void onKeyPressed(const KeyEvent &event) = 0;

    /**
     * Override
     */
    virtual void onKeyReleased(const KeyEvent &event) = 0;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
