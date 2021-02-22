//AC time 2021-02-21 16:06:17

#include <cstdio>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

struct Matrix{
	int a,b;
	Matrix(int a = 0, int b =0) :a(a),b(b){}
}m[26];

stack<Matrix> s;
int main(){
	int n;
	cin>>n;
	for(int i =0;i<n;i++){
		string name;
		cin>>name;
		int k = name[0]-'A';
		cin>>m[k].a >> m[k].b; 
	}
	
	string expr;
	while(cin >> expr){
		int len = expr.size();
		int ans = 0;
		bool error = false;
		for(int i =0;i<len;i++){
			if(isalpha(expr[i])) s.push(m[expr[i] - 'A']);
			else if(expr[i] == ')'){
				Matrix m2 = s.top(); s.pop();
				Matrix m1 = s.top(); s.pop();
				if(m1.b != m2.a) {error = true; break;}
				ans += m1.a * m1.b * m2.b;
				s.push(Matrix(m1.a,m2.b));
			}
		}
		error? cout <<  "error" : cout<< ans ;
		cout << endl;
	}
	return 0;
}
