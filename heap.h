#ifndef HEAP_H
#define HEAP_H

#include "main.h"

//huffman tree node
typedef struct node
{
    unsigned char data;
    unsigned freq;
    struct node *left;
    struct node *right;
    
}node;

//min heap structure
typedef struct minheap
{
    int size;
    int capacity;
    node **array;

}minheap;


//function prototype
node *create_node(unsigned char data, unsigned freq);

minheap *create_minheap(int capacity);

void swap_node(node **a, node **b);

void min_heapify(minheap *heap, int idx);

node *extract_min(minheap *heap);

void insert_minheap(minheap *heap, node *Node);

void build_minheap(minheap *heap);



#endif