#include <bits/stdc++.h>
using namespace std;

long long fact[1000001];
long int mod = 1000000007;
const int N = 1e6 + 100;
int a,b;

void initfact() {
        fact[0] = 1;
        for(int i = 1; i < N; i++) {
                fact[i] = (fact[i-1] * i);
                fact[i] %= mod;
        }

}

bool is(long int sum){

	int digit;

	while(sum){

		digit = sum%10;

		if(digit!= a && digit != b)
			return false;

		sum = sum/10;
	}

	return true;
}

long long binpow(long long val, long long deg, long long mod) {
        if (!deg) return 1 % mod;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
        long long res = binpow(val ,deg >> 1, mod);
        return (res*res) % mod;
}

long long getC(int n, int i) {
        long long res = fact[n];
        long long div = fact[n-i] * fact[i];
        div %= mod;  div = binpow(div, mod - 2, mod);
        return (res * div) % mod;
}



int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long int n;

	initfact();

	cin >> a >> b >> n;

	long int x;

	
	long int val;

	long long int ans = 0;

	for(long int i=0;i<=n;i++){

		val = i*a+(n-i)*b;

		if(is(val)){
			ans = (ans + getC(n,i))%mod;
			//cout << ans  << endl;
		}
	}


	cout << ans;
 

	return 0;
}