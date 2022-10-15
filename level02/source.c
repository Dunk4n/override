#include <stdlib.h>
#include <string.h>
#include <stdio.h>

long main(void)
    {
    int cmp_ret;
    size_t size;
    long cnt;
    long *iterator;
    long password_buff [14];
    long flag_buff [6];
    long username_buff [12];
    int size_tmp;
    FILE *flag_file;

    iterator = username_buff;
    for (cnt = 0xc; cnt != 0; cnt = cnt + -1) {
        *iterator = 0;
        iterator = iterator + 1;
    }
    *(int *)iterator = 0;
    iterator = flag_buff;
    for (cnt = 5; cnt != 0; cnt = cnt + -1) {
        *iterator = 0;
        iterator = iterator + 1;
    }
    *(char *)iterator = 0;
    iterator = password_buff;
    for (cnt = 0xc; cnt != 0; cnt = cnt + -1) {
        *iterator = 0;
        iterator = iterator + 1;
    }
    *(int *)iterator = 0;

    flag_file = (FILE *)0x0;
    size_tmp = 0;
    flag_file = fopen("/home/users/level3/.pass","r");
    if (flag_file == (FILE *)0x0) {
        fwrite("ERROR: failed to open password file\n",1,0x24,stderr);
        /* WARNING: Subroutine does not return */
        exit(1);
    }

    size = fread(flag_buff,1,0x29,flag_file);
    size_tmp = (int)size;
    size = strcspn((char *)flag_buff,"\n");
    *(char *)((long)flag_buff + size) = 0;
    if (size_tmp != 0x29) {
        fwrite("ERROR: failed to read password file\n",1,0x24,stderr);
        fwrite("ERROR: failed to read password file\n",1,0x24,stderr);
        /* WARNING: Subroutine does not return */
        exit(1);
    }
    fclose(flag_file);

    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");

    printf("--[ Username: ");
    fgets((char *)username_buff,100,stdin);

    size = strcspn((char *)username_buff,"\n");
    printf("SIZE %zu\n", size); 
    *(char *)((long)username_buff + size) = 0;

    printf("--[ Password: ");
    fgets((char *)password_buff,100,stdin);

    size = strcspn((char *)password_buff,"\n");
    *(char *)((long)password_buff + size) = 0;

    printf("flag_buff, [%s]\n", (char*) flag_buff); 
    printf("password_buff [%s]\n", (char*) password_buff); 
    puts("*****************************************");
    cmp_ret = strncmp((char *)flag_buff,(char *)password_buff,0x29);
    if (cmp_ret == 0) {
        printf("Greetings, %s!\n", (char *)username_buff);
        system("/bin/sh");
        return 0;
    }
    printf((char *)username_buff);
    puts(" does not have access!");
    /* WARNING: Subroutine does not return */
    exit(1);
    }
