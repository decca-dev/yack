#include "../include/yackfiles.h"
#include "../include/yackstring.h"
#include <stdio.h>

// Get file size
int fileSize(FILE *file)
{
    int size;
    // Reset pointer to the start of the file, just to be safe
    rewind(file);
    // Move pointer to the end of the file
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    // Reset pointer
    rewind(file);
    return size;
}