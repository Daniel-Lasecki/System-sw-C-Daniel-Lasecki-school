#ifndef FIR_FILTER_H
#define FIR_FILTER_H

#include <stdio.h>



void fir_filter(double *input, double *output, size_t length, const double *filter_taps, FILE *outfile);

#endif
