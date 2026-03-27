#include "decompress.h"
#include "huffman.h"
#include "main.h"


//main decompression function
int decompress_file(char *input_file, char *output_file)
{
    //open compressed file in binary read
    FILE *in = fopen(input_file, "rb");
    if(in == NULL)
    {
        printf("\nError : Unable To Open Compressed File.\n");
        return FAILURE;
    }

    //create output text file
    FILE *out = fopen(output_file, "w");
    if(out == NULL)
    {
        printf("\nError : Unable To Create Output File.\n");
        fclose(in);
        return FAILURE;
    }

    //array to stroe frequency of characters
    int freq[MAX_CHAR] = {0};
    //variable to store number of unique characters
    int unique;

    printf("\n[STEP 1] Reading Header🔃\n");
    //read number of unique characters from header
    fread(&unique, sizeof(int), 1 , in);

    //read character-frequency pairs from header
    for(int i = 0; i < unique; i++)
    {
        //varibale to store characyer
        unsigned char ch;

        //variable to store frequnecy
        int f;

        //read character
        fread(&ch, 1, 1, in);

        //read frequency
        fread(&f, sizeof(int), 1, in);

        //store frequency in freq array
        freq[ch] = f;
    }

    //rebuild huffman trqq using frequency array
    printf("\n[STEP 2] Rebuilding Huffman Tree🔃\n");
    node *root = build_huffman_tree(freq);

    //pointer used to traverse huffman tree
    node *current = root;

    //variabel to store encoded byte
    unsigned char byte;

    //total characters in original file
    int total_chars = 0;

    //calculate total characters from frequency table
    for(int i = 0; i < MAX_CHAR; i++)
    {
        //add all frequency
        total_chars = total_chars + freq[i];
    }

    //counter for decoded characters
    int decoded = 0;

    printf("\n[STEP 3] Decoding compressed data🔃\n");
    //read compressed data byte by byte
    while(decoded < total_chars && fread(&byte, 1, 1, in) == 1)
    {
        //process each bit in the byte
        for(int i = 7; i >= 0; i--)
        {
            //extract individual bit
            int bit = (byte >> i) & 1;

            //if bit is 0 move left in tree
            if(bit == 0)
            current = current->left;

            //if bit is 1 move right in tree
            else
            current = current->right;

            //check if leaf node reached
            if(current->left == NULL && current->right == NULL)
            {
                //write decoded character to output
                fputc(current->data, out);
                //increase decoded character count
                decoded++;

                //stop if all characters decode
                if(decoded == total_chars)
                break;

                //reset pointer to root for next character
                current = root;
            }
        }
    }

    //close compressed file
    fclose(in);
    //close output file
    fclose(out);

    printf("\nDecompression Completed SuccessFully.\n");

    return SUCCESS;


}