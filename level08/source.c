#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void log_wrapper(FILE *log_file, char *msg, char *file_to_backup)
    {
    char tmp;
    size_t size;
    unsigned long cnt;
    unsigned long cnt_2;
    char *iterator;
    char buffer[264];

    strcpy(buffer, msg);

    cnt = 0xffffffffffffffff;
    iterator = buffer;
    do
        {
        if (cnt == 0)
            break;
        cnt--;
        tmp = *iterator;
        iterator++;
    } while (tmp != '\0');

    cnt_2 = 0xffffffffffffffff;
    iterator = buffer;
    do
        {
        if (cnt_2 == 0)
            break;
        cnt_2--;
        tmp = *iterator;
        iterator++;
    } while (tmp != '\0');

    snprintf(buffer + (~cnt_2 - 1), 254 - (~cnt - 1), file_to_backup);

    size = strcspn(buffer,"\n");

    buffer[size] = '\0';

    fprintf(log_file, "LOG: %s\n", buffer);
    return;
    }

int main(int argc, char **argv)
    {
    char tmp;
    int backup_file_fd;
    FILE *log_file;
    FILE *file_to_backup;
    unsigned long cnt;
    char *iterator;
    char read_char;
    char backup_file_path[11] = "./backups/";

    read_char = -1;
    if (argc != 2)
        printf("Usage: %s filename\n", argv[0]);

    log_file = fopen("./backups/.log","w");
    if (log_file == (FILE *)0x0)
        {
        printf("ERROR: Failed to open %s\n","./backups/.log");
        exit(1);
        }

    log_wrapper(log_file,"Starting back up: ", argv[1]);
    file_to_backup = fopen((char *)argv[1], "r");
    if (file_to_backup == (FILE *)0x0)
        {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
        }

    cnt = 0xffffffffffffffff;
    iterator = (char *) &backup_file_path;
    do
        {
        if (cnt == 0)
            break;
        cnt = cnt - 1;
        tmp = *iterator;
        iterator++;
        } while (tmp != '\0');

    strncat((char *)&backup_file_path, (char *)argv[1], 99 - (~cnt - 1));

    backup_file_fd = open((char *)&backup_file_path, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    if (backup_file_fd < 0)
        {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
        }

    while(1)
        {
        read_char = (char) fgetc(file_to_backup);
        if (read_char == -1)
            break;
        write(backup_file_fd, &read_char, 1);
        }

    log_wrapper(log_file,"Finished back up ", argv[1]);
    fclose(file_to_backup);
    close(backup_file_fd);
    return 0;
    }
