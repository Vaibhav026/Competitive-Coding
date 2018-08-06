#include <bits/stdc++.h>
using namespace std;

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

long long int gcd(long long int a, long long int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);

}

int main()
{	
	long long int mod = 1000000007;	
	int t;

	cin >> t;

	long long int a,b,n;

	while(t--){

		cin >> a >> b >> n;

		if(a-b == 0){

			long long int first = power(a,n,mod);
			long long int second = power(b,n,mod);

			long long int z = (first + second)%(mod) ;

			cout << z << endl;
		}
		else{

			long long int first = power(a,n,a-b);
			long long int second = power(b,n,a-b);

			long long int z = (first + second)%(a-b) ;

			cout << (gcd(z,a-b))%mod << endl;
		}	
	}


	return 0;
}
