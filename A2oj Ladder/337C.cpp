#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long binpow(long long val, long long deg, long long mod) {
        if (!deg) return 1 % mod;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
        long long res = binpow(val ,deg >> 1, mod);
        return (res*res) % mod;
}

int main()
{
	long int n,m,k;
	long int mod = 1000000009;

	cin >> n >> m >> k;

	long long int p = 1ll*(k-1)*(n-m);

	long int rem = (m)-(p) ;

	//cout << p << endl;
	if(rem <= 0){
		cout << (m);
		return 0;
	}
	else{
		long int groups = rem/k;

		long long int ans = ( ( 2*k )%mod * (binpow(2,groups,mod)-1))%mod;

		long long int left = rem%k ;

		ans = (ans + left + p%mod)%mod;

		cout << ans;
	}




	return 0;
}