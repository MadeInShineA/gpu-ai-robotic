#pragma once

#include "Maths.h"
#include <math.h>

#include "Colors.cu.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class RipplingMath
    {
    /*--------------------------------------*\
    |*		Constructeur		*|
     \*-------------------------------------*/

  public:
    __device__ RipplingMath(uint w, uint h, float t)
        : dim2(w / 2), //
          t(t)
        {
        // rien
        }

    __device__ virtual ~RipplingMath()
        {
        // rien
        }

    /*--------------------------------------*\
    |*		Methode			*|
     \*-------------------------------------*/

  public:
    __device__ void colorIJ(uchar4* ptrColorIJ, int i, int j)
        {
        // uchar levelGris = levelGray(i, j); // update levelGris

        // ptrColorIJ->x = levelGris;
        // ptrColorIJ->y = levelGris;
        // ptrColorIJ->z = levelGris;

        // ptrColorIJ->w = 255; // opaque

        // Conseil:
        // 		Etape 1 : 	Commencer par afficher une image uniforme grise (128 par exemple)
        // 				pour valider tout le pipeline en amont
        //
        // 		Etape 2:	Puis une fois que l'image grise est valider, attaquer rippling

        // debug temp
        //		{
        //		ptrColorIJ->x = 128;
        //		ptrColorIJ->y = 128;
        //		ptrColorIJ->z = 128;
        //		ptrColorIJ->w = 255; // opacity facultatif
        //		}

        uchar gray_level = levelGray(i, j);

        uchar4 color = {gray_level, gray_level, gray_level, 255};

        *ptrColorIJ = color;
        }

  private:
    /*-------------*\
     |*	int	*|
     \*------------*/

    __inline__ __device__ uchar levelGray(int i, int j)
        {

        float dij_value;

        dij(i, j, &dij_value);

        float num = cos((dij_value / 10.0f) - (this->t / 7.0f));

        float denum = (dij_value / 10.0f) + 1;

        float frac = num / denum;

        float value = 128 + (127 * frac);

        return (uchar)value;
        }

    __inline__ __device__ void dij(int i, int j, float* ptrResult)
        {
        // TODO Rippling GPU cf fonction math pdf

        // Ne pas utiliser la fonction pow pour elever au carrer !
        // Utiliser l'opérateur *
        int f_i = i - this->dim2;
        int f_j = j - this->dim2;

        float value = sqrtf((f_i * f_i) + (f_j * f_j));

        *ptrResult = value;
        }

    /*--------------------------------------*\
    |*		Attribut			*|
     \*-------------------------------------*/

  private:
    // Tools
    int dim2; // dim2=dim/2
    float t;
    };

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
