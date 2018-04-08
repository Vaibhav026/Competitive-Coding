#include<iostream>
using namespace std;


// modular exponentiation

long long int power(int x, long long int y, long long int p)
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

int main()
{
	long int t;

	long long int mod = 1000000007 ;
	long long int n;
	int w;

	long long int constant ;
	long long int ans;

	cin >> t ;
	while(t--)
	{	
		constant = 0;
		ans = 1;
		cin >> n >> w ;


		for(int i=1;i<=9;i++)
		{
			if( (w+i)>=0 && (w+i)<= 9 )
			constant++;	
		}

		ans = power(10,n-2,mod);

		ans = (ans * constant ) % mod ;

		cout<<ans<<endl;
	}	





	return 0;
}