// Chakar_libFS.h
#ifndef CHAKER_LIBFS_H
#define CHAKER_LIBFS_H

// Create a new file
int fileCreate(const char* filename);

// Open an existing file
int fileOpen(const char* filename);

// Write data to a file
int fileWrite(int fd, const char* buffer, int size);

// Read data from a file
int fileRead(int fd, char* buffer, int size);

// Close an open file
int fileClose(int fd);

// Delete a file
int fileDelete(const char* filename);

#endif
