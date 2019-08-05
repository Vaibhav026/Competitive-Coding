#include <bits/stdc++.h>
using namespace std;




int main(){


	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	long long int n;
	cin >> n;

	long long int a[n+1];

	long long int even,odd;

	even = 0;
	odd = 0;

	for(int i=1;i<=n;i++){
		cin >> a[i];

		if(i%2 == 1){
			odd += a[i];
		}
		else{
			even += a[i];
		}

	}

	if(n%2 == 0){
		cout << min(odd,even);
	}
	else{
		cout << min(odd,min(even+a[1],even+a[n]));
	}
	return 0;
		
}	