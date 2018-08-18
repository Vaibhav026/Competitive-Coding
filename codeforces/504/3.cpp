#include <bits/stdc++.h>
using namespace std;

 #define fl(i, a, b)     for(int i(a); i < (b); i ++)
    #define rep(i, n)       fl(i, 0, n)
    #define rep1(i, n)      fl(i, 1, n)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)

int main()
{
	long int n,k;
	
	cin >> n  >> k;

	string s;

	cin >> s;

	bool x[n];

	for(int i=0;i<n;i++){
		x[i] = false;
	}

	stack<char> st;

	stack<long int> v;

	st.push(s[0]);
	v.push(0);

	long int siz = 0;

	for(int i=1;i<n;i++){

		if(s[i] == ')' && st.top() == '('){

			int t = v.top();
			st.pop();
			v.pop();

			x[i] = true;
			x[t] = true;
			siz += 2;

		}
		else{
			st.push(s[i]);
			v.push(i);
		}

		if(siz == k)
			break;
	} 


	rep(i,n){

		if(x[i])
			cout << s[i];
	}








	return 0;
}
