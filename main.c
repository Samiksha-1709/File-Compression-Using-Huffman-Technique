/*
name = Samiksha Mane
Description = The File Compression Tool using Huffman Coding is a command-line based application 
developed in the C programming language that compresses and decompresses text files efficiently.

The project uses the Huffman Coding algorithm, a lossless data compression technique, 
to reduce the size of input text files by assigning variable-length binary codes to 
characters based on their frequency of occurrence. Characters that appear more frequently 
are assigned shorter codes, while less frequent characters are assigned longer codes,
thereby minimizing the overall file size.

During compression, the program reads the input .txt file, calculates the frequency of 
each character, builds a Huffman tree using a min-heap, generates binary codes, and 
encodes the data into a compressed .huf file along with header information.

During decompression, the program reads the .huf file, reconstructs the Huffman tree
from the stored header, decodes the binary data, and recreates the original text file 
without any loss of information.

 */


#include "main.h"
#include "compress.h"
#include "huffman.h"
#include "heap.h"
#include <stdio.h>


// function to check whether input file has .txt extension
int check_txt_file(char *filename)
{
    // find the last '.' character in filename
    char *ext = strrchr(filename, '.');

    // check if extension exists and equals ".txt"
    if(ext != NULL && strcmp(ext, ".txt") == 0)
    {
        // return success if file is .txt
        return SUCCESS;
    }

    // otherwise return failure
    else
    {
        return FAILURE;
    }
}


// main function with command line arguments
int main(int argc, char *argv[])
{
    printf("\n=================================================\n");
    printf("           HUFFMAN FILE COMPRESSION TOOL\n");
    printf("              (Text File Utility)\n");
    printf("-------------------------------------------------\n");
    printf("   Project: Huffman Coding Based Compression\n");
    printf("=================================================\n");
    // check if correct number of arguments are passed
    if(argc != 4)
    {
        // print usage instructions
        printf("\nUsage : \n");

        // show compression command format
        printf("./a.out -c <input.txt> <output.huf>\n");

        // show decompression command format
        printf("./a.out -d <input.huf> <output.txt>\n");

        // return failure if arguments are incorrect
        return FAILURE;
    }


    // check if compression mode is selected
    if(strcmp(argv[1], "-c") == 0)
    {
        // print compression banner
        printf("\n====================================\n");
        printf("        HUFFMAN COMPRESSION\n");
        printf("====================================\n");

        // display selected mode
        printf("Compression Mode Selected\n");

        // check if input file is .txt
        if(check_txt_file(argv[2]) == FAILURE)
        {
            // print error message
            printf("\nError : Please Upload Only .txt File Format.\n");

            // stop program if wrong file type
            return FAILURE;
        }

        // call compression function
        if(compress_file(argv[2], argv[3]) == SUCCESS)
        {
            // print success banner
            printf("\n====================================\n");
            printf("   COMPRESSION COMPLETED SUCCESSFULLY\n");
            printf("====================================\n");
        }

        // print failure message if compression fails
        else
        {
            printf("\nFailed To Compress The File.\n");
        }
    }


    // check if decompression mode is selected
    else if(strcmp(argv[1], "-d") == 0)
    {
        // print decompression banner
        printf("\n====================================\n");
        printf("       HUFFMAN DECOMPRESSION\n");
        printf("====================================\n");

        // display selected mode
        printf("Decompression Mode Selected\n");

        // call decompression function
        if(decompress_file(argv[2], argv[3]) == SUCCESS)
        {
            // print success banner
            printf("\n====================================\n");
            printf("   DECOMPRESSION COMPLETED SUCCESSFULLY\n");
            printf("====================================\n");
        }

        // print failure message if decompression fails
        else
        {
            printf("\nFailed to Decompress The File.\n");
        }
    }


    // if invalid option provided
    else
    {
        // print error message
        printf("Invalid Option\n");

        // show correct usage options
        printf("\nUse '-c' For Compression.\n");
        printf("Use '-d' For Decompression.\n");

        // return failure
        return FAILURE;
    }

    // return success if program finishes correctly
    return SUCCESS;
}