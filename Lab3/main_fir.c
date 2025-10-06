#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fir_filter.h"
#include "coefficients.h"



int main(int argc, char *argv[]){

    
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <lowpass/highpass/bandstop/bandpass>\n", argv[0]);
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    FILE *outfile = fopen(argv[2], "w");
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        fclose(infile);
        return 1;

    }

    const double *filter_taps;

    if (strcmp(argv[3], "lowpass") == 0) filter_taps = lowpass_filter_taps;
    else if (strcmp(argv[3], "highpass") == 0) filter_taps = highpass_filter_taps;
    else if (strcmp(argv[3], "bandpass") == 0) filter_taps = bandpass_filter_taps;
    else if (strcmp(argv[3], "bandstop") == 0) filter_taps = bandstop_filter_taps;
    else { fprintf(stderr, "Unknown filter\n"); return 1; }

    double value = 0;
    size_t length = 0;

    while (fscanf(infile, "%lf", &value) == 1){ // count number of lines
        length++;
    }

    rewind(infile); // reset file pointer to beginning of file


    double *input = malloc(sizeof(double) * length); // allocate memory for input and output arrays
    double *output = malloc(sizeof(double) * length);

    for (size_t i = 0; i < length; i++) {  // read input values from file
        fscanf(infile, "%lf", &input[i]);
    }
    
    fir_filter(input, output, length , filter_taps, outfile);

    free(input);
    free(output);
    fclose(infile);
    fclose(outfile);
}