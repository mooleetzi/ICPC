#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char pre[] = "****************************************************************";
#define PLAYER1_ATTACK_PLAYER2 1
#define PLAYER2_ATTACK_PLAYER1 2
#define HEALER_TREAT_PLAYER1 3
#define HEALER_TREAT_PLAYER2 4
typedef struct
{
    char name[100];
    int power;
} Weapon;
typedef struct
{
    char name[100];
    Weapon *w;
    int power;
    int hp;
} Player;
int min(int x, int y)
{
    return x > y ? y : x;
}
void showPlayer(Player *p)
{
    printf("name :%s, hp: %d, power: %d, weapon:%s, weapon_power:%d\n", p->name, p->hp, p->power, p->w->name, p->w->power);
}
void showStatus(Player *p1, Player *p2)
{
    printf("%s\n", pre);
    showPlayer(p1);
    showPlayer(p2);
    printf("%s\n", pre);
}
void attack(Player *p1, Player *p2)
{
    int dec = min(p1->w->power, p2->hp);
    printf("%s attck %s %d hp\n", p1->name, p2->name, dec);
    p2->hp -= dec;
}
void treat(Player *p1, Player *p2)
{
    int add = -p1->w->power;
    printf("%s treat %s %d hp\n ", p1->name, p2->name, add);
    p2->hp += add;
}
int getOpt()
{
    return rand() % 4 + 1;
}
void initWeapon(Weapon *w, char name[], int power)
{
    strcpy(w->name, name);
    w->power = power;
}
int main()
{
    srand(time(0));
    Weapon w[3];
    initWeapon(&w[0], "yuanhong", 99);
    initWeapon(&w[1], "shachi", 98);
    initWeapon(&w[2], "xuebao", -50);
    Player p1, p2;
    Player healer = {"healer", &w[2], 0, 0};
    printf("please enter the first player's name:\n");
    scanf("%s", p1.name);
    printf("please enter the second player's name:\n");
    scanf("%s", p2.name);
    p1.power = rand() % 100 + 1;
    p2.power = rand() % 100 + 1;
    p1.hp = rand() % 1000 + 1;
    p2.hp = rand() % 1000 + 1;
    int f1 = rand() % 2;
    p1.w = &w[f1];
    p2.w = &w[f1 ^ 1];
    while (p1.hp > 0 && p2.hp > 0)
    {
        int op = getOpt();
        showStatus(&p1, &p2);
        switch (op)
        {
        case PLAYER1_ATTACK_PLAYER2:
            attack(&p1, &p2);
            break;
        case PLAYER2_ATTACK_PLAYER1:
            attack(&p2, &p1);
            break;
        case HEALER_TREAT_PLAYER1:
            treat(&healer, &p1);
            break;
        case HEALER_TREAT_PLAYER2:
            treat(&healer, &p2);
            break;
        }
    }
    if (p1.hp)
        printf("%s kill %s\n", p1.name, p2.name);
    else
        printf("%s kill %s\n", p2.name, p1.name);
    return 0;
}
