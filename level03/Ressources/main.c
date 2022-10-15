#include <stdio.h>

int main(void)
    {
    char code[] = "Q}|u`sfg~sf{}|a3";
    char res[] = "Congratulations!";

    int i = 0;
    while(code[i] != '\0')
        {
        printf("%d\n", code[i] ^ res[i]);
        i++;
        }
    }
