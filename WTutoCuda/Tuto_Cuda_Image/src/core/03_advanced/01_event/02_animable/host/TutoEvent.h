#pragma once

#include "Maths.h"
#include "cudas.h"

#include "Animable_I.h"

#include "MouseKeyListenerGlue_I.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class TutoEvent : public Animable_I<uchar4>, public MouseKeyListenerGlue_I
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    TutoEvent(const Grid &grid, uint w, uint h, int dt, bool isVerbose, std::string title = "Event-Cuda-RGBA-uchar4");
    virtual ~TutoEvent();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    // ---------------------------------
    //   Override Animable_I
    // ---------------------------------

    /**
     * Call periodicly by the api
     */
    virtual void process(uchar4 *tabPixelsGM, uint w, uint h, const DomaineMath &domaineMath);

    /**
     * Call periodicly by the api
     */
    virtual void animationStep();

    // ---------------------------------
    //   Key listener
    // ---------------------------------

    /**
     * Override
     */
    virtual void onKeyPressed(const KeyEvent &event);

    /**
     * Override
     */
    virtual void onKeyReleased(const KeyEvent &event);

    // ---------------------------------
    //   Mouse listener
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

  private:
    void printXY(const MouseEvent &event);

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs
    int dt;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
