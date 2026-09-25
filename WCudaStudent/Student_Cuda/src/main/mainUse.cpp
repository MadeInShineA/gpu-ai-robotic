#include <iostream>
#include <stdlib.h>

using std::cerr;
using std::cout;
using std::endl;

#include "Couts.h"
#include "Limits.h"

// Slice
#include "SliceGmHostUse.h"
#include "SliceGmUse.h"
#include "SliceMultiUse.h"
#include "SliceSmUse.h"

// Montecarlo
#include "MontecarloStreamUse.h"
#include "MontecarloThreadUse.h"
#include "MontecarloUse.h"
#include "entier_montecarlo.h"

// Vector Stream
#include "AddVectorBistreamUse.h"
#include "AddVectorTristreamUse.h"
#include "AddVectorUse.h"
#include "VectorTools.h"

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

static void slice(bool &isOk);
static void montecarlo_use(bool &isOk);
static void vector(bool &isOk);

static void print(bool isSuccess);

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

static const int IS_VERBOSE = true;

int mainUse()
    {
    // activer ci-dessous seulement le TP voulu (pas tous)

    bool isOk = true;

    slice(isOk); // voir code ci-dessous pour activer la version voulue
    // montecarlo_use(isOk);	// voir code ci-dessous pour activer la version voulue
    // vector(isOk);		// voir code ci-dessous pour activer la version voulue

    print(isOk);

    return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
    }

// --------------------------------------------------------------------------------------
// TP
// --------------------------------------------------------------------------------------

/**
 * activer ci-dessous la version souhaiter
 */
void slice(bool &isOk)
    {
    SliceGmHostUse sliceGmHostUse(IS_VERBOSE);
    // SliceGmUse sliceGmUse(IS_VERBOSE);
    // SliceSmUse sliceSmUse(IS_VERBOSE);
    // SliceMultiUse sliceMultiUse(IS_VERBOSE);

    isOk &= sliceGmHostUse.isOk(IS_VERBOSE);
    // isOk &= sliceGmUse.isOk(IS_VERBOSE);
    // isOk &= sliceSmUse.isOk(IS_VERBOSE);
    // isOk &= sliceMultiUse.isOk(IS_VERBOSE);
    }

/**
 * activer ci-dessous la version souhaiter
 */
void montecarlo_use(bool &isOk)
    {
    const float HMIN = 4;
    const float HMAX = 10;

    cout << endl;

        // mono
        {
        for (float h = HMIN; h <= HMAX; h = h + 1)
            {
            MontecarloUse algo(IS_VERBOSE, h);
            isOk &= algo.isOk(IS_VERBOSE);
            }
        }

    cout << endl;

        // thread
        {
        for (float h = HMIN; h <= HMAX; h = h + 1)
            {
            MontecarloThreadUse algo(IS_VERBOSE, h);
            isOk &= algo.isOk(IS_VERBOSE);
            }
        }

    cout << endl;

        // stream
        {
        for (float h = HMIN; h <= HMAX; h = h + 1)
            {
            MontecarloStreamUse algo(IS_VERBOSE, h);
            isOk &= algo.isOk(IS_VERBOSE);
            }
        }

    cout << endl;
    }

/**
 * activer ci-dessous la version souhaiter
 */
void vector(bool &isOk)
    {
        // Base line
        {
        AddVectorUse algo(IS_VERBOSE);
        isOk &= algo.isOk(false);
        }

        // Bi-stream
        {
        AddVectorBistreamUse algo(IS_VERBOSE);
        isOk &= algo.isOk(false);
        }

    const bool IS_WARMUP = true;

    // Warning :
    //		 On ne peut pas en meme temps lancer en mode warmup et en mode generic.
    //		 D'abord on valide completement le mode warmup (les 3) puis apres on attaque le mode generic.
    //		 Une fois le mode generic fonctionel, le mode warmup n'est plus tres utile.
    //		 Il nous a juste permis de contruire le mode generic
    //		 Sauf erreur, les tests unitaires ne sont coder que pour le cas generique.

    if (IS_WARMUP) // Tri-stream : warmup 3 4 5  slices
        {
        // Warning :
        //		(W0) Le code warump doit etre activer dans votre implementation soit pour 3 4 ou 5 slices
        //		(W1) Le true  ci-dessous implique un affichage dans la console
        //		(W2) Dans ce cas il serait bien que  VectorTools:n() soit petit
        //		(W3) Changer le provisoirement
        //		(W4) Ce n doit etre divisible par nbSlice
        //		(W5) Il faut donc changer le code a 4 endroits differents
        //				ICI : nbSlice
        //				ICI : IS_WARMUP
        //				VectorToos.n()
        //				void AddVectorTristream::run()

        int nbSlice = 3;
        // int nbSlice = 4;
        // int nbSlice = 5;

        AddVectorTristreamUse algo(nbSlice, IS_VERBOSE); // true implique un affichage dans la console
        bool isOkSlice = algo.isOk(false);
        // cout <<"Tri-stream : warmup : #slice = "<<nbSlice << " : success = "<<isOkSlice<<endl;
        isOk &= isOkSlice;
        }
    else // Tri-stream (generic)	: Warning : le code generic doit etre activer dans votre implementation
        {
            // Use1
            {
            for (int nbSlice = 3; nbSlice <= 15; nbSlice++)
                {
                AddVectorTristreamUse algo(nbSlice, IS_VERBOSE);
                bool isOkSlice = algo.isOk(false);
                // cout <<"Tri-stream : #slice = "<<nbSlice << " : success = "<<isOkSlice<<endl;

                isOk &= isOkSlice;
                }
            }

            // Use2
            {
            for (int nbSlice = 5; nbSlice <= 75; nbSlice += 5)
                {
                AddVectorTristreamUse algo(nbSlice, IS_VERBOSE);
                bool isOkSlice = algo.isOk(false);
                // cout <<"Tri-stream :  #slice = "<<nbSlice << " : success = "<<isOkSlice<<endl;

                isOk &= isOkSlice;
                }
            }
        }
    }

// --------------------------------------------------------------------------------------
// Tools
// --------------------------------------------------------------------------------------

void print(bool isSuccess)
    {
    cout << endl << Couts::REVERSE;

    Couts::status(isSuccess, "Success, Congratulations !", "Failed, sorry!");

    cout << endl << Couts::RESET;
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
