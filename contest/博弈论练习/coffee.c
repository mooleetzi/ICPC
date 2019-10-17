#include <stdio.h>
int money = 0, pay = 0, t = 0, op = 0;
int coffee()
{
    printf("Making the first coffee.\n");
    printf("Done.\n");
    return 500;
}
int water()
{
    printf("Adding water.\n");
    return 500;
}
int vanilla()
{
    printf("Adding vanilla.\n");
    return 500;
}
int milk()
{
    printf("Adding milk.\n");
    return 1000;
}
int milkCoffee()
{

    printf("Making the milkCoffee...\n");
    t = coffee() + milk();
    printf("Done....\n");
    return t;
}
int waterCoffee()
{
    printf("Making the waterCoffee...\n");
    t = coffee() + water();
    printf("Done...\n");
    return t;
}
int vanillaMilkCoffee()
{
    printf("Making the vanillaMilkCoffee...\n");
    t = coffee() + vanilla() + milk();
    printf("Done....\n");
    return t;
}
int getOrder()
{
    printf("Welcome to our cafe, please order.\n");
    printf("Coffee 500 each,Water 500 each,Milk 1000 each,Vanilla 500 each\n");
    printf("1.Coffee\n");
    printf("2.Water Coffee\n");
    printf("3.Milk Coffee\n");
    printf("4.Vanilla Milk Coffee\n");
    scanf("%d", &op);
    return op;
}
int main()
{
    op = getOrder();
    if (op == 1)
        money += coffee();
    else if (op == 2)
        money += waterCoffee();
    else if (op == 3)
        money += milkCoffee();
    else if (op == 4)
        money += vanillaMilkCoffee();
    else
    {
        puts("Wrong choice.\nBye.");
        return 0;
    }
    printf("Your total consumption is %d.\n", money);
    printf("Please pay:");
    scanf("%d", &pay);
    while (pay < money)
    {
        printf("It's not enough.\n");
        printf("Please repay:");
        scanf("%d", &pay);
    }
    if (pay > money)
        printf("Change %d.\n", pay - money);
    else
        printf("OK.\n");
    printf("Welcome to visit next time.\n");
    return 0;
}