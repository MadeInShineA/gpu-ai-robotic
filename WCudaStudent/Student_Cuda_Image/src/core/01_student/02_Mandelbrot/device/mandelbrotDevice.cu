#include "Thread2D.cu.h"
#include "cudas.h"

#include "MandelbrotMath.cu.h"
#include "real_mandelbrot.h"

#include "Colors.cu.h"
#include "DomaineMath.h"
#include "Indices.cu.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

// optimisation lookup table color
static __device__ void fill(uchar4 *tabSM, int n);
static __device__ void color(uchar4 *ptrColor, int k, int n);

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

__global__ void mandelbrot(uchar4 *tabPixelsGM, uint w, uint h, DomaineMath domaineMath, int n)
    {
    // TODO Mandelbrot  :
    //
    // entrelacement
    // s -> (i,j) -> (x,y)
    // appeler colorXY

    double x;
    double y;
    // domaineMath.toXY(i, j, &x, &y); // x et y doivent etre en double! Caster ensuite en real lors du passage à colorXY
    }

// ---------------------------------
// Private
// ---------------------------------

/**
 * optimisation lookup table color (facultatif)
 */
__inline__ __device__ void fill(uchar4 *tabSM, int n)
    {
    // Indications:
    //		(I1)	tabSM a n cases
    //		(I2)	La case k contient les couleurs en RVBA lorsque la suite s est arreter a k
    //		(I3)	Utiliser la methode color ci-dessous pour vous aider
    //		(I4)	Utiliser tabSM dans la partie mandelbrotMath, updater a cet effet quelques prototypes si necessaire
    //			Passer par exemple tabSM au constructeur de mandelbrotMath
    //
    //	Warning
    //		(W1)	Commencer d'abord sans cette piste d'optimisation
    }

/**
 * optimisation lookup table color (facultatif)
 */
__inline__ __device__ void color(uchar4 *ptrColor, int k, int n)
    {
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
