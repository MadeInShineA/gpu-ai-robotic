#pragma once

#include "Color3f.h"
#include "Graphic2D.h"
#include "Line2D.h"
#include "Rect2D.h"
#include "Text2D.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class ExampleDrawer2D
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    ExampleDrawer2D(int w, int h);

    virtual ~ExampleDrawer2D();

    // ---------------------------------------------------------------------------
    // Methodes
    // ---------------------------------------------------------------------------

  public:
    void drawNonObjet(Graphic2D &graphic2D);
    void drawObjet(Graphic2D &graphic2D);

  private:
    void drawGreenRect(Graphic2D &graphic2D);
    void drawWiredRect(Graphic2D &graphic2D);
    void drawRedHorizontalLine(Graphic2D &graphic2D);
    void drawBlueVerticalLine(Graphic2D &graphic2D);
    void drawOrangeTexte(Graphic2D &graphic2D);
    void drawLineTriangle(Graphic2D &graphic2D);
    void drawTexteTopRight(Graphic2D &graphic2D);

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------

  private:
    // Inputs
    int w;
    int h;

    // Tools

    Rect2D *ptrRect2D;
    Line2D *ptrLine2D;
    Text2D *ptrText2D;
    };

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
