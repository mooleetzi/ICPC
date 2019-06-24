#include <iostream>
#include <cmath>

using namespace std;

double c(int m,int n)
{
    double sa,sb,sc;
    sa=sb=sc=0.0;
    for(int i=2;i<=m;i++)
    {
        sa+=log((double)i);
    }
    for(int i=2;i<=n;i++)
    {
        sb+=log((double)i);
    }
    for(int i=2;i<=n-m;i++)
    {
        sc+=log((double)i);
    }

   //cout<<sa<<" "<<sb<<" "<<sc<<endl;

    return sb-sa-sc;
}

int main()
{
    int m,n;
    cin>>m>>n;
    cout<<exp(c(m,n));
    return 0;
}
