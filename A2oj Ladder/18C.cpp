#include<bits/stdc++.h>
using namespace std;


int main()
{

	long int n;

	cin >> n;

	long int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	long int sum[n];

	sum[0] = a[0];

	for(int i=1;i<n;i++)
		sum[i] = sum[i-1] + a[i];


	long int ways = 0;

	for(int i=0;i<n-1;i++){
		
		 if(sum[i] == (sum[n-1]-sum[i]) )
		 	ways++;

		//cout << sum[i] << " " << (sum[n-1] - sum[i]) << endl;
	}		 

	cout << ways;










	return 0;
}