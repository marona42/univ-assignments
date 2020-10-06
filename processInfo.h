struct processInfo
{
    char name[16];
    int pid;
    int ppid;
    enum procstate state;
    uint psize;
    int numberContextSwitches;
};
