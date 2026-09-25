#include "DomaineProvider.h"
#include "DamierProvider.h"

#include "Damier.h"

#include "ImageCustomDomaine.h"

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

/**
 * Override
 */
Image_I *DomaineProvider::createImageGL()
    {
    ColorRGB_01 colorTexte = colorTitle();

    Animable_I<uchar4> *ptrAnimable = Provider_uchar4_A::createAnimable();

    const bool IS_V1 = false;

    if (IS_V1)
        {
        return new ImageCustomDomaine(ptrAnimable, colorTexte);
        }
    else // v2
        {
        Damier *prtDamier = dynamic_cast<Damier *>(ptrAnimable);
        return new ImageCustomDomaine(prtDamier, colorTexte); // la classe avec les event

        // INFO : cette approche permettrait de typer de maniere plus precise le constructeur de ImageCustomDomaine:
        //
        // pour la v1 : on type avec Animable_I<uchar4>*
        //
        //	ImageCustomDomaine(Animable_I<uchar4>* ptrAnimable , ColorRGB_01 titleColor);
        //
        // pour la v2  : on type avec TutoEvent*  (MIEUX)
        //
        //	ImageCustomDomaine(Damier* prtDamier , ColorRGB_01 titleColor);
        }
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
