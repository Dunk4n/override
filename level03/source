#include <stdio.h>
#include <stdbool.h>
#include <openssl/evp.h>

int decrypt(EVP_PKEY_CTX *ctx,unsigned char *out,size_t *outlen,unsigned char *in,size_t inlen)
    {
    uint code_length;
    char *congrat_str;
    int in_GS_OFFSET;
    uint cnt;
    char code[] = "Q}|u`sfg~sf{}|a3"

    code_length = 0;
    while(code[code_length] != '\0')
        {
        if (code_length == 0xffffffff)
            break;
        code_length++;
        }

    cnt = 0;
    while(cnt < code_length - 1)
        {
        code[cnt] = (char)ctx ^ code[cnt];
        cnt++;
        }

    cnt = 0;
    congrat_str = (char *)"Congratulations!";
    while(cnt < 0x11)
        {
        if(code[cnt] != *congrat_str)
            {
            puts("\nInvalid Password");
            return;
            }

        congrat_str = congrat_str + 1;
        cnt++;
        }

    system("/bin/sh");
    }

void test(int param_1,int param_2)
    {
    EVP_PKEY_CTX  *public_key;
    unsigned char *out;
    size_t        *out_size;
    unsigned char *in;
    size_t         in_size;

    public_key = (EVP_PKEY_CTX *)(param_2 - param_1);
    switch((int) public_key)
        {
        default:
            public_key = (int)(EVP_PKEY_CTX *)rand();
            decrypt(public_key, out, out_size, in, in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x1:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x2:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x3:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x4:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x5:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x6:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x7:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x8:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x9:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x10:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x11:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x12:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x13:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x14:
            decrypt(public_key,out,out_size,in,in_size);
            break;
        case (int)(EVP_PKEY_CTX *)0x15:
            decrypt(public_key,out,out_size,in,in_size);
        }
    return;
    }

int main(void)
    {
    int password;

    srand(time((time_t *) 0x0));
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &password);
    test(password, 0x1337d00d);
    return 0;
    }
