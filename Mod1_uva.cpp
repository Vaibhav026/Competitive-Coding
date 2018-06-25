#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
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



int main()
{
	long int mod = 34943;
	
	string s;
	
	long long int sum = 0;

	long long int temp;

	long long int offset = 0;

	long long int ascval;
	int l;

	long int ans;

	string hex[4];

	while(1)
	{
		getline(cin,s);

		// cout << s;
		if(s[0] == '#')
		break;
		
		sum = 0;
		offset = 0 ;
		l = s.length();

		for(int i= l-1;i>=0;i--)
		{	
			ascval = (int) s[i];
			//cout << ascval<<endl;
			temp = ( power(2,offset,mod)*ascval ) % mod;
		
			sum = (sum + temp) ;
			 cout << sum <<endl;
			offset += floor(log2(ascval))+1;
			
		}	

		sum = (32*32*64*sum) % mod ;

	    ans = mod - sum;
		
		 cout << ans
		  <<endl;		
		int temp2 ;
		for(int i =0;i<4;i++)
		{	
			temp2 = ans % 16;

			if(temp2 < 10)
			hex[i] = (char) (48+temp2);
			else
			{
				if(temp2 == 10)
				hex[i] = 'A';
				else if(temp2 == 11)
				hex[i] = 'B';
				else if(temp2 == 12)
				hex[i] = 'C';
				else if(temp2 == 13)
				hex[i] = 'D';
				else if(temp2 == 14)
				hex[i] = 'E';
				else
				hex[i] = 'F';	
			}


			ans = ans/16;
		}	

		for(int i=3;i>=0;i--)
		{	
			cout<<hex[i];	

			if(i == 2)
			cout<<" ";	
		}	

		cout << endl;
	}	

	
	return 0;
}