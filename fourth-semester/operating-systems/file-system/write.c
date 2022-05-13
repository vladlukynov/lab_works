#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#include "functions.h"

int main()
{
    char *filePath = "/home/vladislav/filedata";

    addElement(1, filePath);
    addElement(2, filePath);
    addElement(3, filePath);
    addElement(4, filePath);
    addElement(5, filePath);
    addElement(5, filePath);
    addElement(6, filePath);
    addElement(7, filePath);
    addElement(8, filePath);
    addElement(9, filePath);
    addElement(10, filePath);

    return 0;
}
