#include <bits/stdc++.h>
using namespace std;




int main(){


	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;

	cin >> n;

	long long int a[n+1];

	long long int b[n+1];

	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[n-i+1] = a[i];
	}

	if(n == 1){

	}

	long long int odd[n+1];
	long long int even[n+1];

	for(int i = n; i >= 1 ; i--){

		if(i%2 == 0){

			if( (i+2) <= n ){
				even[i] = even[i+2] + a[i];
				odd[i] = odd[i+2];
			}
			else{
				even[i] = a[i];
				odd[i] = 0;
			}


		}
		else{

			if( (i+2) <= n ){
				odd[i] = odd[i+2] + a[i];
				even[i] = even[i+2];
			}
			else{
				odd[i] = a[i];
				even[i] = 0;
			}


		}

	}


	long long int min_ans = a[1] + min(odd[1],even[1]);

	long long int prev = a[1];

	for(int i=2; i <= n; i += 2){

		if(odd[i] > even[i]){
				
			if(prev + even[i] < min_ans){
				min_ans = prev + even[i];
			}
			prev += a[i];
		}
		else{

			if(prev + odd[i] < min_ans){
				min_ans = prev + odd[i];
			}

			
		}

	}
	
	return 0;
}