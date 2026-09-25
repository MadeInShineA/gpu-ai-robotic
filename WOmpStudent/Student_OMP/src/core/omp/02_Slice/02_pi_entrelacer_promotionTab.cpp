#include <omp.h>

#include "Omps.h"

// -----------------------------------------------------------------------
// Extern
// -----------------------------------------------------------------------

namespace PI
    {
    double f(double x);
    }

// -----------------------------------------------------------------------
// Implementations
// -----------------------------------------------------------------------

namespace PI::OMP::entrelacement
    {

    double promotionTab(int n)
        {
        const int NB_THREAD = Omps::setAndGetNaturalGranularity();

        double thread_array[NB_THREAD];
        const double dx = 1 / (double)n;

#pragma omp parallel
            {

            const int tid = Omps::getTid();

            int slice = tid;

            double thread_sum = 0;
            double x_slice;

            while (slice < n)
                {

                x_slice = slice * dx;
                thread_sum += f(x_slice);

                slice += NB_THREAD;
                }

            thread_array[tid] = thread_sum;
            }

        double sum = 0;

        for (int i = 0; i < NB_THREAD; i++)
            {
            sum += thread_array[i];
            }

        return sum * dx;

        } // promotionTab

    } // namespace PI::OMP::entrelacement

// -----------------------------------------------------------------------
// End
// -----------------------------------------------------------------------