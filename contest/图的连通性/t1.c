#include <stdio.h>
#include <string.h>
int w[] = {2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5};
int ID_1[13];
char ID_2[14];
int check, choice, i, j, tmp;

void input1()
{
    printf("Please input your id:\n");
    scanf("%s", ID_2);
}
void input2()
{
    printf("Please input your id:\n");
    for (i = 0; i < 13; i++)
        scanf("%d", ID_1 + i);
}
int judge()
{
    int f1, f2, t1, t2;
    f1 = f2 = t1 = t2 = 0;
    for (i = 0; i < 12; i++)
        t1 += ID_1[i] * w[i];
    for (i = 0; i < 12; i++)
        t2 += (ID_2[i] - '0') * w[i];
    f1 = (11 - t1 % 11) % 10 == ID_1[12];
    f2 = (11 - t2 % 11) % 10 == ID_2[12] - '0';
    return f1 || f2;
}
int main()
{
    printf("First,please choose the way you input:\n");
    printf("1.strings\n");
    printf("2.integer array\n");
    scanf("%d", &choice);
    if (choice == 1)
        input1();
    else if (choice == 2)
        input2();
    else
    {
        printf("Error input.\n");
        return 0;
    }
    check = judge();
    if (check)
        puts("Correct");
    else
        puts("False");
    return 0;
}