#include <stdio.h>
#include <string.h>
void Encrypt(char Letter[], int Key)
{
    int len, i;
    len = strlen(Letter);
    for (i = 0; i < len; i++)
        Letter[i] ^= Key;
}
void Decrypt(char Letter[], int Key)
{
    int len, i;
    len = strlen(Letter);
    for (i = 0; i < len; i++)
        Letter[i] ^= Key;
}
int main(int argc, char const *argv[])
{
    char s[] = "12345";
    Encrypt(s, 7);
    puts(s);
    Decrypt(s, 7);
    puts(s);
    return 0;
}
