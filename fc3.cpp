#include<bits/stdc++.h>
using namespace std;

long long int min(long long int a,long long int b)
{
	if(a<=b)
		return a;
	else
		return b;
}
bool check(long long int n,long long int k)
{	
	long long int a,b,rem,x;
	a = 0;
	b = 0;
	rem = n;
	

	long long int conta , contb;

	conta = 0;
	contb = 0;
	while(true)
	{
		if(rem == 0)
			break;
       
		

		if(rem<k)
			conta = rem;
		else
			conta = k;
		
		a = a + conta;

		rem = rem - conta;

		contb = floor(rem/10);

		b = b + contb; 
		rem = rem - contb;

		//cout << conta << " "<<contb<<endl;
	}	

	long long int boundary = ceil((double) n/2);
	if(a>=boundary)
		return true;
	else
		return false;
}

int main()
{

	long long int n,l,r;

	cin >> n;
	l = 1;
	r = n;

	long long int ans = n;
	while( l <= r )
    {
        long long int mid = (l + r) / 2;
        
        //cout << l <<" "<<r<<endl;
        if(check(n,mid))
        {	//cout << ans <<endl;
            ans = min(ans,mid);
            //cout << ans << endl;
            r = mid-1;
        }
        else
        l = mid+1;
    }

	// bool fg = check(n,3);

	// cout <<endl<< fg;

   cout << ans;






	return 0;
}