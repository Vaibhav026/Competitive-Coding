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

	long long int n,k;

	long long int s[100001];

	long long int ans;

	while(t--){


		cin >> n >> k;

		ans = k;

		for(long int i =1;i<=n;i++)
			cin >> s[i];

		sort(s+1,s+n+1,greater<long long int>());

		for(long int i = k+1;i<=n;i++){
			
			if(s[i] < s[k])
				break;
			else
				ans++;
		}



		cout << ans << endl;

	} 










	return 0;
}