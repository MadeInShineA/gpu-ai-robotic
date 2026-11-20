#include "Thread1D.cu.h"
#include "Thread2D.cu.h"
#include "cudas.h"

#include "Indices.cu.h"

#include "RipplingMath.cu.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

static __device__ void ripplingBaseline(uchar4* tabPixelsGM, uint w, uint h, float t);
static __device__ void ripplingDemi(uchar4* tabPixelsGM, uint w, uint h, float t);
static __device__ void ripplingQuart(uchar4* tabPixelsGM, uint w, uint h, float t);

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

__global__ void rippling(uchar4* tabPixelsGM, uint w, uint h, float t)
    {
    // ripplingBaseline(tabPixelsGM, w, h, t); // warmup
    ripplingDemi(tabPixelsGM, w, h, t); // required for performance
    // ripplingQuart(tabPixelsGM, w, h, t); 	// nice to have
    }

// ---------------------------------
// Private
// ---------------------------------

/**
 * v1
 */
__inline__ __device__ void ripplingBaseline(uchar4* tabPixelsGM, uint w, uint h, float t)
    {
    // TODO instacier RipplingMath

    RipplingMath rippling_math = RipplingMath(w, h, t);
    const int TID = Thread2D::tid();
    const int NB_THREAD = Thread2D::nbThread();
    const int WH = w * h;

    int work = TID;

    while (work < WH)
        {

        int i = work % w;
        int j = work / w;

        uchar4 color;

        rippling_math.colorIJ(&color, i, j);

        tabPixelsGM[work] = color;

        work += NB_THREAD;
        }

    // TODO Rippling GPU  pattern entrelacement
    }

/**
 * v2 : optimisation (possible car w et h sont impair (necessaire pour test performance)
 */
__inline__ __device__ void ripplingDemi(uchar4* tabPixelsGM, uint w, uint h, float t)
    {
    // Indication:
    //		(I1)	Utiliser la symetrie horizontale de l'image
    //		(I2)	Calculer que la demi partie superieur
    //		(I3)	Ranger la couleur calculer dans la demi partie superieur dans la demi partie inferieur (effet miroir)
    //			Partez de la fin de l'image, peut-etre
    //		(I4)	N'oubliez pas de calculer la ligne centrale (h est impaire)

    // TODO Rippling GPU
    RipplingMath rippling_math = RipplingMath(w, h, t);
    const int TID = Thread2D::tid();
    const int NB_THREAD = Thread2D::nbThread();

    const int half_h = h / 2;
    const int pixel_in_top = w * half_h;

    int work = TID;

    while (work < pixel_in_top)
        {

        int i = work % w;
        int j = work / w;

        uchar4 color;

        rippling_math.colorIJ(&color, i, j);

        tabPixelsGM[work] = color;
        tabPixelsGM[(h - 1 - j) * w + i] = color;

        work += NB_THREAD;
        }

    int iMid = TID;
    while (iMid < w)
        {
        uchar4 color;
        rippling_math.colorIJ(&color, iMid, half_h);
        tabPixelsGM[half_h * w + iMid] = color;
        iMid += NB_THREAD;
        }
    }

/**
 * v3 : optimsation : defi (difficile) (pas necessaire pour test performance)
 */
__inline__ __device__ void ripplingQuart(uchar4* tabPixelsGM, uint w, uint h, float t)
    {
    // Indication:
    //		(I1)	Utiliser la symetrie horizontale et verticale de l'image
    //		(I2)	Calculer que le quart en huat a gauche
    //		(I3)	Ranger la couleur calculer dans les autres quarts
    //	Warning
    //		(w1)	Necessaire sans doute pour passer le test performance
    //
    //	Contrainte
    //		(C1)	Utiliser toujours le pattern d'entrelacement

    // TODO Rippling GPU
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
