#include <bits/stdc++.h>
using namespace std;

int a,b;
typedef long long           ll;

long int power(long int x, long int y, long int m);
 
// Function to find modular inverse of a under modulo m
// Assumption: m is prime
long  int modInverse(long int a, long int m)
{
    return power(a, m-2, m);
}
 
// To compute x^y under modulo m
long int power(long int x, long int y,long int m)
{	
	long long int xx = x;
    if (y == 0)
        return 1;
    long long int p = power(x, y/2, m) % m;
    
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (xx * p) % m;
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

int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long int n;

	cin >> a >> b >> n;

	long int x;

	long int mod = 1000000007;

	long long int store[n+1];
	
	store[0] = 1;

	for(long int i=1;i<=n;i++){

		store[i] = ( (1ll* (store[i-1])*(n-i+1))% mod * modInverse(i,mod) )% mod;
		//cout << store[i] << endl;
	}

	long int val;

	long long int ans = 0;

	for(long int i=0;i<=n;i++){

		val = i*a+(n-i)*b;

		if(is(val)){
			ans = (ans + store[i])%mod;
			//cout << ans  << endl;
		}
	}


	cout << ans;
 

	return 0;
}