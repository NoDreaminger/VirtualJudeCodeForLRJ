//AC Time 2021-02-22 12:10:23
/**
��Ҫ���ѵ�����������ʵ��������һ��֪ʶ�㡣
�ڱ�������У�curָ���ǵ�ǰ�Ĺ��λ�ã�
lastָ������ĩβ�Ĺ��λ��
���� [ ��ʱ���Ͱѹ���ƶ�������ͷ�ڵ㣬����]��ʱ���Ͱѹ���ƶ������Ҷˡ�
�����ƶ���꣬���������һ���ģ�������cur ��next[cur] ֮�䡣�������cur��λ�á�
һ��ʼ��cur ��0��next[cur]Ҳ��0,������ܹؼ��� 
*/ 

#include <cstdio>
#include <cstring>
const int maxn  = 100000+5;
int cur,last,next[maxn];
char s[maxn];

int main(){
	while(scanf("%s",s+1) != EOF){
		int n = strlen(s+1);
		cur = last = 0;
		next[0] = 0;
		for(int i = 1;i<=n;i++){
			if(s[i] == '[') cur = 0;
			else if(s[i] == ']') cur = last;
			else{
				next[i] = next[cur];
				next[cur] = i;
				if(cur == last) last = i;
				cur = i;
			}
		}
		
		for(int i =next[0]; i ; i = next[i]) printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
