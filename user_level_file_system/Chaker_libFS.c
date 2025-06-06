// Chakar_libFS.c
#include <stdio.h>
#include <string.h>
#include "Chaker_libFS.h"

// Max number of files and file size
#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

// Structure to represent a file
typedef struct {
    char name[100];                  // File name
    char content[MAX_FILE_SIZE];    // File content
    int isOpen;                     // 1 if open, 0 if closed
} File;

// In memory file table
File fileTable[MAX_FILES];

// Create a new file if it doesn't exist
int fileCreate(const char* filename) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(fileTable[i].name, filename) == 0)
            return -1; // File already exists
        if (fileTable[i].name[0] == '\0') {
            strcpy(fileTable[i].name, filename);
            return 0; // File created
        }
    }
    return -1; // No space to create file
}

// Open an existing file and return its index
int fileOpen(const char* filename) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(fileTable[i].name, filename) == 0) {
            fileTable[i].isOpen = 1;
            return i; // Return file descriptor
        }
    }
    return -1; // File not found
}

// Write data to an open file
int fileWrite(int fd, const char* buffer, int size) {
    if (fd < 0 || fd >= MAX_FILES || !fileTable[fd].isOpen) return -1;
    strncpy(fileTable[fd].content, buffer, size);
    return size; // Return number of bytes written
}

// Read data from an open file
int fileRead(int fd, char* buffer, int size) {
    if (fd < 0 || fd >= MAX_FILES || !fileTable[fd].isOpen) return -1;
    strncpy(buffer, fileTable[fd].content, size);
    return size; // Return number of bytes read
}

// Close the file
int fileClose(int fd) {
    if (fd < 0 || fd >= MAX_FILES) return -1;
    fileTable[fd].isOpen = 0;
    return 0; // File closed
}

// Delete the file from memory
int fileDelete(const char* filename) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(fileTable[i].name, filename) == 0) {
            fileTable[i].name[0] = '\0';
            fileTable[i].content[0] = '\0';
            fileTable[i].isOpen = 0;
            return 0; // File deleted
        }
    }
    return -1; // File not found
}
