#include <bits/stdc++.h>
using namespace std;


int main()
{	
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int t;

    cin >> t;


    long int n;

    long long int a[100001];

    long long int sum[100001];

    while(t--){

    	cin >> n;

    	for(long int i=1;i<=n;i++)
    		cin >> a[i];

    	

    	sum[1] = a[1];

    	for(long int i=2;i<=n;i++)
    		sum[i] = sum[i-1] + a[i];


    	long int days = 0;

    	long int index = 1;

    	while(index < n){

    		index += sum[index];
    		days++;
    	}

    	cout << days << "\n";
    	
    }

    


    return 0;

}    