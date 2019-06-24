
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=1000000+10;
char text[MAX];
char word[10000+10];
int next[10000+10];

void get_next(char *a){//计算next,next会算到next[0...len]
	int i=0,j=-1,len=strlen(a);
	next[0]=-1;
	while(i<len){
		if(j == -1 || a[i] == a[j]){
			if(a[++i] != a[++j])next[i]=j;
			else next[i]=next[j];//一个优化,表示如果在kmp时a[i]和b[k]不匹配,那么a[i]=a[j],a[j]肯定和b[k]不匹配,所以用next[j]去匹配
		}else j=next[j];
	}
}
int KMP(char *a,char *b){
	int i=0,j=0,lena=strlen(a),lenb=strlen(b),sum=0;
	while(i<=lena && j<lenb){
		if(i == -1 || a[i] == b[j])++i,++j;
		else i=next[i];
		if(i == lena)++sum;
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>word>>text;
		get_next(word);
		cout<<KMP(word,text)<<endl;
	}
	return 0;
}
