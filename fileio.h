#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @author Andrew Madden (andrewsmadden@gmail.com)
 * 
 * This file contains all the declarations for structs and methods used for file io.
 */

/**
 *  @struct FileData
 *
 *  @brief This structure contains information about the
 *  size and content of a file
 *
 *  @param numbytes the number of char bytes in the file
 *  @param buffer a pointer to the file's character buffer
 */
struct FileData {
    long numbytes;
    char *buffer;
};

/**
 * @brief Reads data from a file into a FileData struct
 * 
 * @param filename A string containing the path to a file
 * 
 * @return A FileData struct with the size and content of the given file
 */
struct FileData read_file(const char *filename);

/**
 * @brief Writes a character buffer into a file
 * 
 * @param filename a string containing the path to a file
 * @param buffer the content to be written to the file
 * 
 * @return Void
 */
void write_file(const char *filename, const char *buffer);

#endif