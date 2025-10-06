#include "fir_filter.h"
#include "coefficients.h"

void fir_filter(double *input, double *output, size_t length,
                const double *filter_taps, FILE *outfile)
{
    for (int n = 0; n < length; n++) {
        output[n] = 0.0;

        for (size_t k = 0; k < FILTER_TAP_NUM; k++) {
            if (n - k >= 0) {
                output[n] += filter_taps[k] * input[n - k];
            }
        }

        fprintf(outfile, "%lf\n", output[n]);
    }
}