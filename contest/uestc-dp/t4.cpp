
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 1000001;


char text[maxn];//文本串
char pattern[maxn];//模式串
int nnext[maxn];//next数组.直接起next可能会跟系统中预定的重名

/*O(m)的时间求next数组*/
void get_next() {
	int patternLen = strlen(pattern);//计算模式串的长度

	nnext[0] = nnext[1] = 0;
	for (int i = 1; i < patternLen; i++) {
		int j = nnext[i];
		while (j && pattern[i] != pattern[j]){
			j = nnext[j];
		}
		nnext[i + 1] = pattern[i] == pattern[j] ? j + 1 : 0;
	}
}

/*o(n)的时间进行匹配
 *
 * 返回第一次匹配的位置
 */
int kmp() {

	int ans = 0;//计算模式串在文本串中出现的次数

	int textLen = strlen(text);//计算文本串的长度
	int patternLen = strlen(pattern);//计算模式串的长度

	int j = 0;/*初始化在模式串的第一个位置*/
	for (int i = 0; i < textLen; i++) {/*遍历整个文本串*/
		while (j && pattern[j] != text[i]){/*顺着失配边走，直到可以匹配，最坏得到情况是j = 0*/
			j = nnext[j];
		}
		if (pattern[j] == text[i]){/*如果匹配成功继续下一个位置*/
			j++;
		}
		if (j == patternLen) {
			ans++;//计算pattern在text中出现的次数..
		}
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", pattern, text);
		get_next();
		printf("%d\n", kmp());
	}

	return 0;
}
