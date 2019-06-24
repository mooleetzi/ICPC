#include<bits/stdc++.h>
using namespace std;
int v1,v2,s;
struct node{
    int v,m,n,step;
    node(){}
    node(int x,int y,int z,int p):v(x),m(y),n(z),step(p){}
};
int b[101][101][101];
void bfs();
bool ok(const node&);
int main(){
    while(cin>>s>>v1>>v2&&(s+v1+v2)){
        memset(b,0,sizeof(b));
        if (s&1)
            cout<<"NO"<<endl;
        else
            bfs();
    }
    return 0;
}
void bfs(){
    queue<node> q;
    b[s][0][0]=1;//��ʼ״̬���Ϊ1
    q.push(node(s,0,0,0));//��ʼ״ֻ̬��s�����п��֣�m,n�о�û�У�����m,n���㵹��ֵС��v1��v2
    while(!q.empty()){
        node now=q.front();
        q.pop();
//        if (ok(now)){
//            cout<<now.step<<endl;
//            break;
//        }
        node l1,l2,l3,l4,l5,l6;
        if (now.v>=v1-now.m){//��ǰs�е�ˮ����m��ʣ��ռ�
            l1.v=now.v-(v1-now.m);//s�е���m���ռ�
            l1.m=v1;
            l1.n=now.n;
            l1.step=now.step+1;
        }
        else{//s�е�ˮ�����Ե���m
            l1.v=0;//ȫ������m
            l1.m=now.v+now.m;
            l1.n=now.n;
        }
        if (now.v>=v2-now.n){//��ǰs�е�ˮ����n��ʣ��ռ�
            l2.v=now.v-(v2-now.n);//s�е���n���ռ�
            l2.n=v2;
            l2.m=now.m;
            l2.step=now.step+1;
        }
        else{//s�е�ˮ�����Ե���n
            l2.v=0;//ȫ������n
            l2.n=now.v+now.n;
            l2.m=now.m;
            l2.step=now.step+1;
        }
        l3.v=now.v+now.m;//m�е�ˮ�϶������Ե���s���߸պ��ܵ���,m��s�е�ˮ
        l3.m=0;
        l3.n=now.n;
        l3.step=now.step+1;
        if (now.m>=v2-now.n){//m���ڵ���n��ʣ��ռ�
            l4.m=now.m-(v2-now.n);
            l4.n=v2;
            l4.v=now.v;
            l4.step=now.step+1;
        }
        else{//m������n
            l4.m=0;
            l4.n=now.n+now.m;
            l4.v=now.v;
            l4.step=now.step+1;
        }
        l5.v=now.v+now.n;
        l5.m=now.m;
        l5.n=0;
        l5.step=now.step+1;
        if (now.n>=(v1-now.m)){
            l6.m=v1;
            l6.n=now.n-(v1-now.m);
            l6.v=now.v;
            l6.step=now.step+1;
        }
        else{
            l6.m=now.m+now.n;
            l6.n=0;
            l6.v=now.v;
            l6.step=now.step+1;
        }
        if (ok(l1)){
            cout<<l1.step<<endl;
            return;
        }
        if (ok(l2)){
            cout<<l1.step<<endl;
            return;
        }
        if (ok(l3)){
            cout<<l1.step<<endl;
            return;
        }
        if (ok(l4)){
            cout<<l1.step<<endl;
            return;
        }
        if (ok(l5)){
            cout<<l1.step<<endl;
            return;
        }
        if (ok(l6)){
            cout<<l1.step<<endl;
            return;
        }
        if (!b[l1.v][l1.m][l1.n]){
            q.push(l1);
            b[l1.v][l1.m][l1.n]=1;
        }

        if (!b[l2.v][l2.m][l2.n]){
            q.push(l2);
            b[l2.v][l2.m][l2.n]=1;
        }

        if (!b[l3.v][l3.m][l3.n]){
            q.push(l3);
            b[l3.v][l3.m][l3.n]=1;
        }

        if (!b[l4.v][l4.m][l4.n]){
            q.push(l4);
            b[l4.v][l4.m][l4.n]=1;
        }

        if (!b[l5.v][l5.m][l5.n]){
            q.push(l5);
            b[l5.v][l5.m][l5.n]=1;
        }

        if (!b[l6.v][l6.m][l6.n]){
            q.push(l6);
            b[l6.v][l6.m][l6.n]=1;
        }

    }
    cout<<"NO"<<endl;
}
bool ok(const node &a){
    if ((a.m==a.n&&a.n+a.m==s)||(a.m==a.v&&a.m+a.v==s)||(a.n==a.v&&a.v+a.n==s))
        return true;
    return false;
}
