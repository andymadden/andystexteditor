#include "fileio.h"

struct FileData
read_file(const char *filename)
{
    FILE *f;
    long numbytes;
    char *buffer;

    f = fopen(filename, "r");
    
    fseek(f, 0L, SEEK_END);
    numbytes = ftell(f);
    fseek(f, 0L, SEEK_SET);

    buffer = (char *) calloc(numbytes + 1, sizeof(char));

    fread(buffer, sizeof(char), numbytes, f);
    fclose(f);

    struct FileData ret;
    
    ret.buffer = buffer;
    ret.numbytes = numbytes;

    return ret;
}

void
write_file(const char *filename,
           const char *buffer)
{
    FILE *f;
    f = fopen(filename, "w");

    fputs(buffer, f);
    fclose(f);
}