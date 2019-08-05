#include<bits/stdc++.h>
using namespace std;




int main() {

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int n;

	cin >> n;

	int a[n];

	int gud[100001];


	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	for(int i=0;i<=100000;i++){
		gud[i] = 0;
	}

	for(int i=0;i<(n/2);i++){

		if(a[i] > i)
			gud[a[i]-i]++;
	}

	for(int i = n-1; i >= (n/2) ; i--){

			if(a[i] > ((n-1)-i)){
				gud[a[i] - ((n-1)-i)]++;
			}
	}

	int maxx = 0;

	for(int i=1;i<=100000;i++){
		maxx = max(gud[i],maxx);
	}

	cout << (n-maxx);

	return 0;
}	