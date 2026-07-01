#include <unistd.h>
#include <stdio.h>
#include <string.h>

void* heap_start = NULL;

void* own_malloc (size_t len) {
    void* allocated_address = sbrk(len);
    heap_start = (heap_start == NULL) ? allocated_address : heap_start;
    return allocated_address;
}

int own_free_all() {
    if (heap_start == NULL) return 0;
    brk(heap_start);
    return 1;
}

int main() {
    const char* message = "This is my heap message";
    size_t len = strlen(message) + 1; // don't forget \0
    // otherwise memory will print first and second message
    char* memory = (char*) sbrk(sizeof(char) * len); 
    
    strcpy(memory, message);

    const char* more_message = "Second message!";
    size_t more_len = strlen(more_message) + 1;
    char* more_memory = (char*) sbrk(sizeof(char) * more_len);

    strcpy(more_memory, more_message);
    printf("%s\n", more_memory);
    printf("%s\n", memory);
    brk(more_memory);
    printf("%s\n", memory);
    // printf("%s\n", more_memory); will segfault!

    const char* overwrite = "Overwriting message!";
    size_t over_len = strlen(overwrite) + 1;
    char* over_mem = (char*) sbrk(sizeof(char) * over_len);
    strcpy(over_mem, overwrite);
    printf("%s\n", over_mem);
    



    const char* new_message = "This is a rudimentary malloc!";
    size_t size = strlen(new_message);
    char* address = (char*) own_malloc((size + 1) * sizeof(char)); // \0

    strcpy(address, new_message);
    printf("%i\n",own_free_all());

    return 0;
}