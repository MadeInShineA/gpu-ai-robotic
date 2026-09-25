#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Args.h"
#include "Videos.h"
#include "Viewer.h"
#include "cudas.h"

#include "TutoSurfaceProvider.h"
#include "TutoTextureCuarrayProvider.h"
#include "TutoTextureGMProvider.h"
#include "WarmupProvider.h"

using std::cout;
using std::endl;
using std::string;

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

int mainImage(const Args &args)
    {
    cout << "\n[Image] mode" << endl;

    gpu::GLUTImageViewers::init(args.argc, args.argv); // only once

    // Videos::preloadONE(); // une image only de chacune des videos (utile en debug)
    Videos::preloadALL();

    // ImageOption : (boolean,boolean) : (isSelection ,isAnimation)
    ImageOption zoomable(true);
    ImageOption nozoomable(false);

    Viewer<WarmupProvider> warmup(nozoomable, 0, 0); // imageOption px py
    Viewer<TutoTextureGMProvider> tutoTextureGM(nozoomable, 25, 25);
    Viewer<TutoTextureCuarrayProvider> tutoTextureCuarray(nozoomable, 50, 50);
    Viewer<TutoSurfaceProvider> tutoSurface(nozoomable, 75, 75);

    // Common
    gpu::GLUTImageViewers::runALL(); // Bloquant, Tant qu'une fenetre est ouverte

    cout << "\n[Image] end" << endl;

    return EXIT_SUCCESS;
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
