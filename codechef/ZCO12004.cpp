#include <bits/stdc++.h>
using namespace std;




int main(){
	
	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	long int n;

	cin >> n;

	long int a[n];

	long int b[n];

	for(int i=0;i<n;i++){
		cin >> a[i]; 
		b[n-i-1] = a[i];
	}

	if(n == 1){
		cout << a[0];
		return 0;
	}
	else if(n == 2){
		cout << min(a[0],a[1]);
		return 0;
	}
	else if( n == 3){

		cout << min(a[0]+a[2],min(a[0]+a[1],a[1]+a[2]));
		return 0;
	}

	long int dp1[n];

	bool is1[n];

	long int dp2[n];

	bool is2[n];

	dp1[n-1] = a[n-1];
	is1[n-1] = true;

	if(a[n-2] <= a[n-1]){
		is1[n-2] = true;
		is1[n-1] = false;
		dp1[n-2] = a[n-2];
	}
	else{
		is1[n-2] = false;
		dp1[n-2] = dp1[n-1];
	}

	for(int j = (n-3) ; j >= 0; j--){

		if(is1[j+1]){
			is1[j] = false;
			dp1[j] = dp1[j+1];
		}
		else{

			if(a[j] <= a[j+1]){
				is1[j] = true;
				dp1[j] = dp1[j+1] + a[j];
			}
			else{
				is1[j] = false;
				dp1[j] = dp1[j+1] + a[j+1];	
			}
		}
	}

	long int ans1 = a[0] + dp1[1];


	dp2[n-1] = b[n-1];
	is2[n-1] = true;

	if(b[n-2] <= b[n-1]){
		is2[n-2] = true;
		is2[n-1] = false;
		dp2[n-2] = b[n-2];
	}
	else{
		is2[n-2] = false;
		dp2[n-2] = dp2[n-1];
	}

	for(int j = (n-3) ; j >= 0; j--){

		if(is2[j+1]){
			is2[j] = false;
			dp2[j] = dp2[j+1];
		}
		else{

			if(b[j] <= b[j+1]){
				is2[j] = true;
				dp2[j] = dp2[j+1] + b[j];
			}
			else{
				is2[j] = false;
				dp2[j] = dp2[j+1] + b[j+1];	
			}
		}
	}

	if(is1[0] || is1[n-1]){
		cout << dp1[0];
		return 0;
	}

	if(is2[0] || is2[n-1]){
		cout << dp2[0];
		return 0;
	}

	long int ans2 = b[0] + dp2[1];

	if(ans1 < ans2){
		cout << ans1;
	}
	else{
		cout << ans2;
	}

	return 0;
}	