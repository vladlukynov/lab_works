#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "functions.h"

int main()
{
    char *filePath = "/home/vladislav/filedata";
    readFile(filePath);

    return 0;
}
