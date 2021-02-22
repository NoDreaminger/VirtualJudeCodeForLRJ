/**
AC Time 2021-02-21 15:35:02 
*/ 

#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 1000+5;

int target[maxn];

int main(){
	int n;
	while(scanf("%d",&n) && n){
		while(scanf("%d",&target[1]) && target[1]){
			for(int i =2;i<=n;i++){
				scanf("%d",&target[i]);
			}
			
			stack<int> s;
			int p1 = 1,p2 = 1;
			
			int ok =1;
			while(p2 < n){
				if(p1 == target[p2]) {
					p1++,p2++;
				}
				else if(!s.empty() && s.top() == target[p2]){
					s.pop();
					p2++;
				}
				else if(p1 <= n) s.push(p1++);
				else {
					ok = 0;break;
				}
			}
			
			printf("%s\n",ok?"Yes" : "No");
		}
		printf("\n");
	}
	return 0;
}
