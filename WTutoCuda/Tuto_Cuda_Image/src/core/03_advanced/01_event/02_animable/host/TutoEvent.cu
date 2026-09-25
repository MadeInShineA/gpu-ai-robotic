#include "TutoEvent.h"

#include <assert.h>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// ---------------------------------------------------------------------------
// Extern
// ---------------------------------------------------------------------------

extern __global__ void tutoEvent(uchar4 *tabPixelsGM, uint w, uint h, int t);

// --------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------

TutoEvent::TutoEvent(const Grid &grid, uint w, uint h, int dt, bool isVerbose, string title)
    : Animable_I<uchar4>(grid, w, h, title, isVerbose), //
      dt(dt)
    {
    // Tools
    this->t = 0; // protected dans Animable
    }

TutoEvent::~TutoEvent()
    {
    // rien
    }

// ---------------------------------------------------------------------------
// Methodes
// ---------------------------------------------------------------------------

/**
 * Override
 * Call periodicly by the API
 *
 * Note : domaineMath pas use car pas zoomable
 */
void TutoEvent::process(uchar4 *tabPixelsGM, uint w, uint h, const DomaineMath &domaineMath)
    {
    tutoEvent<<<dg, db>>>(tabPixelsGM, w, h, t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void TutoEvent::animationStep()
    {
    t += dt;
    }

// ---------------------------------
//   key listener
// ---------------------------------

/**
 * Override
 */
void TutoEvent::onKeyPressed(const KeyEvent &event)
    {
    if (event.isSpecial())
        {
        cout << "[Special Key Pressed] = " << event.getSpecialKey() << endl;
        }
    else
        {
        cout << "[KeyPressed] = " << event.getKey() << endl;
        }
    }

/**
 * Override
 */
void TutoEvent::onKeyReleased(const KeyEvent &event)
    {
    if (event.isSpecial())
        {
        cout << "[Special Key Released] = " << event.getSpecialKey() << endl;
        }
    else
        {
        cout << "[KeyReleased] = " << event.getKey() << endl;
        }
    }

// ---------------------------------
//   Mouse listener
// ---------------------------------

void TutoEvent::onMouseMoved(const MouseEvent &event)
    {
    cout << "[MouseMoved] : ";
    printXY(event);
    }

void TutoEvent::onMousePressed(const MouseEvent &event)
    {
    cout << "\n[MousePressed]  :  button=" << event.getButtonType() << " : " << endl;
    printXY(event);
    }

void TutoEvent::onMouseReleased(const MouseEvent &event)
    {
    cout << "[MouseReleased] :  button=" << event.getButtonType() << " : ";
    printXY(event);
    }

void TutoEvent::onMouseWheel(const MouseWheelEvent &event)
    {
    cout << "[MouseWheel]    :  direction=" << event.getDirection() << " : ";
    printXY(event);
    }

/**
 * (x,y) : coordonnee image, et non frame!
 */
void TutoEvent::printXY(const MouseEvent &event)
    {
    cout << " at pixel (x,y) = (" << event.getX() << "," << event.getY() << ")" << endl;
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
