// Chakar_testFS.c
#include <stdio.h>
#include <string.h>
#include "Chaker_libFS.h"

// Displays a simple menu to guide user actions
void menu() {
    printf("\n1. Create File\n2. Open File\n3. Write Intro\n4. Read File\n5. Close File\n6. Delete File\n0. Exit\n> ");
}

int main() {
    int choice, fd = -1;
    const char* filename = "Chaker_Introduction.txt";

    // Intro content to be written to the file
    const char* intro =
        "Hello! My name is Chaker Baloch.\n"
        "I'm a Computer Science student passionate about systems programming and software design.\n\n"
        "In this file system project, I'm learning how to manage files at a low level.\n"
        "I enjoy building backend services and experimenting with C and operating system internals.\n";

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // clears newline after numeric input

        switch (choice) {
            case 1:
                if (fileCreate(filename) == 0)
                    printf("File created.\n");
                else
                    printf("File already exists or could not be created.\n");
                break;
            case 2:
                fd = fileOpen(filename);
                if (fd >= 0)
                    printf("File opened. FD: %d\n", fd);
                else
                    printf("File not found.\n");
                break;
            case 3:
                if (fd >= 0 && fileWrite(fd, intro, strlen(intro)) > 0)
                    printf("Introduction written.\n");
                else
                    printf("Open the file first.\n");
                break;
            case 4:
                if (fd >= 0) {
                    char readBuffer[1024] = {0};
                    if (fileRead(fd, readBuffer, sizeof(readBuffer)) > 0)
                        printf("File content:\n%s\n", readBuffer);
                    else
                        printf("Failed to read from file.\n");
                } else {
                    printf("Open the file first.\n");
                }
                break;
            case 5:
                if (fileClose(fd) == 0) {
                    printf("File closed.\n");
                    fd = -1;
                } else {
                    printf("Failed to close.\n");
                }
                break;
            case 6:
                if (fileDelete(filename) == 0)
                    printf("File deleted.\n");
                else
                    printf("Failed to delete file.\n");
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
