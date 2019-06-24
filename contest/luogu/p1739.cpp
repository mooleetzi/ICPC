#include<bits/stdc++.h>
using namespace std;
int main(){
    int tot = 0;
    int flag = 1;
    char ch = getchar();
    while (ch!='@')
    {
        if (ch=='(')
            ++tot;
        else if (ch==')'){
            if (!tot)
                flag = 0;
            --tot;
        }
        ch = getchar();
    }
    if (flag&&!tot)
        printf("YES");
    else
    {
        printf("NO");
    }
    return 0;
}