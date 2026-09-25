#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "Chrome.h"
#include "CppTests.h"
#include "Folders.h"
#include "cudas.h"

#include "Videos.h"

#include "TestVideoBase.h"
#include "TestVideoSurface.h"
#include "TestVideoTextureCuarray.h"
#include "TestVideoTextureGM.h"

// #include "TestConvolutionGauss.h"
// #include "TestConvolutionTexGauss.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

using Test::Suite;

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

int mainTest()
    {
    Videos::preloadONE();

    Suite testSuite;

        // Video
        {
        testSuite.add(std::auto_ptr<Suite>(new TestVideoBase()));
        testSuite.add(std::auto_ptr<Suite>(new TestVideoTextureGM()));
        testSuite.add(std::auto_ptr<Suite>(new TestVideoTextureCuarray()));
        testSuite.add(std::auto_ptr<Suite>(new TestVideoSurface()));
        }

        // Convolution
        //	{
        //	testSuite.add(std::auto_ptr < Suite > (new TestConvolutionGauss));
        //	testSuite.add(std::auto_ptr < Suite > (new TestConvolutionTexGauss));
        //	}

        // run
        {
        string folder = "./out";
        string title = "testAll"; // see above, title list
        string fileHTML = title + ".html";

        Folders::mkdirP(folder);

        int result = CppTests::run(folder, fileHTML, title, testSuite, OutputType::HTML); // HTML CONSOLE

        Chrome::showHTML(folder, fileHTML); // to be commented if OutputType::CONSOLE

        return result;
        }
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
