#pragma once

#include "GLUTWindowScene.h"
#include "SurfaceSceneStrip.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

class MandelbrotWindow
    {
    // ---------------------------------------------------------------------------
    // Constructors
    // ---------------------------------------------------------------------------

  public:
    /**
     * <pre>
     * RenderMode:
     * 		- RENDER_MODE_FILL
     * 		- RENDER_MODE_LINE
     * 		- RENDER_MODE_POINT
     * </pre>
     */
    MandelbrotWindow(RenderMode renderMode = RenderMode::RENDER_MODE_FILL);

    virtual ~MandelbrotWindow();

    // ---------------------------------------------------------------------------
    // Attributes
    // ---------------------------------------------------------------------------
  private:
    // Inputs
    RenderMode renderMode;

    // Tools
    SurfaceStrip_I *ptrSurfaceStrip;
    SurfaceSceneStrip *ptrScene;
    GLUTWindowScene *prtWindow;
    };

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
