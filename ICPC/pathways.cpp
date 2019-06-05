#include<bits/stdc++.h>
using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif


    int n;

    cin >> n;

    long long int a[n][n];


    long long int dp[n][n];

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin >> a[i][j];
    		dp[i][j] = 0;
    	}
    }

    dp[n-1][n-1] = a[n-1][n-1];


    for(int j = n-2;j>=0;j--){
    	dp[n-1][j] =  a[n-1][j] + dp[n-1][j+1];
    }

    for(int i = n-2;i>=0;i--){
    	dp[i][n-1] = a[i][n-1] + dp[i+1][n-1];
    }

    long long int tmp;

    for(int i = n-2;i>=0;i--){

    	for(int j = n-2;j>=0;j--){

    		tmp = min(dp[i+1][j],dp[i][j+1]);

    		dp[i][j] = a[i][j] + tmp;	
    	}
    }

    cout << dp[0][0];
    
    return 0;
}    