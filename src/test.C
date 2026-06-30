#include <unistd.h>
#include <stdio.h>
#include <string.h>

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

    return 0;
}