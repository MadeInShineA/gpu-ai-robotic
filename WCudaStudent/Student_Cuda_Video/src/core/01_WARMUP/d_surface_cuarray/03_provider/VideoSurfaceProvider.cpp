#include "VideoSurfaceProvider.h"
#include "VideoSurface.h"

#include "Grid.h"
#include "Hardware.h"

#include "Videos.h"

// --------------------------------------------------------------------------------------
//  Constructors
// --------------------------------------------------------------------------------------

VideoSurfaceProvider::VideoSurfaceProvider(bool loadOnlyOneImage) : Provider_uchar_A(loadOnlyOneImage)
    {
    // rien de plus
    }

VideoSurfaceProvider::~VideoSurfaceProvider()
    {
    // rien
    }

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

/**
 * Override
 */
Grid VideoSurfaceProvider::grid() // gridDilatation
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
Animable_I<uchar> *VideoSurfaceProvider::createAnimable(const Grid &grid, bool isVerbose)
    {
    // IteratorImageGray_I* ptrIteratorImageGray = Autoroute::getInstance()->iterator();
    //   IteratorImageGray_I* ptrIteratorImageGray = NeilPryde::getInstance()->iterator();

    // IteratorImageGray_I* ptrIteratorImageGray = Matrix12::getInstance()->iterator();
    // IteratorImageGray_I* ptrIteratorImageGray = Matrix21::getInstance()->iterator();
    //  IteratorImageGray_I* ptrIteratorImageGray = Matrix22::getInstance()->iterator();

    IteratorImageGray_I *ptrIteratorImageGray = Dilatation::getInstance()->iterator(); // Utile pour debuguer
    // IteratorImageGray_I* ptrIteratorImageGray = Errosion::getInstance()->iterator();
    // IteratorImageGray_I* ptrIteratorImageGray = Contrast::getInstance()->iterator();
    uchar seuil0255 = 150;

    return new VideoSurface(grid, ptrIteratorImageGray, seuil0255); // gridDilatation
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
