#include "Maths.h"
#include "Thread1D.cu.h"
#include "Thread2D.cu.h"
#include "cudas.h"

#include "Calibreur.cu.h"

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

__global__ void kConstrastor(uchar *tabPixelsGM, uint wh, int *ptrMinGM, int *ptrMaxGM)
    {
    // Goal  :		[min,max]-> [0,255]
    //
    // Tools : 		Calibreur<float> calibreur(Interval<float> depart, Interval<float> arriver)
    //	       		calibreur.calibrer(&toCalibrer);
    //	       		travailler en float pour la calibration
    //
    // Astuce:  	Interval<float> intervalArriver(0, 255.9f); // 255.9f sinon on obtient jamais 255, mais 254 comme max
    //
    // Compilation:
    //			float value0255=...
    //			calibreur.calibrer(&value0255); // updateValue
    //			uchar levelGray=(uchar)value0255;
    //
    // Note:		On pet aussi faire sans le calibreur, et écrire soit meme la formule, transformation affine: facile

    float min = *ptrMinGM;
    float max = *ptrMaxGM;

    // TODO kConstrastor
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
