#include <bits/stdc++.h>
using namespace std;

#define fl(i, a, b)     for(int i(a); i < (b); i ++)
#define rep(i, n)       fl(i, 0, n)
#define rep1(i, n)      fl(i, 1, n)
#define rfl(i, a, b)    for(int i(a); i >= (b); i --)

int main()
{
	int n,a,b,c,d;
	cin >> n;

	int sum[n];

	rep(i,n){
		cin >> a >> b >> c >> d;
		sum[i] = a+b+c+d;
	}

	int thomas = sum[0];

	//cout << thomas << endl;
	sort(sum,sum+n);

	int rank;

	rfl(i,n-1,0){

		if(sum[i] == thomas){
			//cout <<  << endl;
			rank = (n-i);
			break;
		}
	}

	cout << rank;









	return 0;
}
