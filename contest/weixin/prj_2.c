#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define content "#############################################################################################"
#define MAGICIAN_CURE_PLAYER1 1
#define MAGICINA_CURE_PLAYER2 2
#define PLAYER1_TO_PLAYER2 3
#define PLAYER2_TO_PLAYER1 4
#define WEAPON_NUM 5
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
Weapon weapon[5];
Player player1, player2, magician;
void accuse(Player *player1, Player *player2)
{
    int accusation = player1->power;
    player2->hp -= accusation;
    printf("%s is accusing, %s decreace %d hp\n", player1->name, player2->name, accusation);
}
void heal(Player *player1, Player *player2)
{
    int healNum = -player2->w->power;
    player1->hp += healNum;
    printf("%s is healed by %s, increase %d hp\n", player1->name, player2->name, healNum);
}
void printWeaponInfo(Weapon *weapon)
{
    printf("weapon_name:%s, weapon_power:%d\n", weapon->name, weapon->power);
}
void initWeaponInfo(char s[], int p, Weapon *weapon)
{
    weapon->power = p;
    strcpy(weapon->name, s);
    printf("Initialize the weapon successfully.\n");
    printWeaponInfo(weapon);
}
void printPlayerInfo(Player *player)
{
    printf("player_name :%s, player_hp: %d, player_power: %d, player_weapon:%s, player_weapon_power:%d\n", player->name, player->hp, player->power, player->w->name, player->w->power);
}
void printCurrentStatus(Player *player1, Player *player2)
{
    printf("%s\n", content);
    printPlayerInfo(player1);
    printPlayerInfo(player2);
    printf("\n");
}
void initWeaponAll()
{
    initWeaponInfo("fangtianhuaji", rand() % 100 + 50, &weapon[0]);
    initWeaponInfo("qinglongyanyuedao", rand() % 100 + 50, &weapon[1]);
    initWeaponInfo("zhangbashemao", rand() % 100 + 50, &weapon[2]);
    initWeaponInfo("qinggangjina", rand() % 100 + 50, &weapon[3]);
    initWeaponInfo("caoyao", -(rand() % 50 + 1), &weapon[4]);
}
void initHealerInfo()
{
    strcpy(magician.name, "xuenv");
    magician.w = &weapon[WEAPON_NUM - 1];
}
void initPlayerInfo()
{
    player1.power = rand() % 100 + 1;
    player1.hp = rand() % 1000 + 1;
    player1.w = &weapon[rand() % 4];
    player2.w = &weapon[rand() % 4];
    player2.power = rand() % 100 + 1;
    player2.hp = rand() % 1000 + 1;
}
int menu()
{
    return rand() % 4 + 1;
}
void swap(Player *p1, Player *p2)
{
    Player *tmp = p1;
    p1 = p2;
    p2 = tmp;
}
void play()
{
    for (;;)
    {
        printCurrentStatus(&player1, &player2);
        int m = menu();
        if (m == MAGICIAN_CURE_PLAYER1)
            heal(&player1, &magician);
        else if (m == MAGICINA_CURE_PLAYER2)
            heal(&player2, &magician);
        else if (m == PLAYER1_TO_PLAYER2)
            accuse(&player1, &player2);
        else if (m == PLAYER2_TO_PLAYER1)
            accuse(&player2, &player1);
        if (player1.hp <= 0 || player2.hp <= 0)
            break;
    }
    if (player1.hp < 0)
        swap(&player1, &player2);
    printf("%s defeated %s\n", player1.name, player2.name);
}
int main()
{
    srand(time(NULL));
    initWeaponAll();
    initHealerInfo();
    printf("Please enter these two player's name:\n");
    scanf("%s %s", player1.name, player2.name);
    initPlayerInfo();
    play();
    return 0;
}
