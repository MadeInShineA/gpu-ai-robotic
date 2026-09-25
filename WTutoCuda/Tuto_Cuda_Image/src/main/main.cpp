#include <iostream>

#include "CudaContextImage.h"
#include "Limits.h"

using std::cerr;
using std::cout;
using std::endl;

// --------------------------------------------------------------------------------------
// Extern
// --------------------------------------------------------------------------------------

extern int mainImage(const Args &args);
extern int mainBenchmark();
extern int mainBrutforce();

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

int main(int argc, char **argv)
    {
    // Limits::rappelTypeSize();

    CudaContextImage cudaContext;

        // public
        {
        cudaContext.deviceId = 0;                        //  in [0,2] width Server Cuda3
        cudaContext.launchMode = LaunchModeImage::IMAGE; // IMAGE  BENCHMARKING BRUTFORCE

        cudaContext.deviceDriver = DeviceDriver::LOAD_CURRENT; // LOAD_CURRENT   LOAD_ALL
        cudaContext.deviceInfo = DeviceInfo::ALL_SIMPLE;       // NONE  ALL  ALL_SIMPLE  CURRENT
        }

        // private
        {
        cudaContext.args.argc = argc;
        cudaContext.args.argv = argv;

        cudaContext.mainImage = mainImage;
        cudaContext.mainBenchmark = mainBenchmark;
        cudaContext.mainBrutforce = mainBrutforce;
        }

    return cudaContext.process();
    }

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
