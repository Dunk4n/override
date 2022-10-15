#include <sys/types.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int main(void)
    {
    int cnt;
    int *iterator;
    char bVar3;
    unsigned int wstatus;
    int buffer[32];
    uint local_20;
    uint local_1c;
    long ptrace_ret;
    pid_t pid;

    bVar3 = 0;
    pid = fork();
    iterator = buffer;
    for (cnt = 32; cnt != 0; cnt--)
        {
        *iterator = 0;
        iterator++;
        }

    ptrace_ret = 0;
    wstatus = 0;
    if (pid == 0)
        {
        prctl(1,1);
        ptrace(PTRACE_TRACEME,0,0,0);
        puts("Give me some shellcode, k");
        gets(buffer);
        }
    else
        {
        do
            {
            wait((int *) &wstatus);
            local_20 = wstatus;
            if (((wstatus & 0x7f) == 0) || (local_1c = wstatus, '\0' < (char)(((char)wstatus & 0x7f) + 1) >> 1))
                {
                puts("child is exiting...");
                return 0;
                }
            ptrace_ret = ptrace(PTRACE_PEEKUSER,pid,0x2c,0);
            } while (ptrace_ret != 0xb);
        puts("no exec() for you");
        kill(pid,9);
        }
    return 0;
    }
