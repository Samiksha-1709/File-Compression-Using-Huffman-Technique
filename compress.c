#include "main.h"
#include "compress.h"
#include "huffman.h"


// main compression function
int compress_file(char *input_file, char *output_file)
{
    // declare file pointers
    FILE *fptr_input;
    FILE *fptr_output;

    // create frequency array and initialize to 0
    int freq[MAX_CHAR] = {0};

    // open input file in binary read mode
    fptr_input = fopen(input_file, "rb");

    // display input file name
    printf("\nInput File  : %s\n", input_file);

    // check if input file opened successfully
    if(fptr_input == NULL)
    {
        // print error if file cannot open
        printf("\nError : Unable to open input file❌.\n");

        // return failure
        return FAILURE;
    }

    // create compressed output file in binary write mode
    fptr_output = fopen(output_file, "wb");

    // display output file name
    printf("Output File : %s\n", output_file);

    // check if output file created successfully
    if(fptr_output == NULL)
    {
        // print error if output file cannot be created
        printf("\nError : Unable to create output file❌.\n");

        // return failure
        return FAILURE;
    }

    // message showing input file opened successfully
    printf("\nInput file opened successfully✅.\n");

    // message showing compressed file created successfully
    printf("\nCompressed file created successfully✅.\n");

    // call function to calculate character frequencies
    calculate_frequency(fptr_input, freq);

    // declare Huffman tree root pointer
    node *root;

    // array to store Huffman path bits
    int arr[100];

    // variable to track depth in tree
    int top = 0;

    // array to store Huffman codes for characters
    char *codes[256] = {NULL};

    // build Huffman tree using frequency table
    printf("[STEP 2] Building Huffman Tree🔃.\n");
    root = build_huffman_tree(freq);
    
    // display step message for generating codes
    printf("[STEP 3] Generating Huffman Codes🔃.\n");

    // generate Huffman codes
    generate_codes(root, arr, top, codes);

    // print Huffman codes for verification
   // print_nodes(root, arr, top);

    // write header information to compressed file
    write_header(fptr_output, freq);

    // encode original file data using Huffman codes
    encode_data(fptr_input, fptr_output, codes);

    // close input file
    fclose(fptr_input);

    // close output file
    fclose(fptr_output);

    // return success
    return SUCCESS;
}


// STEP 1: calculate frequency of each character
void calculate_frequency(FILE *fptr_input, int freq[])
{
    // variable to store byte read from file
    unsigned char byte;

    // read file byte by byte
    while(fread(&byte, 1, 1, fptr_input) == 1)
    {
        // increase frequency count
        freq[byte]++;
    }

    // move file pointer back to beginning
    rewind(fptr_input);

    // display step message
    printf("\n[STEP 1] Calculating Character Frequencies🔃.\n");
}


// STEP 4: write header to compressed file
void write_header(FILE *fptr_output, int freq[])
{
    // variable to count unique characters
    int unique = 0;

    // count how many characters appear in file
    for(int i = 0; i < MAX_CHAR; i++)
    {
        // check if frequency is greater than zero
        if(freq[i] > 0)
            unique++;
    }

    // write number of unique characters
    fwrite(&unique, sizeof(int), 1, fptr_output);

    // loop through all characters
    for(int i = 0; i < MAX_CHAR; i++)
    {
        // check if character appears in file
        if(freq[i] > 0)
        {
            // store character
            unsigned char ch = i;

            // write character to header
            fwrite(&ch, 1, 1, fptr_output);

            // write frequency to header
            fwrite(&freq[i], sizeof(int), 1, fptr_output);
        }
    }

    // display step message
    printf("[STEP 4] Writing Header🔃.\n");
}


// STEP 5: encode input file using Huffman codes
void encode_data(FILE *fptr_input, FILE *fptr_output, char *codes[])
{
    // variable to store byte from input file
    unsigned char byte;

    // buffer used to pack bits
    unsigned char buffer = 0;

    // counter for number of bits stored in buffer
    int bit_count = 0;

    // read input file byte by byte
    while(fread(&byte, 1, 1, fptr_input) == 1)
    {
        // get Huffman code for this character
        char *code = codes[byte];

        // process each bit of the code
        for(int i = 0; code[i] != '\0'; i++)
        {
            // shift buffer left by 1 bit
            buffer = buffer << 1;

            // if code bit is 1 set buffer bit
            if(code[i] == '1')
                buffer |= 1;

            // increase bit count
            bit_count++;

            // if buffer is full write to file
            if(bit_count == 8)
            {
                // write buffer byte
                fwrite(&buffer, 1, 1, fptr_output);

                // reset buffer
                buffer = 0;

                // reset bit counter
                bit_count = 0;
            }
        }
    }

    // if remaining bits exist pad and write
    if(bit_count > 0)
    {
        // shift remaining bits to fill byte
        buffer = buffer << (8 - bit_count);

        // write last byte
        fwrite(&buffer, 1, 1, fptr_output);
    }

    // display step message
    printf("[STEP 5] Encoding Data🔃.\n");
}