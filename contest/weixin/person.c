#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#define MAKE_ROW_SUCCES 1
#define MAKE_ROW_FAILED 2
#define MAKE_COL_SUCCES 3
#define MAKE_COL_FAILED 4
#define FREE_SUCCESS 5
#define FREE_FAILED 6
#define pre "######################################"
char ud[] = "undefined";
typedef struct person
{
    char *name;
    int age;
    char *tel;
} Person;
int makeRow(Person ***addr, int row)
{
    *addr = (Person **)malloc(sizeof(Person *) * row);
    return MAKE_ROW_SUCCES;
}
int makeCol(Person **addr, int col)
{
    *addr = (Person *)malloc(sizeof(Person) * col);
    for (int i = 0; i < col; i++) //init
    {
        (*addr)[i].age = 0;
        (*addr)[i].name = (char *)malloc(sizeof(char) * 101);
        (*addr)[i].tel = (char *)malloc(sizeof(char) * 101);
        memcpy((*addr)[i].name, ud, sizeof(ud));
        memcpy((*addr)[i].tel, ud, sizeof(ud));
    }
    return MAKE_COL_SUCCES;
}
int releaseRow(Person **addr)
{
    int col = _msize(*addr) / sizeof(Person);
    for (int i = 0; i < col; i++)
    {
        (*addr)[i].age = 0;
        free((*addr)[i].name);
        free((*addr)[i].tel);
        (*addr)[i].name = NULL;
        (*addr)[i].tel = NULL;
    }
    free((*addr));
    (*addr) = NULL;
    return FREE_SUCCESS;
}
void showRow(int col)
{
    for (int i = 0; i < col; i++)
        printf("口");
}
void showBuilding(Person ***addr, int row)
{
    printf("varible_name:%s, variable_addr:%x\n", "building", (int)(*addr));
    for (int i = 0; i < row; i++)
    {
        int col = _msize((*addr)[i]) / sizeof(Person);
        printf("Row#%d: %d,", i, col);
        showRow(col);
        puts("");
    }
}
int main(int argc, char const *argv[])
{
    Person **building = NULL;
    showBuilding(&building, 0);
    int row, col;
    printf("please enter the row of this building:");
    scanf("%d", &row);
    int f = makeRow(&building, row);
    while (f != MAKE_ROW_SUCCES)
    {
        printf("makerow of the building failded, please retry.\n");
        Sleep(500); //sleep 500ms
        printf("please enter the row of this building:");
        scanf("%d", &row);
        f = makeRow(&building, row);
    }
    printf("makerow of the building success, please go on.\n");
    for (int i = 0; i < row; i++)
    {
        printf("please enter the col of Row#%d:", i);
        scanf("%d", &col);
        int f = makeCol(&(building[i]), col);
        while (f != MAKE_COL_SUCCES)
        {
            printf("makecol of Row#%d failded, please retry.\n", i);
            Sleep(500); //sleep 500ms
            printf("please enter the col of Row#%d:", i);
            scanf("%d", &col);
            makeCol(&(building[row]), col);
        }
        if (i != row - 1)
            printf("makecol of Row#%d success, please go on.\n", i);
        else
            printf("makecol of Row#%d success, please check the results.\n", i);
    }
    printf("%sresult%s\n", pre, pre);
    showBuilding(&building, row);
    return 0;
}
