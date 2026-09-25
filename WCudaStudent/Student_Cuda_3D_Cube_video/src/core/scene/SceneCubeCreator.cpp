#include <iostream>

#include "SceneCubeCreator.h"

// video
#include "VideoBaseProvider.h"
#include "VideoSurfaceProvider.h"
#include "VideoTextureCuarrayProvider.h"
#include "VideoTextureGMProvider.h"

// image (activate in dataProject.mk src_aux+= line 45 (about)
// #include "MandelbrotProvider.h"
// #include "RaytracingProviderCM.h"
// #include "RaytracingProviderCM2SM.h"
// #include "RaytracingProviderGM.h"
// #include "RaytracingProviderSM.h"
// #include "RipplingProvider.h"

// --------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------

SceneCubeCreator::SceneCubeCreator()
    {
    createImages();
    createScene();
    }

SceneCubeCreator::~SceneCubeCreator()
    {
    delete ptrImage1;
    delete ptrImage2;
    delete ptrImage3;
    delete ptrImage4;
    delete ptrImage5;
    delete ptrImage6;

    delete ptrScene;
    }

// ---------------------------------
// Override
// ---------------------------------

SceneCube *SceneCubeCreator::getScene()
    {
    return ptrScene;
    }

// ---------------------------------
// Private
// ---------------------------------

void SceneCubeCreator::createImages()
    {
    // video
    ptrImage1 = VideoBaseProvider().createImageGL();
    ptrImage2 = VideoTextureGMProvider().createImageGL();
    ptrImage3 = VideoTextureCuarrayProvider().createImageGL();
    ptrImage4 = VideoSurfaceProvider().createImageGL();
    ptrImage5 = VideoSurfaceProvider().createImageGL();
    ptrImage6 = VideoSurfaceProvider().createImageGL();

    //    // image
    //    ptrImage1 = RipplingProvider().createImageGL();
    //    ptrImage2 = MandelbrotProvider().createImageGL();
    //
    //    ptrImage3 = RaytracingProviderGM().createImageGL();
    //    ptrImage4 = RaytracingProviderSM().createImageGL();
    //    ptrImage5 = RaytracingProviderCM().createImageGL();
    //    ptrImage6 = RaytracingProviderCM2SM().createImageGL();
    }

void SceneCubeCreator::createScene()
    {
    ptrScene = new SceneCube(ptrImage1, ptrImage2, ptrImage3, ptrImage4, ptrImage5, ptrImage6);
    }

// --------------------------------------------------------------------------------------
// End
// --------------------------------------------------------------------------------------
