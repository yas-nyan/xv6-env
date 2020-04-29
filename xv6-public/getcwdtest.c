#include "types.h"
#include "user.h"

#define MAX_PATH_NUM 512

int
main(int argc, char *argv[])
{
    char path[MAX_PATH_NUM];
    getcwd(path, MAX_PATH_NUM);
    printf(1, "%s\n", path);
    exit();
};
