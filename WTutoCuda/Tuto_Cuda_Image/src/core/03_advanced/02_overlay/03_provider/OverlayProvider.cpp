#include "OverlayProvider.h"

#include "ImageOverlay.h"
#include "Vague.h"

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

/**
 * Override
 */
Image_I *OverlayProvider::createImageGL()
    {
    ColorRGB_01 colorTexte = colorTitle();
    Animable_I<uchar4> *ptrAnimable = Provider_uchar4_A::createAnimable();

    const bool IS_V1 = false;

    if (IS_V1)
        {
        return new ImageOverlay(ptrAnimable, colorTexte);
        }
    else // v2
        {
        Vague *ptrVague = dynamic_cast<Vague *>(ptrAnimable);
        return new ImageOverlay(ptrVague, colorTexte); // la classe avec les event

        // INFO : cette approche permettrait de typer de maniere plus precise le constructeur de ImageOverlay:
        //
        // pour la v1 : on type avec Animable_I<uchar4>*
        //
        //	ImageOverlay(Animable_I<uchar4>* ptrAnimable ,ColorRGB_01 colorTexte);
        //
        // pour la v2  : on type avec TutoEvent*  (MIEUX)
        //
        //	ImageOverlay(Vague* ptrVague , ColorRGB_01 colorTexte);
        }
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
