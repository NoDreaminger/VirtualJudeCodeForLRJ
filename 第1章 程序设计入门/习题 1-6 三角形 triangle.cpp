#include <cstdio>
#include <string>
#include<iostream>
using namespace std;

const char NOT[] = "not a triangle";
const char YES[] = "yes";
const char NO[] = "no";

int main(){
	long long int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)){
		if(b < c) swap(b,c);
		if(a < b) swap(a,b);
		
		if(a >= b+c){
			printf("%s\n",NOT); continue;
		}
		
		if(a*a == b*b + c*c){
			printf("%s\n", YES);
		}else{
			printf("%s\n", NO);
		}
	}
	return 0;
} 
