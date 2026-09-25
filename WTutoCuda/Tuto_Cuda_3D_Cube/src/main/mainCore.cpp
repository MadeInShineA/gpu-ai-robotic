#include <iostream>

#include "Args.h"
#include "GLUTWindowManagers.h"
#include "GLUTWindowScene.h"

#include "SceneCubeCreator.h"

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

void mainCore(const Args &args)
    {
    GLUTWindowManagers::init(args.argc, args.argv);

    SceneCubeCreator sceneCubeCreator;
    SceneCube *ptrScene = sceneCubeCreator.getScene();

    int w = 16 * 32 * 2;

    GLUTWindowScene window(ptrScene, "Tuto Cube 3D", w, w, 60, 60); // (w,h, px,py)

    cout << "\nTourner-Zoomer\n" << endl;

    GLUTWindowManagers::getInstance()->runALL(); // bloquant
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
