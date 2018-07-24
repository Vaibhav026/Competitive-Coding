#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >> t;


	int n,k;

	long int mod = 1000000007;	

	int size ;

	long int dp[5005][5005];

	long int a[5005];

	while(t--){
		
		cin >> n >> k;	 

		for(int i=0;i<n;i++)
	   		cin >> a[i];

	   	size = k-2;

	   	long int acc = 1;

	   	
	   	for(int i=0;i<n;i++){

	   		acc = 1;

			for(int j=0;j<n;j++){

				if((j-i+1)<=size){
					acc = (acc*a[j])% mod;

					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = 
					
				}	
			}

	   	}






	}






	return 0;
}