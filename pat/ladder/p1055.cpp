#include<iostream>
using namespace std;
int p[3];
int main(){
    int x1,x2;
    int y1=0,y2=0;
    cin>>x1>>x2>>p[0]>>p[1]>>p[2];
    int a=x1;
    int b=x2;
    for (int i=0;i<3;i++)
        if (p[i])
            y2++;
        else
            y1++;
    if ((x1>x2&&y1)||y1==3)
        cout<<"The winner is a: "<<x1<<" + "<<y1;
    else if (x2+y2>x1+y1||y2==3)
        cout<<"The winner is b: "<<x2<<" + "<<y2;
    return 0;

}
