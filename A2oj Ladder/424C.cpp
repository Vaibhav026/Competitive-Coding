#include <bits/stdc++.h>
using namespace std;


int main()
{	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long int n;
	cin >> n;

	long int p[n];

	long int val;
	for(long int i=0;i<n;i++){
		cin >> p[i];

		if(i == 0)
			val = p[0];
		else
			val = val^p[i];
	}

	long int dp[n];

	dp[0] = 0;

	for(long int i=1;i<n;i++){
		dp[i] = dp[i-1]^i;
	}


	long int save[n+1];

	save[1] = 0;

	long int groups,rem;

	for(long int i=2;i<=n;i++){

		groups = n/i;

		rem = n%i;

		if(groups%2 == 1){
			save[i] = dp[i-1]^dp[rem];
		}
		else{
			save[i] = dp[rem];
		}

	}

	for(long int i=1;i<=n;i++){
		val = val^save[i];
	}

	cout << val;



	return 0;
}