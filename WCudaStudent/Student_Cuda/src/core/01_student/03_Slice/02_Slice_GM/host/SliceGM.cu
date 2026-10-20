#include "SliceGM.h"

#include <assert.h>
#include <iostream>

#include "GM.h"
#include "Hardware.h"
#include "Kernel.h"
#include "Maths.h"

using std::cout;
using std::endl;
using std::to_string;

// --------------------------------------------------------------------------------------
//  Externs
// --------------------------------------------------------------------------------------

extern __global__ void reductionIntraThreadGM(float* tabGM, int nbSlice);
extern __global__ void ecrasementGM(float* tabGM, int moitier);

// --------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------

SliceGM::SliceGM(Grid grid, int nbSlice, double* ptrPiHat, bool isVerbose)
    : RunnableGPU(grid, "SliceGM_" + to_string(nbSlice), isVerbose), // classe parente
                                                                     //
      nbSlice(nbSlice),                                              //
      ptrPiHat(ptrPiHat)                                             //
    {
    this->nTabGM = grid.threadCounts();             // Done SliceGM
    this->sizeTabGM = this->nTabGM * sizeof(float); //  Done SliceGM // [octet]
    GM::malloc(&this->tabGM, this->sizeTabGM);
    }

SliceGM::~SliceGM(void)
    {
    GM::free(this->tabGM);
    }

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

/**
 * <pre>
 * Idea globale
 *
 *	Etape 0 : Promotion d'un tableau en GM (MemoryManagement MM)
 * 	Etape 1 : Reduction intra-thread dans un tableau promu en GM
 * 	Etape 2 : Reduction du tableau en GM par ecrasement hierarchique 2 à 2
 * 		  On lance les kernels d'ecrasement depuis le host (chef d'orchestre)
 * 	Etape 4 : Copy du resultat coter host
 * 	Etape 5 : Destruction GM
 * </pre>
 */
void SliceGM::run()
    {
    // TODO SliceGM // call the kernel (asynchrone)
    reductionIntraThreadGM<<<this->dg, this->db>>>(this->tabGM, this->nbSlice);
    reductionGM();
    }

// ---------------------------------
//  Private
// ---------------------------------

/**
 * Etape 1 : Lancement des kernels d'ecrasement depuis le host, dans une boucle,
 * Etape 2 : recuperer le resultat coter host
 * Etape 3 : finaliser le calcule de PI
 */
void SliceGM::reductionGM()
    {
    int midle = nTabGM >> 1; // nTabGM/2;

    // TODO SliceGM

    // Warning:		Utiliser une autre grille que celle heriter de la classe parente dg, db
    // 			Votre grid ici doit avoir une taille speciale!
    // 			N'utiliser donc pas les variables dg et db de la classe parentes

    // Tip:		Il y a une methode dedier pour ramener un float cote host
    //
    //				float resultat;
    //				GM::memcpyDToH_float(&resultat,ptrResultGM);

    while (midle > 0)
        {
        dim3 db(256);
        dim3 dg((midle + db.x - 1) / db.x);
        ecrasementGM<<<dg, db>>>(this->tabGM, midle);
        midle = midle >> 1;
        }

    float result;
    GM::memcpyDToH_float(&result, &this->tabGM[0]);

    result = result * (1.0f / float(this->nbSlice));

    *this->ptrPiHat = double(result);
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
