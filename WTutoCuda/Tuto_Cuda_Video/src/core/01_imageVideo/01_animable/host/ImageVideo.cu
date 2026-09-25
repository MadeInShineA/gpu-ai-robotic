#include <assert.h>
#include <iostream>

#include "GM.h"
#include "ImageVideo.h"

using std::cerr;
using std::cout;
using std::endl;

// ---------------------------------------------------------------------------
// Extern
// ---------------------------------------------------------------------------

extern __global__ void kToGray(uchar4 *tabPixelGM, uint wh);

// ---------------------------------------------------------------------------
// Constructors
// ---------------------------------------------------------------------------

ImageVideo::ImageVideo(const Grid &grid, uint w, uint h, string nameVideo, int nbImage)
    : Animable_I<uchar4>(grid, w, h, "Video_RGBA_uchar4"), //
      videoProviderRGB(nameVideo, nbImage)
    {
    // Tools
    this->t = 0; // protected dans Animable
    this->sizeImage = sizeof(uchar4) * w * h;

        // video
        {
        bool isOk = videoProviderRGB.loadALL();
        assert(isOk);
        assert(videoProviderRGB.getW() == w && videoProviderRGB.getH() == h);

        animationStep();
        }
    }

ImageVideo::~ImageVideo()
    {
    // rien
    }

// ---------------------------------------------------------------------------
// Methodes
// ---------------------------------------------------------------------------

/**
 * Override
 * Call periodicly by the API
 *
 * Note : domaineMath pas use car pas zoomable
 */
void ImageVideo::process(uchar4 *tabPixelsGM, uint w, uint h, const DomaineMath &domaineMath)
    {
    GM::memcpyHToD(tabPixelsGM, ptrTabPixelVideo, sizeImage);

    kToGray<<<dg, db>>>(tabPixelsGM, w * h);
    }

/**
 * Override
 * Call periodicly by the API
 */
void ImageVideo::animationStep()
    {
    t++;

    this->ptrTabPixelVideo = videoProviderRGB.getImage();
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
