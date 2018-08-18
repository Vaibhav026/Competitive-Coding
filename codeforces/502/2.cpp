#include <bits/stdc++.h>
using namespace std;

#define fl(i, a, b)     for(int i(a); i < (b); i ++)
#define rep(i, n)       fl(i, 0, n)
#define rep1(i, n)      fl(i, 1, n)
#define rfl(i, a, b)    for(int i(a); i >= (b); i --)


int main()
{
	long int n;
	cin >> n;

	string a,b;

	cin >> a >> b;

	long long int t1=0,t2=0,t3=0,t4=0;

	rep(i,n){

		if(a[i] == '0' && b[i] == '0')
			t1++;
		else if(a[i] == '0' && b[i] == '1')
			t2++;
		else if(a[i] == '1' && b[i] == '0')
			t3++;
		else
			t4++;



	}


	long long int ans = t1*(t3+t4) + t3*(t2);


	cout << ans;







	return 0;
}