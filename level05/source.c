void main(void)
    {
    char act_char;
    uint cnt;
    char *pbVar3;
    char buffer [100];
    uint pos;

    fgets((char *)buffer,100,stdin);
    pos = 0;
    do
        {
        cnt = 0xffffffff;
        iterator = buffer;
        do
            {
            if (cnt == 0) break;
            cnt--;
            act_char = *iterator;
            iterator++;
            } while (bVar1 != 0);
        if (~cnt - 1 <= pos)
            {
            printf((char *)buffer);
            exit(0);
            }
        if (('@' < buffer[pos]) && (buffer[pos] < '['))
            {
            buffer[pos] = buffer[pos] ^ 0x20;
            }
        pos = pos + 1;
        } while( true );
    }

