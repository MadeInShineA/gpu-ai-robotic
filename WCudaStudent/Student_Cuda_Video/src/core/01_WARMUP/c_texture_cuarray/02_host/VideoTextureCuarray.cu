#include <iostream>

#include "Texture2D.h"
#include "VideoTextureCuarray.h"

using std::cerr;
using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
//  Extern
// --------------------------------------------------------------------------------------

/**
 * <pre>
 * source : 	tex2dVideo
 * destination :tabPixelsGM
 * </pre>
 */
extern __global__ void kContourTex(cudaTextureObject_t tex2dVideo, uchar *tabPixelsGM, uint w, uint h);

// --------------------------------------------------------------------------------------
//  Constructors
// --------------------------------------------------------------------------------------

VideoTextureCuarray::VideoTextureCuarray(const Grid &grid, IteratorImageGray_I *ptrIteratorImage)
    : Animable_I<uchar>(grid, ptrIteratorImage->getW(), ptrIteratorImage->getH(), "Video_contour_Texture_cuarray_uchar"), //
                                                                                                                          //
      ptrIteratorImage(ptrIteratorImage),                                                                                 //
      //
      texture2DVideo(ptrIteratorImage->getW(), ptrIteratorImage->getH())
    {
        // animation
        {
        this->t = 0; // protected dans Animable
        }

        // video
        {
        this->tabPixelVideo = ptrIteratorImage->first();
        }
    }

VideoTextureCuarray::~VideoTextureCuarray()
    {
    // rien
    }

// --------------------------------------------------------------------------------------
//  Methodes
// --------------------------------------------------------------------------------------

/**
 * Override
 * Call periodicly by the API
 *
 * Note : domaineMath pas use car pas zoomable
 */
void VideoTextureCuarray::process(uchar *tabPixelsGM, uint w, uint h, const DomaineMath &domaineMath)
    {
    // 1) copier tabPixelVideo dans texture2DVideo
    // 2) appeler le kernel de contour

    // TODO
    }

/**
 * Override
 * Call periodicly by the API
 */
void VideoTextureCuarray::animationStep()
    {
    t++;

    this->tabPixelVideo = ptrIteratorImage->next();
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
