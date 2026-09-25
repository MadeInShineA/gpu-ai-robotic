#include <iostream>

#include "SceneCubeCreator.h"

#include "DamierProvider.h"
#include "VagueProvider.h"

#include "DamierHSBAFloatProvider.h"
#include "DamierHueFloatProvider.h"
#include "DamierRGBAFloatProvider.h"
#include "VagueGrayProvider.h"

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

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

SceneCube *SceneCubeCreator::getScene()
    {
    return ptrScene;
    }

// ---------------------------------
//  Private
// ---------------------------------

void SceneCubeCreator::createImages()
    {
    ptrImage1 = VagueProvider().createImageGL();
    ptrImage2 = DamierProvider().createImageGL();

    ptrImage3 = VagueGrayProvider().createImageGL();
    ptrImage4 = DamierRGBAFloatProvider().createImageGL();
    ptrImage5 = DamierHSBAFloatProvider().createImageGL(); // ko, FIXME JST shader
    ptrImage6 = DamierHueFloatProvider().createImageGL();  // ko, FIXME JST shader
    }

void SceneCubeCreator::createScene()
    {
    ptrScene = new SceneCube(ptrImage1, ptrImage2, ptrImage3, ptrImage4, ptrImage5, ptrImage6);
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
