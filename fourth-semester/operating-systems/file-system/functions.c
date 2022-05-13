#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "functions.h"

void addElement(int element, char *filePath)
{
    int fd = open(filePath, O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "Open file error: %i", errno);
    }

    ssize_t fileSize = getFileSize(filePath);
    lseek(fd, fileSize, SEEK_CUR);

    write(fd, &element, sizeof(int));
    close(fd);
}

ssize_t getFileSize(char *filePath)
{
    struct stat st;
    stat(filePath, &st);
    return st.st_size;
}

void readFile(char *filePath)
{
    int fd = open(filePath, O_RDWR);
    if (fd == -1)
    {
        fprintf(stderr, "Open file error: %i", errno);
    }

    ssize_t size = getFileSize(filePath);
    int *array = malloc(size);
    read(fd, array, size);
    for (int i = 0; i < size / sizeof(int); i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");

    free(array);
    close(fd);
}
