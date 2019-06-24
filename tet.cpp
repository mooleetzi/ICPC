#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #include<bits/extc++.h>
// #include<iostream>
const int maxn = 110;
int ans=0;
inline int is_prime(int x){
    if (x==1)
        return 0;
    for (int i=2;i<sqrt(x);i++)
        if (x%i==0)
            return 0;
    return 1;
}
int main(int argc, char const *argv[])
{
    for (int i=1;i<=100;i++)
        if (is_prime(i))
            ans+=i;
    std::cout<<ans<<"\n";
    std::cout<<"hello world\n";
    return 0;
}
