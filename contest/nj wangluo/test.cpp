#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int n = 5;
pair <double, double> P;
pair <double,double> gps[2000];
double n1[2000];

double dis(pair<double, double> p1, pair<double, double> p2)
{
//
//    cout<<sqrt(
//                (p1.first-p2.first)*
//                 (p1.first-p2.first)
//                 +(p1.second-p2.second)*
//                 (p1.second-p2.second)
//                )
//                *111<<endl;
    return sqrt(
                (p1.first-p2.first)*
                 (p1.first-p2.first)
                 +(p1.second-p2.second)*
                 (p1.second-p2.second)
                )
                *111;
}

void cal()
{

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dis(gps[i],gps[j])<=1.5)
                n1[i]++;
}

int main()
{
    for(int i=1;i<=n;i++)
        cin>>gps[i].first>>gps[i].second;
    for (int i=1;i<=n;i++)
        printf("%.6f %.6f\n",gps[i].first,gps[i].second);
    cout<<dis(gps[1],gps[2]);
    void cal();
    for(int i=1;i<=n;i++)
        cout<<n1[i]<<endl;
    return 0;
}
