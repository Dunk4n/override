#include <stdio.h>

int verify_user_pass(char *passed_password)
    {
    int cnt;
    char *password;
    char in_CF;
    char in_ZF;

    cnt = 5;
    password = (char *)"admin";
    while(cnt > 0)
        {
        if(*passed_password != *password)
            return (1);
        passed_password++;
        password++;
        cnt--;
        }
    return (0);
    }

char user_name[100];

int verify_user_name(void)
    {
    int cnt;
    char *gived_user_name_ptr;
    char *user_name_ptr;

    puts("verifying username....\n");
    cnt = 7;
    gived_user_name_ptr = user_name;
    user_name_ptr = (char *)"dat_wil";
    while(cnt > 0)
        {
        if(*gived_user_name_ptr != *user_name_ptr)
            return(1);
        gived_user_name_ptr++;
        user_name_ptr++;
        cnt--;
        }
    return (0);
    }

int main(void)
    {
    int program_ret;
    int cnt;
    int *iterator;
    int password[16];
    int ret;

    iterator = password;
    for (cnt = 16; cnt != 0; cnt--)
        {
        *iterator = 0;
        iterator++;
        }

    ret = 0;
    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(user_name, 256, stdin);

    ret = verify_user_name();
    if (ret == 0)
        {
        puts("Enter Password: ");
        fgets((char *)password, 100, stdin);
        ret = verify_user_pass((char *)password);
        if ((ret == 0) || (ret != 0))
            {
            puts("nope, incorrect password...\n");
            program_ret = 1;
            }
        else
            program_ret = 0;
        }
    else
        {
        puts("nope, incorrect username...\n");
        program_ret = 1;
        }
    return program_ret;
    }
