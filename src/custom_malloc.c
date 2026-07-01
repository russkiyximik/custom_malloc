#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>


/*
* Data structures
*/

struct block_meta {
    size_t size; // payload size
    bool free;
    struct block_meta* next;
    // 24 bytes?
};

void* heap_start = NULL;


/*
* Function implementation
*/

void *an_malloc(size_t size) {
    // creates block with payload of size 'size'
    void* block_start = sbrk(sizeof(struct block_meta) + size);
    struct block_meta* meta_start = block_start;
    meta_start->size=size; meta_start->free=0; meta_start->next=NULL;

    return (void*)(meta_start + sizeof(struct block_meta));
    // or return (void*) (meta_start + 1)
}




int main() {
    printf("Size of block_meta: %zu\n", sizeof(struct block_meta));
    int* a = (int*) an_malloc(sizeof(int));
    *a = 42;
    printf("%d\n", *a);

    return 0;
}