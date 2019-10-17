#include <stdio.h>
#include <string.h>
void Encrypt(char *Letter, int Key)
{
    int len = strlen(Letter), i;
    for (i = 0; i < len; i++)
        Letter[i] += Key;
}
void Decrypt(char *Letter, int Key)
{
    int len = strlen(Letter), i;
    for (i = 0; i < len; i++)
        Letter[i] -= Key;
}
int main()
{
    char s[] = "ABC";
    Encrypt(s, 2);
    printf("%s\n", s);
    Decrypt(s, 2);
    printf("%s\n", s);
    return 0;
}