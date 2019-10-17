#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
void Encrypt(char Letter[M], int Key)
{
    int len, d, i, j, m;
    char temp[M];
    len = strlen(Letter);
    if ((d = len % Key) != 0)
    {
        len = len + Key - d;
    }
    m = len / Key;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < Key; j++)
        {
            if (i * Key + j < len)
            {
                temp[i + m * j] = Letter[i * Key + j];
            }
            else
            {
                temp[i + m * j] = ' ';
            }
        }
    }
    for (i = 0; i < len; i++)
    {
        Letter[i] = temp[i];
    }
}
void Decrypt(char Letter[M], int Key)
{
    int len, d, i, j, m;
    char temp[M];
    len = strlen(Letter);
    if ((d = len % Key) != 0)
    {
        len = len + Key - d;
    }
    m = len / Key;
    for (i = 0; i < Key; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i * m + j < len)
            {
                temp[i + j * Key] = Letter[i * m + j];
            }
            else
            {
                temp[i + Key * j] = ' ';
            }
        }
    }
    for (i = 0; i < len; i++)
    {
        Letter[i] = temp[i];
    }
}
int main(int argc, char const *argv[])
{
    char s[] = "meetmeafterthetogaparty  ";
    Encrypt(s, 5);
    puts(s);
    Decrypt(s, 5);
    puts(s);
    return 0;
}
