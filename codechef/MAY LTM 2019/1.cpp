#include<bits/stdc++.h>
using namespace std;

long int gcd(long int a,long int b){

	if(a == 0){
		return b;
	}

	return gcd(b%a,a);

}


int main() {

	#ifndef ONLINE_JUDGE    
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
   
	int t;
	
	cin >> t;


	long long int n,m,k;

	long long int ans;

	while(t--){

		cin >> n >> m >> k;
		if(gcd(n,k) == 1 && gcd(m,k) == 1){

			ans = n*m;

			cout << ans << endl;
		}
		else{

			cout << "-1\n";
		}


	}	

    return 0;
}