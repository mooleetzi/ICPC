#include <stdio.h>
#define M 50
int weight[M] = {2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4};
char s[M];
int in[M];

int main()
{
    int i, j, k, flag;
    printf("Please input your ID CARD:\n");
    // scanf_s("%[^\n]", s, M - 1);
    scanf("%[^\n]", s);
    j = 0;
    for (i = 0; i < 13; i++)
    {
        while (s[j] == ' ')
            ++j;
        in[i] = s[j++] - '0';
    }
    k = 0;
    for (i = 0; i < 12; i++)
        k += in[i] * weight[i];
    flag = (11 - k % 11) % 10 == in[12];
    if (flag)
        printf("Correct\n");
    else
        printf("Wrong\n");
    return 0;
}
