#include "MontecarloStream.h"

#include <assert.h>
#include <iostream>

#include "Hardware.h"
#include "Montecarlo.h"
#include "Stream.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

using montecarlo::entier;
using montecarlo::entierToString;

// --------------------------------------------------------------------------------------
//  Implementations
// --------------------------------------------------------------------------------------

/**
 * static
 */
int MontecarloStream::NB_DEVICE = Hardware::getDeviceCount();

// ---------------------------------------------------------------------------
// Constructors
// ---------------------------------------------------------------------------

MontecarloStream::MontecarloStream(const Grid &grid, entier nbDarTotalAsk, double *ptrPiHat, float h, bool isVerbose)
    : RunnableGPU(grid, title(nbDarTotalAsk, h), isVerbose), // classe parente
                                                             //
      nbDarTotalAsk(nbDarTotalAsk),                          //
      ptrPiHat(ptrPiHat),                                    //
      h(h),                                                  //
      grid(grid)
    {
    this->nbDarByDevice = nbDarTotalAsk / NB_DEVICE;
    assert(nbDarByDevice >= grid.threadCounts());

    this->tabStream = new cudaStream_t[NB_DEVICE];
    this->tabMontecarlo = new Montecarlo *[NB_DEVICE];

    const int DEVICE_ID_ORIGINAL = Hardware::getDeviceId();

    for (int deviceID = 0; deviceID < NB_DEVICE; deviceID++)
        {
        // obligatoire de creer stream sur bon device
        // obligatoire de crere Montecarlo sur bon device, car Montecarlo fait du MM
        Hardware::setDevice(deviceID);

        Stream::create(&tabStream[deviceID]);
        tabMontecarlo[deviceID] = new Montecarlo(grid, nbDarByDevice, ptrPiHat, h, isVerbose);
        }

    Hardware::setDevice(DEVICE_ID_ORIGINAL); // restore deviceID
    }

MontecarloStream::~MontecarloStream()
    {
    const int DEVICE_ID_ORIGINAL = Hardware::getDeviceId();

    for (int deviceID = 0; deviceID < NB_DEVICE; deviceID++)
        {
        Hardware::setDevice(deviceID); // facultatif pour delele Montecarlo et destroy stream

        delete tabMontecarlo[deviceID];
        Stream::destroy(tabStream[deviceID]);
        }

        // tableaux
        {
        delete[] tabStream;
        delete[] tabMontecarlo;
        }

    Hardware::setDevice(DEVICE_ID_ORIGINAL); // restore deviceID
    }

// --------------------------------------------------------------------------------------
// Methodes
// --------------------------------------------------------------------------------------

void MontecarloStream::run()
    {
    const int DEVICE_ID_ORIGINAL = Hardware::getDeviceId();

    for (int deviceID = 0; deviceID < NB_DEVICE; deviceID++)
        {
        // recuperation:
        Montecarlo *ptrMontecarlo = tabMontecarlo[deviceID];
        cudaStream_t stream = tabStream[deviceID];

        // TODO MontecarloMulti-stream
        // Appeler sur le bon device kernel_async de montecarlo mono
        }

    for (int deviceID = 0; deviceID < NB_DEVICE; deviceID++)
        {
        // recuperation:
        Montecarlo *ptrMontecarlo = tabMontecarlo[deviceID];
        cudaStream_t stream = tabStream[deviceID];

        // TODO MontecarloMulti-stream
        // Appeler sur le bon device DtoH_async de montecarlo mono
        }

    for (int deviceID = 0; deviceID < NB_DEVICE; deviceID++)
        {
        // TODO MontecarloMulti-stream
        // synchroniser chacune des streams (Stream:: ...)
        }

    Hardware::setDevice(DEVICE_ID_ORIGINAL); // restore deviceID

        // host consolidation
        {
        this->nbDarTotalEffective = 0;
        entier nbDarUnderCurve = 0;

        for (int deviceID = 0; deviceID < NB_DEVICE; deviceID++)
            {
            // TODO MontecarloMulti-stream
            // update nbDarUnderCurve
            // update nbDarTotalEffective
            }

        *this->ptrPiHat = this->h * nbDarUnderCurve / this->nbDarTotalEffective;
        }
    }

// --------------------------
// get
// --------------------------

entier MontecarloStream::getNbDarTotalEffective()
    {
    return nbDarTotalEffective;
    }

double MontecarloStream::getInputGO()
    {
    return (nbDarTotalEffective / (double)1024 / (double)1024 / (double)1024) * sizeof(float) * 2;
    }

// --------------------------
// set
// --------------------------

void MontecarloStream::setH(float h)
    {
    this->h = h;
    }

// --------------------------
// Private
// --------------------------

string MontecarloStream::title(entier nbDarTotalAsk, float h)
    {
    return "Montecarlo_" + entierToString() + "_stream_" + to_string(nbDarTotalAsk) + "_h" + to_string((int)h);
    }

// --------------------------------------------------------------------------------------
//  End
// --------------------------------------------------------------------------------------
