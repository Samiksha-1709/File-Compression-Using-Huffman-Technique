#include "huffman.h"
#include "heap.h"
#include "compress.h"

//cheak if node is leaf
int is_leaf(node *N)
{
    //return true if both child are null
    return !(N->left) && !(N->right);
}

//build huffman tree
node *build_huffman_tree(int freq[])
{
    int i;
    //create a min heap with capacity MAX_CHAR
    minheap *heap = create_minheap(MAX_CHAR);

    //create nodes for characters with non-zero frequency
    for(i = 0; i < MAX_CHAR; i++)
    {
        //check if character appears in file
        if(freq[i] > 0)
        {
            //create node and add to heap
            heap->array[heap->size++] = create_node(i, freq[i]);
        }
    }

    //convert array into a valid min heap
    build_minheap(heap);

    //repeat until only one node remains in heap
    while(heap->size > 1)
    {
        //extract node with smallest freq
        node *left = extract_min(heap);

        //extract second smallest node
        node *right = extract_min(heap);
 
        //create new internal node
        node *top = create_node('$', left->freq + right->freq);

        //attach left child
        top->left = left;
        //attach right child
        top->right = right;

        //insert new combined node back into heap
        insert_minheap(heap, top);
    }

    

    //remaining node is root of huffman tree
    return extract_min(heap);
    
}

//generate huffman codes
void generate_codes(node *root, int arr[], int top, char *codes[])
{
    //if left child exists
    if(root->left)
    {
        //assign 0 for left edge
        arr[top] = 0;

        //recursively go left 
        generate_codes(root->left, arr, top+1, codes);
    }

    //if right child exists
    if(root->right)
    {
        //assign 1 for right edge
        arr[top] = 1;
        //recursively go right
        generate_codes(root->right, arr, top+1,codes);
    }

    //if leaf node reached. store the huffmane code
    if(is_leaf(root))
    {
        //allocate memory for code string
        codes[root->data] = (char *)malloc(top+1);

        //copy bits from to code string
        for(int i = 0; i < top; i++)
        {
            //convert integer bit to character
            codes[root->data][i] = arr[i] + '0';
        }
        //terminate string
        codes[root->data][top] = '\0';
    }
    
}

/*//print huffman code
void print_nodes(node *root, int arr[], int top)
{
    //if left child exists
    if(root->left)
    {
        //store 0 for left edge
        arr[top] = 0;
        //recursively traverse left
        print_nodes(root->left, arr, top+1);
    }

    //if right child exists
    if(root->right)
    {
        //store 1 for  right edge
        arr[top] = 1;
        //recursively traverse right
        print_nodes(root->right, arr, top+1);
    }

    //if leaf node reached
    if(is_leaf(root))
    {
        //print characters
        printf("%c : ",root->data);
        for(int i = 0; i < top; i++)
        {
            //print its huffman code
            printf("%d",arr[i]);
        }
        printf("\n");
    }
}*/