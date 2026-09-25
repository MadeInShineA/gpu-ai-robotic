#pragma once

#include "MouseKeyListenerGlue_I.h"

#include "TutoEvent.h"

#include "KeyListener_I.h"
#include "MouseListener_I.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class MouseKeyListener : public MouseListener_I, public KeyListener_I
    {
  public:
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

    MouseKeyListener(MouseKeyListenerGlue_I *ptrAnimable);
    virtual ~MouseKeyListener();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    // ---------------------------------
    //  Mouse listener
    // ---------------------------------

    /**
     * Override
     */
    virtual void onMouseMoved(const MouseEvent &event);

    /**
     * Override
     */
    virtual void onMousePressed(const MouseEvent &event);

    /**
     * Override
     */
    virtual void onMouseReleased(const MouseEvent &event);

    /**
     * Override
     */
    virtual void onMouseWheel(const MouseWheelEvent &event);

    // ---------------------------------
    //  Key listener
    // ---------------------------------

    /**
     * Override
     */
    virtual void onKeyPressed(const KeyEvent &event);

    /**
     * Override
     */
    virtual void onKeyReleased(const KeyEvent &event);

  private:
    void printXY(const MouseEvent &event);

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs
    MouseKeyListenerGlue_I *ptrAnimable;
    TutoEvent *ptrTutoEvent;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
