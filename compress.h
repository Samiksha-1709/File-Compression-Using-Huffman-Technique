#ifndef COMPRESS_H
#define COMPRESS_H

#include "main.h"

//compression function
int compress_file(char *input_file, char *output_file);

//calculate frequency of each byte
void calculate_frequency(FILE *fptr_input, int freq[]);

//header information to compress file
void write_header(FILE *fptr_output, int freq[]);

//encode input data using huffman code
void encode_data(FILE *fptr_input, FILE *fptr_output, char *codes[]);
#endif