#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

#define COMPRESS "-c"
#define DECOMPRESS "-d"

#define MAX_CHAR 256

/* Function prototypes */

//compression function prototype
int compress_file(char *input_file, char *output_file);

//decompression function prototype
int decompress_file(char *input_file, char *output_file);

//function to check if input file .txt
int check_txt_file(char *filename);

#endif