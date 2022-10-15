#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/ptrace.h>

int auth(char *login,uint serial)
    {
    size_t size;
    int ret;
    int cnt;
    uint calculated_serial;

    size = strcspn(login,"\n");
    login[size] = '\0';
    size = strnlen(login,32);
    if ((int)size < 6)
        {
        ret = 1;
        }
    else
        {
        if (ptrace(PTRACE_TRACEME) == -1)
            {
            puts("\x1b[32m.---------------------------.");
            puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
            puts("\x1b[32m\'---------------------------\'");
            ret = 1;
            }
        else
            {
            calculated_serial = ((int)login[3] ^ 0x1337U) + 0x5eeded;
            for (cnt = 0; cnt < (int)size; cnt++)
                {
                if (login[cnt] < ' ')
                    return 1;
                calculated_serial = calculated_serial + ((int)login[cnt] ^ calculated_serial) % 0x539;
                }

            if (serial == calculated_serial)
                {
                ret = 0;
                }
            else
                {
                ret = 1;
                }
            }
        }
    return ret;
    }

int main(void)
    {
    int ret;
    char login[32];
    unsigned int serial;

    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");
    printf("-> Enter Login: ");
    fgets(login,32,stdin);
    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");
    printf("-> Enter Serial: ");
    scanf("%u", &serial);
    ret = auth(login, serial);
    if (ret == 0)
        {
        puts("Authenticated!");
        system("/bin/sh");
        }
    return ret != 0;
    }
