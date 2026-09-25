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

    double critical(int n)
        {

        const int NB_THREAD = Omps::setAndGetNaturalGranularity();

        const double dx = 1 / (double)n;
        double global_sum = 0;

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

#pragma omp critical
                {
                global_sum += thread_sum;
                }
            }

        return global_sum * dx;
        }

    } // namespace PI::OMP::entrelacement

// -----------------------------------------------------------------------
// End
// -----------------------------------------------------------------------