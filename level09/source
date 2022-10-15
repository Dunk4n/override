#include <string.h>
#include <stdio.h>

void secret_backdoor(void)
{
  char command[128];

  fgets(command, 128, stdin);
  system(command);
  return;
}

void set_username(char *buffer)
    {
    long cnt;
    long *iterator;
    char username[136];
    int pos;

    iterator = (long *) username;
    for (cnt = 16; cnt != 0; cnt--)
        {
        *iterator = 0;
        iterator++;
        }

    puts(">: Enter your username");
    printf(">>: ");

    fgets((char *)username, 128, stdin);
    for (pos = 0; (pos < 41 && (username[pos] != '\0')); pos++)
        {
        buffer[140 + pos] = username[pos];
        }

    printf(">: Welcome, %s", buffer + 140);
    return;
    }

void set_msg(char *msg_buffer)
    {
    long cnt;
    long *iterator;
    long buffer[128];

    iterator = buffer;
    for (cnt = 128; cnt != 0; cnt = cnt--)
        {
        *iterator = 0;
        iterator++;
        }

    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets((char *)buffer, 1024, stdin);
    strncpy(msg_buffer, (char *)buffer, (long)*(int *)(msg_buffer + 180));
    return;
    }

void handle_msg(void)
    {
    char msg_buffer[140];
    long local_3c;
    long local_34;
    long local_2c;
    long local_24;
    long local_1c;
    long local_14;

    local_3c = 0;
    local_34 = 0;
    local_2c = 0;
    local_24 = 0;
    local_1c = 0;
    local_14 = 140;

    set_username(msg_buffer);

    set_msg(msg_buffer);

    puts(">: Msg sent!");
    return;
    }

int main(void)
    {
    puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
    handle_msg();
    return 0;
    }
