#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "Chrome.h"
#include "CppTests.h"
#include "Folders.h"
#include "cudas.h"

#include "Videos.h"

#include "TestWarmup.h"

#include "TestTutoSurface.h"
#include "TestTutoTextureCuarray.h"
#include "TestTutoTextureGM.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

using Test::Suite;

// --------------------------------------------------------------------------------------
// Implementations
// --------------------------------------------------------------------------------------

int mainTest()
    {
    Videos::preloadONE();

    Suite testSuite;

    testSuite.add(std::unique_ptr<Suite>(new TestWarmup()));
    testSuite.add(std::unique_ptr<Suite>(new TestTutoTextureGM()));
    testSuite.add(std::unique_ptr<Suite>(new TestTutoTextureCuarray()));
    testSuite.add(std::unique_ptr<Suite>(new TestTutoSurface()));

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

// ---------------------------------------------------------------------------
// End
// ---------------------------------------------------------------------------
