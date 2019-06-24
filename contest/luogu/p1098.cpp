#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

inline int read()
{
    int tmp = 0;
    int f = 1;
    char ch = getchar();
    if (ch == '-')
    {
        ch = getchar();
        f = -1;
    }
    while (ch >= '0' && ch <= '9')
    {
        tmp = tmp * 10 + ch - '0';
        ch = getchar();
    }
    return tmp * f;
}
int p1, p2, p3;
char s[maxn];
int tot;
int main(int argc, char const *argv[])
{
    p1 = read(), p2 = read(), p3 = read();
    scanf("%s", s);
    for (int i = 0; i < strlen(s);i++){
        if (s[i]=='-'&&i&&i<strlen(s)-1){
            char pre = s[i - 1];
            char next = s[i + 1];
            if (pre>=next||next=='-'||pre=='-'||(isdigit(pre)&&isalpha(next)||(isdigit(next)&&isalpha(pre))))
                putchar(s[i]);
            else
            {
                if (p1==1){
                    if (p3==1){
                        for (char i = pre + 1; i < next;i++)
                            for (int j = 0; j < p2;j++)
                                putchar(char(tolower(i)));
                    }
                    else
                    {
                        for (char i = next - 1; i > pre;i--)
                            for (int j = 0; j < p2;j++)
                                putchar(char(tolower(i)));
                    }
                }
                else if (p1==2)
                {
                    if (p3 == 1)
                    {
                        for (char i = pre + 1; i < next; i++)
                            for (int j = 0; j < p2; j++)
                                putchar(char(toupper(i)));
                    }
                    else
                    {
                        for (char i = next - 1; i > pre; i--)
                            for (int j = 0; j < p2; j++)
                                putchar(char(toupper(i)));
                    }
                }
                else
                {
                    for (int i = pre + 1; i < next;i++)
                        for (int j = 0; j < p2;j++)
                            putchar('*');
                }
            }
            
        }
        else
            putchar(s[i]);
    }
    /* code */
    return 0;
}
