#include "VideoTextureGMProvider.h"
#include "VideoTextureGM.h"

#include "Grid.h"
#include "Hardware.h"

#include "Videos.h"

// --------------------------------------------------------------------------------------
//  Constructors
// --------------------------------------------------------------------------------------

VideoTextureGMProvider::VideoTextureGMProvider(bool loadOnlyOneImage) : Provider_uchar_A(loadOnlyOneImage)
    {
    // rien de plus
    }

VideoTextureGMProvider::~VideoTextureGMProvider()
    {
    // rien
    }

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

/**
 * Override
 */
Grid VideoTextureGMProvider::grid() // gridMinMax
    {
    const int MP = Hardware::getMPCount();
    const int CORE_MP = Hardware::getCoreCountMP();

    // TODO
    assert(false);
    Grid grid;

    return grid;
    }

/**
 * Override
 */
Animable_I<uchar> *VideoTextureGMProvider::createAnimable(const Grid &grid, bool isVerbose)
    {
    // IteratorImageGray_I* ptrIteratorImageGray = Autoroute::getInstance()->iterator();
    // IteratorImageGray_I* ptrIteratorImageGray = NeilPryde::getInstance()->iterator();

    // IteratorImageGray_I* ptrIteratorImageGray = Matrix12::getInstance()->iterator(); // utile pour debuguer et valider
    // IteratorImageGray_I* ptrIteratorImageGray = Matrix21::getInstance()->iterator(); // utile pour debuguer et valider
    // IteratorImageGray_I* ptrIteratorImageGray = Matrix22::getInstance()->iterator(); // utile pour debuguer et valider

    // IteratorImageGray_I* ptrIteratorImageGray = Dilatation::getInstance()->iterator();
    // IteratorImageGray_I* ptrIteratorImageGray = Errosion::getInstance()->iterator();
    IteratorImageGray_I *ptrIteratorImageGray = Contrast::getInstance()->iterator(); // utile pour debuguer et valider

    return new VideoTextureGM(grid, ptrIteratorImageGray);
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
