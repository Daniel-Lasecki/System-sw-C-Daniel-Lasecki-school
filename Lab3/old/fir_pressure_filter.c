#include <stdio.h>
#include <stdlib.h>

#define NUM_TAPS 22 // Number of filter taps

int main(int argc, char *argv[]) {


    int buffer_index = 0;
    float sample;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *infile = fopen(argv[1], "rb");
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    FILE *outfile = fopen(argv[2], "wb");
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        fclose(infile);
        return 1;
    }

    

    // Example FIR filter coefficients (replace with your actual coefficients)
    float coeffs[NUM_TAPS] = {
        0.0181, 0.0234, 0.0302, 0.0385, 0.0481, 0.0587, 0.0700, 0.0815, 0.0927, 0.1032, 0.1125,
        0.1202, 0.1259, 0.1294, 0.1306, 0.1294, 0.1259, 0.1202, 0.1125, 0.1032, 0.0927, 0.0815
    };


    // Buffer to hold previous samples for filtering
    float *buffer = calloc(NUM_TAPS, sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(infile);
        fclose(outfile);
        return 1;
    }

    // Process input file sample by sample
    while (fread(&sample, sizeof(float), 1, infile) == 1) {
        buffer[buffer_index] = sample;

        // Apply FIR filter
        float filtered_sample = 0.0f;
        for (int i = 0; i < NUM_TAPS; i++) {
            int index = (buffer_index - i + NUM_TAPS) % NUM_TAPS;
            filtered_sample += coeffs[i] * buffer[index];
            
        }

        // Write filtered sample to output
        fprintf(outfile, "%f\n", filtered_sample);


        buffer_index = (buffer_index + 1) % NUM_TAPS;
    }

    free(buffer);
    fclose(infile);
    fclose(outfile);

    return 0;
}
