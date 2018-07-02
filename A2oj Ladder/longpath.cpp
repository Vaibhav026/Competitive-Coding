#include <bits/stdc++.h>
using namespace std;



int main()
{
	long int mod = 1000000007;
	int n;
	cin >> n;

	int p[n+1];

	for(int i=1;i<=n;i++)
		cin >> p[i];

	long int steps[n+1];

	for(int i=1;i<=n;i++)
		steps[i] = 0;

	steps[1] = 1;

	for(int i=2;i<=n;i++)
	{
		for(int j=p[i];j<i;j++)
		{
			steps[i] = (steps[i] + steps[j])%mod ;
		}

		steps[i] = (steps[i] + i-p[i]+1 )%mod ;       
	}

	long int ans = 0;
	
	for(int i=1;i<n;i++)
	{
		ans  =  (ans + steps[i] + 1)%mod ;

	}

	ans = (ans + steps[n] + 1 )%mod;

	cout << ans;

	return 0;
}