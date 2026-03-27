#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "heap.h"

//buid huffman tree

node *build_huffman_tree(int freq[]);

//print huffman codes
//void print_nodes(node *root, int arr[], int top);

//generate huffman codes and store them
void generate_codes(node *root, int arr[], int top, char *codes[]);
#endif