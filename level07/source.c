#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

void clear_stdin(void)
    {
    int tmp;

    do
        {
        tmp = getchar();
        if ((char)tmp == '\n')
            {
            return;
            }
        } while ((char)tmp != -1);
    return;
    }

int get_unum(void)
{
  int unum[3];

  unum[0] = 0;
  fflush(stdout);
  scanf("%u", unum);
  clear_stdin();
  return unum[0];
}

int read_number(int *storage)
{
  int index;

  printf(" Index: ");
  index = get_unum();
  printf(" Number at data[%u] is %u\n", index, storage[index]);
  return 0;
}

int store_number(int *storage)
    {
    uint number;
    uint index;
    int ret;

    printf(" Number: ");
    number = get_unum();
    printf(" Index: ");
    index = get_unum();
    if ((index % 3 == 0) || (number >> 24 == 183))
        {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");
        ret = 1;
        }
    else
        {
        (int *) ((intptr_t)storage + (index * 4)) = number;
        ret = 0;
        }
    return ret;
    }

int main(int argc,char **argv,char **env)
    {
    char tmp;
    int cnt;
    uint len;
    int *it_command;
    char *str_iterator;
    char *it_str;
    bool bVar7;
    bool bVar8;
    bool bVar9;
    char **saved_env;
    char **saved_argv;
    int storage[100];
    int ret;
    int command[5];

    saved_argv = argv;
    saved_env = env;

    ret = 0;
    command[0] = 0;
    command[1] = 0;
    command[2] = 0;
    command[3] = 0;
    command[4] = 0;

    it_command = storage;
    for (cnt = 100; cnt != 0; cnt--)
        {
        *it_command = 0;
        it_command++;
        }

    for (; *saved_argv != (char *)0x0; saved_argv++)
        {
        len = 0xffffffff;
        str_iterator = *saved_argv;
        do
            {
            if (len == 0)
                break;
            len--;
            tmp = *str_iterator;
            str_iterator = str_iterator + 1;
            } while (tmp != '\0');
        memset(*saved_argv, 0, ~len - 1);
        }

    for (; *saved_env != (char *)0x0; saved_env = saved_env + 1)
        {
        len = 0xffffffff;
        str_iterator = *saved_env;
        do
            {
            if (len == 0)
                break;
            len = len - 1;
            tmp = *str_iterator;
            str_iterator = str_iterator + 1;
            } while (tmp != '\0');
        memset(*saved_env,0,~len - 1);
        }

    puts("----------------------------------------------------\n  Welcome to wil\'s crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n");

    do
        {
        printf("Input command: ");
        ret = 1;
        fgets((char *)command, 20, stdin);

        len = 0xffffffff;
        it_command = command;
        do
            {
            if (len == 0)
                break;
            len--;
            tmp = *(char *)it_command;
            it_command = (int *)((intptr_t)it_command + 1);
            } while (tmp != '\0');

        len = ~len;
        bVar7 = len == 1;
        bVar9 = len == 2;
        *(char *)((intptr_t)&ret + len + 2) = 0;

        cnt = 5;
        it_command = command;
        it_str = (char *)"store";
        do
            {
            if (cnt == 0)
                break;
            cnt = cnt + -1;
            bVar7 = *(char *)it_command < *it_str;
            bVar9 = *(char *)it_command == *it_str;
            it_command = (int *)((intptr_t)it_command + 1);
            it_str = it_str + 1;
            } while (bVar9);

        bVar8 = false;
        bVar7 = (!bVar7 && !bVar9) == bVar7;

        if (bVar7)
            {
            ret = store_number(storage);
            }
        else
            {
            cnt = 4;
            it_command = command;
            it_str = "read";
            do
                {
                if (cnt == 0)
                    break;
                cnt = cnt + -1;
                bVar8 = *(char *)it_command < *it_str;
                bVar7 = *(char *)it_command == *it_str;
                it_command = (int *)((intptr_t)it_command + 1);
                it_str = it_str + 1;
                } while (bVar7);

            bVar9 = false;
            bVar7 = (!bVar8 && !bVar7) == bVar8;

            if (bVar7)
                {
                ret = read_number(storage);
                }
            else
                {
                cnt = 4;
                it_command = command;
                it_str = "quit";
                do
                    {
                    if (cnt == 0)
                        break;
                    cnt = cnt + -1;
                    bVar9 = *(char *)it_command < *it_str;
                    bVar7 = *(char *)it_command == *it_str;
                    it_command = (int *)((intptr_t)it_command + 1);
                    it_str = it_str + 1;
                    } while (bVar7);

                if ((!bVar9 && !bVar7) == bVar9)
                    {
                    return 0;
                    }
                }
            }

        if (ret == 0)
            {
            printf(" Completed %s command successfully\n", (char *) command);
            }
        else
            {
            printf(" Failed to do %s command\n", (char *) command);
            }

        command[0] = 0;
        command[1] = 0;
        command[2] = 0;
        command[3] = 0;
        command[4] = 0;
        } while( true );
    }
