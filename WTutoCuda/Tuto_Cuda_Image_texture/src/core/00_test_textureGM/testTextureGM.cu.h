#pragma once

#include <iostream>
#include <stdio.h>

#include "GM.h"
#include "Hardware.h"
#include "Indices.cu.h"
#include "Kernel.h"
#include "ReducerAdd.cu.h"
#include "Texture2D_GM.h"
#include "Thread2D.cu.h"
#include "cudas.h"

using std::cerr;
using std::cout;
using std::endl;

// https://leimao.github.io/blog/Pass-Function-Pointers-to-Kernels-CUDA/

// --------------------------------------------------------------------------------------
// Declarations
// --------------------------------------------------------------------------------------

template <typename T> bool useTextureGM();

template <typename T> static bool useTextureGM(dim3 dg, dim3 db);

template <typename T> static bool test1_textureGM(int w, int h, dim3 dg, dim3 db);

template <typename T> static bool test2_textureGM(int w, int h, dim3 dg, dim3 db);

// ---------------------------------
//  device
// ---------------------------------

template <typename T> __global__ void fillTextureGM(T *tabGM, int n);

template <typename T> __global__ void checkTextureGM(cudaTextureObject_t tex2dGM, int w, int h, int *ptrSumOkGM);

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

// ---------------------------------
//  host
// ---------------------------------

/**
 * exemple float int uchar char
 */
template <typename T> bool useTextureGM()
    {
    // Grid (disons on cherche pas optimum ici)
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();
    dim3 dg(MP * 2, 1, 1);
    dim3 db(64, 1, 1); // power 2 reduction

    return useTextureGM<T>(dg, db);
    }

/**
 * exemple float int uchar char
 */
template <typename T> bool useTextureGM(dim3 dg, dim3 db)
    {
    const int MIN = 32;    // contrainte MIN*sizeof(type)>=32  // float et int : MIN=4 uchar : MIN=32
    const int MAX = 16384; // on arrte la suffisant

    bool isOk = true;
    int failed = 0;
    int success = 0;
    int s = 0;
    for (int w = MIN; w <= MAX; w = w * 2) // *2 ok mais +2 ko // puissance de 2 depuis 8
        {
        for (int h = 1; h <= MAX; h = h + 1) // n'importe quoi // min 1
            {
            // cout << "(w,h)=(" << w << "," << h << ")"<<endl;

            bool isOkLocal = test1_textureGM<T>(w, h, dg, db);
            isOkLocal &= test2_textureGM<T>(w, h, dg, db);

            if (isOkLocal)
                {
                cout << "(w,h)=(" << w << "," << h << ") : success " << endl;
                success++;
                }
            else
                {
                failed++;
                cerr << "(w,h)=(" << w << "," << h << ") : failed " << endl;
                }

            isOk = isOk && isOkLocal;
            s++;
            }
        cout << endl;
        }

    // statistique
    cout << endl;
    cout << "#sucess = " << success << endl;
    cout << "#failed = " << failed << endl;
    cout << "#total  = " << s << endl;
    cout << endl;

    return isOk;
    }

template <typename T> bool test1_textureGM(int w, int h, dim3 dg, dim3 db)
    {
    const int WH = w * h;

    // GM
    size_t sizeGM = WH * sizeof(T);
    T *tabGM;
    GM::malloc(&tabGM, sizeGM);
    fillTextureGM<<<dg, db>>>(tabGM, WH);

    // texture sur tabGM
    Texture2D_GM<T> texture2D(w, h);
    texture2D.see(tabGM);

    // check
    int *ptrSumOkGM;
    GM::mallocInt0(&ptrSumOkGM);

    size_t sizeSM = db.x * db.y * db.z * sizeof(int);
    checkTextureGM<T><<<dg, db, sizeSM>>>(texture2D.texCuda, w, h, ptrSumOkGM);

    int sumOK = 0;
    GM::memcpyDToH_int(&sumOK, ptrSumOkGM);

    // free
    GM::free(tabGM);
    GM::free(ptrSumOkGM);

    bool isOK = (sumOK == WH);
    cout << "test 1 : sumOk = " << sumOK << endl;
    cout << "test 1 : WH    = " << WH << endl;
    return isOK;
    }

template <typename T> bool test2_textureGM(int w, int h, dim3 dg, dim3 db)
    {
    const int WH = w * h;

    // GM
    size_t sizeGM = WH * sizeof(T);
    T *tabGM1;
    T *tabGM2;
    GM::malloc(&tabGM1, sizeGM);
    GM::malloc(&tabGM2, sizeGM);

    // fill tabGM1
    fillTextureGM<<<dg, db>>>(tabGM1, WH);

    // fill tabGM2 : tabGM1 -> tabGM2
    Texture2D_GM<T> texture2D(w, h);
    texture2D.see(tabGM2);
    GM::memcpyDToD(tabGM2, tabGM1, sizeGM);

    // check
    int *ptrSumOkGM;
    GM::mallocInt0(&ptrSumOkGM);

    size_t sizeSM = db.x * db.y * db.z * sizeof(int);
    checkTextureGM<T><<<dg, db, sizeSM>>>(texture2D.texCuda, w, h, ptrSumOkGM);

    int sumOK = 0;
    GM::memcpyDToH_int(&sumOK, ptrSumOkGM);

    // free
    GM::free(tabGM1);
    GM::free(tabGM2);
    GM::free(ptrSumOkGM);

    bool isOK = (sumOK == WH);
    cout << "test 2 : sumOk = " << sumOK << endl;
    cout << "test 2 : WH    = " << WH << endl;
    return isOK;
    }

// ---------------------------------
//  device
// ---------------------------------

template <typename T> __global__ void fillTextureGM(T *tabGM, int WH)
    {
    const int TID = Thread2D::tid();
    const int NB_THREAD = Thread2D::nbThread();

    //    if(TID==0)
    //	{
    //	printf("\nkernel fillTextureGM WH=%d\n",WH);
    //	}

    int s = TID;
    while (s < WH)
        {
        tabGM[s] = (s + 1);

        // next
        s += NB_THREAD;
        }

    // tabGM[0] = 111; // pour voir que donne bien false
    }

template <typename T> __global__ void checkTextureGM(cudaTextureObject_t tex2dGM, int w, int h, int *ptrSumOkGM)
    {
    extern __shared__ int tabSM[];

        // reduction intraThread
        {
        const int TID = Thread2D::tid();
        const int NB_THREAD = Thread2D::nbThread();

        //	if(TID==0)
        //	    {
        //	    printf("kernel checkTextureGM\n");
        //	    }

        int i;
        int j;
        T valueIJ;
        T valueIJ_expected;
        int s = TID;
        const int WH = w * h;
        int sum = 0;
        while (s < WH)
            {
            Indices::toIJ(s, w, &i, &j);

            valueIJ = tex2D<T>(tex2dGM, j, i); // warning: orde i et j : tex2D(j,i) et non (i,j)
            valueIJ_expected = (s + 1);

                // debug
                {
                // printf("[ %f, %f ]  delta = %f\n",valueIJ,valueIJ_expected,(valueIJ_expected-valueIJ));
                // printf("[ %i, %i ]  delta = %i\n",valueIJ,valueIJ_expected,(valueIJ_expected-valueIJ));
                }

            if (valueIJ == valueIJ_expected)
                {
                sum++;
                }

            // next
            s += NB_THREAD;
            }

        tabSM[Thread2D::tidLocal()] = sum;
        }

    __syncthreads();

    ReducerAdd::reduce(tabSM, ptrSumOkGM);
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
