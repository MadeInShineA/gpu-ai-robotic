#include "MouseKeyListener.h"

#include <iostream>

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------

MouseKeyListener::MouseKeyListener(MouseKeyListenerGlue_I *ptrAnimable)
    :                           //
      ptrAnimable(ptrAnimable), //
      ptrTutoEvent((TutoEvent *)((Animable_I<uchar4> *)ptrAnimable))
    {
    // rien
    }

MouseKeyListener::~MouseKeyListener()
    {
    // rien
    }

// ---------------------------------
//  Mouse listener
// ---------------------------------

void MouseKeyListener::onMouseMoved(const MouseEvent &event)
    {
    //    cout << "[MouseMoved] : ";
    //    printXY(event);

    this->ptrTutoEvent->onMouseMoved(event);
    }

void MouseKeyListener::onMousePressed(const MouseEvent &event)
    {
    //    cout << "[MousePressed4]  :  button=" << event.getButtonType() << " : ";
    //    printXY(event);

    //  this->ptrAnimable->onMousePressed(event); // marche pas, strange
    this->ptrTutoEvent->onMousePressed(event);
    }

void MouseKeyListener::onMouseReleased(const MouseEvent &event)
    {
    //    cout << "[MouseReleased] :  button=" << event.getButtonType() << " : ";
    //    printXY(event);

    this->ptrTutoEvent->onMouseReleased(event);
    }

void MouseKeyListener::onMouseWheel(const MouseWheelEvent &event)
    {
    //    cout << "[MouseWheel]    :  direction=" << event.getDirection() << " : ";
    //    printXY(event);

    this->ptrTutoEvent->onMouseWheel(event);
    }

// ---------------------------------
//  Key listener
// ---------------------------------

void MouseKeyListener::onKeyPressed(const KeyEvent &event)
    {
    //    if (event.isSpecial())
    //	{
    //	cout << "Special Key Pressed " << event.getSpecialKey() << endl;
    //	}
    //    else
    //	{
    //	cout << "KeyPressed = " << event.getKey() << endl;
    //	}

    this->ptrAnimable->onKeyPressed(event);
    }

void MouseKeyListener::onKeyReleased(const KeyEvent &event)
    {
    //    if (event.isSpecial())
    //	{
    //	cout << "Special Key Released " << event.getSpecialKey() << endl;
    //	}
    //    else
    //	{
    //	cout << "KeyReleased = " << event.getKey() << endl;
    //	}

    this->ptrAnimable->onKeyReleased(event);
    }

// ---------------------------------
//  Private
// ---------------------------------

/**
 * (x,y) : coordonnee image, et non frame!
 */
void MouseKeyListener::printXY(const MouseEvent &event)
    {
    cout << " at pixel (x,y) = (" << event.getX() << "," << event.getY() << ")" << endl;
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
