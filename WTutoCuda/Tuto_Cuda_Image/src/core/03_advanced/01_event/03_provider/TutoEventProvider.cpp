#include "TutoEventProvider.h"
#include "ImageSpecialiser.h"
#include "TutoEvent.h"

#include "Hardware.h"

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

/**
 * Override
 */
Grid TutoEventProvider::grid()
    {
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    // disons a optimiser
    dim3 dg(MP, 1, 1);
    dim3 db(CORE_MP, 14, 1);
    Grid grid(dg, db);

    return grid;
    }

/**
 * Override
 */
Animable_I<uchar4> *TutoEventProvider::createAnimable(const Grid &grid, bool isVerbose)
    {
    // Animation;
    int dt = 1;

    // Dimension
    int w = 16 * 32 * 2;
    int h = 16 * 32;

    // Animable
    return new TutoEvent(grid, w, h, dt, isVerbose);
    }

/**
 * Override
 */
Image_I *TutoEventProvider::createImageGL()
    {
    // ColorRGB_01 titleColor(12,45,67);
    ColorRGB_01 colorTexte = colorTitle();

    Animable_I<uchar4> *ptrAnimable = Provider_uchar4_A::createAnimable();

    const bool IS_V1 = false;

    if (IS_V1)
        {
        return new ImageSpecialiser(ptrAnimable, colorTexte);
        }
    else // v2
        {
        TutoEvent *prtTutoEvent = dynamic_cast<TutoEvent *>(ptrAnimable);
        return new ImageSpecialiser(prtTutoEvent, colorTexte); // la classe avec les event

        // INFO : cette approche permettrait de typer de maniere plus precise le constructeur de ImageSpecialiser:
        //
        // pour la v1 : on type avec Animable_I<uchar4>*
        //
        //	ImageSpecialiser(Animable_I<uchar4>* ptrAnimable , ColorRGB_01 titleColor);
        //
        // pour la v2  : on type avec TutoEvent*  (MIEUX)
        //
        //	ImageSpecialiser(TutoEvent* prtTutoEvent , ColorRGB_01 titleColor);
        }
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
