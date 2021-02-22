//AC Time 2021-02-22 12:10:23
/**
主要的难点就是理解数组实现链表这一个知识点。
在本题代码中，cur指的是当前的光标位置，
last指的是最末尾的光标位置
遇到 [ 键时，就把光标移动到虚拟头节点，遇到]键时，就把光标移动到最右端。
除了移动光标，插入操作是一样的，都是在cur —next[cur] 之间。区别就是cur的位置。
一开始，cur 是0，next[cur]也是0,理解这点很关键。 
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
