#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
void quicksort(int l,int r){
    int key = a[l];
    int i = l, j = r;
    if (l>=r)
        return;
    while (i < j)
    {
        while (i < j && key <= a[j])
            j--;
        if (i<j)
            a[i++] = a[j];
        while (i < j && key >= a[i])
            i++;
        if (i<j)
            a[j--] = a[i];
    }
    a[i] = key;
    quicksort(l, i-1);
    quicksort(i+ 1, r);
}
int main(int argc, char const *argv[])
{
    int n;
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cin >> n;
    scanf("%d",&n);
    for (int i = 0; i < n;i++)
        scanf("%d",&a[i]);
//    quicksort(0, n-1);
    sort(a,a+n);
    for (int i = 0; i <n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    return 0;
}
