#include <iostream>

#include "Args.h"
#include "GLUTWindowManagers.h"

#include "DamierWindow.h"
#include "VagueWindow.h"

using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

void mainCore(const Args &args)
    {
    GLUTWindowManagers::init(args.argc, args.argv);

    // RENDER_MODE_FILL RENDER_MODE_LINE RENDER_MODE_POINT
    VagueWindow vague(RenderMode::RENDER_MODE_FILL);
    // DamierWindow damier(RenderMode::RENDER_MODE_FILL);

    // Info
    cout << "\nTourner-Zoomer\n" << endl;

    // Run
    GLUTWindowManagers::getInstance()->runALL(); // bloquant
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
