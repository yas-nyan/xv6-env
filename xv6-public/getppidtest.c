#include "types.h"
#include "user.h"


int main(void)
{
    int ppid = getppid();
    printf(1, "PPID: %d\n", ppid);
    exit();
}
