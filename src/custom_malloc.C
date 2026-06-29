#include <malloc.h>
#include <stdbool.h>


/*
* Data structures
*/

struct free_area {
    unsigned int marker; // 4 bytes
    struct free_area* prev; // 8 bytes, previous ptr
    bool in_use; // 1 byte
    unsigned int length; // 4 bytes
    struct free_area* next; // 8 bytes
    // total: 32 bytes.
};

struct stats {
    int magical_bytes; // what does this do?
    bool lock; // prevents thread interference
    unsigned int amt_of_blocks;
    unsigned int amt_of_pages;
    // 16 bytes
};
const int MAGICAL_BYTES = 0X55;
const int BLOCK_MARKER = 0xDD;


/*
* Function implementation
*/

int *an_malloc(size_t size) {
    // sbrk (Set Break) is a Unix system call
    // used to manage dynamic memory allocation
    // by changing the location of the program break
    if (heap_start == NULL) {
        heap_start = sbrk(0);
        sbrk(4096);
    }
    char* heap_end = sbrk(0);
    int length = heap_end - heap_start;

    if ((*heap_start) != MAGICAL_BYTES) {
        *(heap_start) = MAGICAL_BYTES;
        stats* malloc_header = (stats*) heap_start;
    }
}




int main() {
    printf("Size of free_area: %zu\n", sizeof(struct free_area));
    printf("Size of stats: %zu\n", sizeof(struct stats));

    return 0;
}