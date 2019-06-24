
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 1000001;


char text[maxn];//�ı���
char pattern[maxn];//ģʽ��
int nnext[maxn];//next����.ֱ����next���ܻ��ϵͳ��Ԥ��������

/*O(m)��ʱ����next����*/
void get_next() {
	int patternLen = strlen(pattern);//����ģʽ���ĳ���

	nnext[0] = nnext[1] = 0;
	for (int i = 1; i < patternLen; i++) {
		int j = nnext[i];
		while (j && pattern[i] != pattern[j]){
			j = nnext[j];
		}
		nnext[i + 1] = pattern[i] == pattern[j] ? j + 1 : 0;
	}
}

/*o(n)��ʱ�����ƥ��
 *
 * ���ص�һ��ƥ���λ��
 */
int kmp() {

	int ans = 0;//����ģʽ�����ı����г��ֵĴ���

	int textLen = strlen(text);//�����ı����ĳ���
	int patternLen = strlen(pattern);//����ģʽ���ĳ���

	int j = 0;/*��ʼ����ģʽ���ĵ�һ��λ��*/
	for (int i = 0; i < textLen; i++) {/*���������ı���*/
		while (j && pattern[j] != text[i]){/*˳��ʧ����ߣ�ֱ������ƥ�䣬��õ������j = 0*/
			j = nnext[j];
		}
		if (pattern[j] == text[i]){/*���ƥ��ɹ�������һ��λ��*/
			j++;
		}
		if (j == patternLen) {
			ans++;//����pattern��text�г��ֵĴ���..
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
