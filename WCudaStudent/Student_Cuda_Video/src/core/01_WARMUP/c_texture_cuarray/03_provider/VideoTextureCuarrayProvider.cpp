#include "VideoTextureCuarrayProvider.h"
#include "VideoTextureCuarray.h"

#include "Grid.h"
#include "Hardware.h"

#include "Videos.h"

// --------------------------------------------------------------------------------------
//  Constructors
// --------------------------------------------------------------------------------------

VideoTextureCuarrayProvider::VideoTextureCuarrayProvider(bool loadOnlyOneImage) : Provider_uchar_A(loadOnlyOneImage)
    {
    // rien de plus
    }

VideoTextureCuarrayProvider::~VideoTextureCuarrayProvider()
    {
    // rien
    }

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

/**
 * Override
 */
Grid VideoTextureCuarrayProvider::grid()
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
Animable_I<uchar> *VideoTextureCuarrayProvider::createAnimable(const Grid &grid, bool isVerbose)
    {
    IteratorImageGray_I *ptrIteratorImageGray = Autoroute::getInstance()->iterator();
    // IteratorImageGray_I* ptrIteratorImageGray = NeilPryde::getInstance()->iterator();

    // IteratorImageGray_I* ptrIteratorImageGray = Matrix12::getInstance()->iterator();
    // IteratorImageGray_I* ptrIteratorImageGray = Matrix21::getInstance()->iterator();
    // IteratorImageGray_I* ptrIteratorImageGray = Matrix22::getInstance()->iterator();

    // IteratorImageGray_I* ptrIteratorImageGray = Dilatation::getInstance()->iterator();
    // IteratorImageGray_I* ptrIteratorImageGray = Errosion::getInstance()->iterator();
    // IteratorImageGray_I* ptrIteratorImageGray = Contrast::getInstance()->iterator();

    return new VideoTextureCuarray(grid, ptrIteratorImageGray);
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
