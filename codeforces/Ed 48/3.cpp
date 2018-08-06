#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long int n;

	cin >> n;

	long long int a[n+1];

	long long int b[n+1];

	long long int sum[n+1];

	long long int dp[n+1];

	for(long int i=1;i<=n;i++){
		cin >> a[i];
	}

	for(long int i=1;i<=n;i++){
		cin >> b[i];
	}

	sum[n] = a[n] + b[n];

	for(long int i=n-1;i>=1;i--){

		sum[i] = sum[i+1] + a[i] + b[i];	
	}

	dp[1] = b[1]*(2*n-1);

	for(long long int i=2;i<=n;i++){
		dp[1] += (i-1)*a[i] + (2*n-i)*b[i];
	}

	dp[2] = b[1];

	for(long long int i=2;i<=n;i++){
		dp[2] += (i)*b[i] + (2*n-i+1)*a[i];
	}	

	for(long long int i=3;i<=n;i++){

		if(i%2 == 0){

			dp[i] = dp[i-2] + 2*sum[i] - 2*(n-i+2)*a[i-2] - 2*(n-i+1)*a[i-1] + 2*b[i-1];
		}
		else{

			dp[i] = dp[i-2] + 2*sum[i] - 2*(n-i+2)*b[i-2] - 2*(n-i+1)*b[i-1] + 2*a[i-1] ;
		}
	}

	long long int max = dp[1];

	for(int i=1;i<=n;i++){

		if(max < dp[i])
			max = dp[i];
	}

	cout << max;
	return 0;
}