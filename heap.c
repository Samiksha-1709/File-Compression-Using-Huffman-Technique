#include "heap.h"

//create new huffman node
node *create_node(unsigned char data, unsigned freq)
{
    //allocate memory for new node
    node *newnode = (node *)malloc(sizeof(node));

    //store character
    newnode->data = data;

    //store freq of character
    newnode->freq = freq;

    //initialize left child pointer
    newnode->left = NULL;

    //initialize right child pointer
    newnode->right = NULL;

    //return newly created node
    return newnode;
}

//create a new min heap
minheap *create_minheap(int capacity)
{
    //allocate memory for heap structure
    minheap *heap = (minheap*)malloc(sizeof(minheap));

    //initialize heap size to 0
    heap->size = 0;

    //set maximum capacity of heap
    heap->capacity = capacity;

    //allocate memory for heap array
    heap->array = (node**)malloc(capacity * sizeof(node*));

    //return created heap
    return heap;
}

//swap nodes
void swap_node(node **a, node **b)
{
    node *temp = *a;
    *a = *b;
    *b = temp;
}

//min heapify
void min_heapify(minheap *heap, int idx)
{
    //assume current node is smallest
    int smallest = idx;

    //calculate left child index
    int left = 2 * idx + 1;

    //calculate right child index
    int right = 2 * idx + 2;

    //check if left child exists and has smaller freq
    if(left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
    //update smallest index
    smallest = left;

    //check if right child exists and has smaller freq
    if(right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
    //update smallest index
    smallest = right;

    //if smallest is not the current node
    if(smallest != idx)
    {
        //swap nodes
        swap_node(&heap->array[smallest], &heap->array[idx]);

        //recursivley heapify affected subtree
        min_heapify(heap, smallest);
    }
}

    //build min heap from array
    void build_minheap(minheap *heap)
    {
        //get last index of heap
        int n = heap->size - 1;

        //start heapifying from last non-leaf node
        for(int i = (n-1) / 2; i >= 0; i--)
        {
            //maintain heap 
            min_heapify(heap,i);
        }
    }

    //extract minimum node
    node *extract_min(minheap *heap)
    {
        //store root node(min element)
        node *temp = heap->array[0];

        //move last node to root
        heap->array[0] = heap->array[heap->size - 1];

        //reduce heap size
        heap->size--;

        //restore heap 
        min_heapify(heap,0);

        //return min node
        return temp;
    }

    //insert node into heap
    void insert_minheap(minheap *heap, node *New)
    {
        //increase heap size
        heap->size++;

    //start from last application
        int i = heap->size - 1;

        //move up while parent freq is larger
        while(i && New->freq < heap->array[(i - 1) / 2]->freq)
        {
            //move parent down
            heap->array[i] = heap->array[(i - 1) / 2];
            //move index to parent
            i = (i - 1) / 2;
        }

        //insert new node at correct position
        heap->array[i] = New;

    }




