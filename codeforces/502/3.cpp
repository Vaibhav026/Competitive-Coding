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


	long int start = n/2 + 1;


	for(long int i=start;i<=n;i++)
		cout << i << " ";

	for(long int i=1;i<start;i++)
		cout << i << " ";



	return 0;
}