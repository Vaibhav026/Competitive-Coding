#include<bits/stdc++.h>
using namespace std;

typedef long long           ll;
const ll MOD = 1000000007LL;
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }


int main(){


	#ifndef ONLINE_JUDGE    
	freopen("class_treasurer.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int t;

	cin >> t;

	int n,k;

	string s;

	long long int mod = 1000000007;
	for(int i=1;i<=t;i++){

		cin >> n >> k;

		cin >> s;

		int cnt = 0;

		long long int ans = 0;
		for(int j= n-1;j>=0;j--){

			if(s[j] == 'B')
				cnt++;
			else
				cnt--;

			if(cnt == k+1){
				ans = ( ans + (power(2LL,j+1,mod)) )%mod;
				cnt -= 2;
			}

			if(cnt == -1){
				cnt = 0;
			}

		}


		cout << "Case #" << i << ": " << (ans) << "\n";




	}	



	return 0;
}