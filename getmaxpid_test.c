#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
    printf(1,"Max Pid of Active Processes: %d\n",get_max_pid());
    exit();
}
