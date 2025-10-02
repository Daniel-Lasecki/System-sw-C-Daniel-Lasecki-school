#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc!=3){
        fprintf(stderr,"how to use <input file> <output file>\n");
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

    // FIR filter coefficients for a low-pass filter
   
    float coeffs[5] = {1, 2, 3, 4, 5};
    int num_taps = sizeof(coeffs) / sizeof(coeffs[0]);
    
    // Buffer to hold previous samples for filtering
    float *buffer = (float *)calloc(num_taps, sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(infile);
        fclose(outfile);
        return 1;
    }
    
    size_t buffer_index = 0;
    float sample;
    
    while (fread(&sample, sizeof(float), 1, infile) == 1) {
        buffer[buffer_index] = sample;
        
        // Apply FIR filter
        float filtered_sample = 0.0f;
        for (int i = 0; i < num_taps; i++) {
            int index = (buffer_index - i + num_taps) % num_taps;
            filtered_sample += coeffs[i] * buffer[index];
        }
        
        
        printf("%f\n", filtered_sample);
        fprintf(outfile, "%f\n", filtered_sample); // Write as text

        
        buffer_index = (buffer_index + 1) % num_taps;
    }
    
    free(buffer);
    fclose(infile);
    fclose(outfile);
    
    return 0;
}




