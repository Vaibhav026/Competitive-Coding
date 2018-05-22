#include <iostream>
#include <math.h>
using namespace std;

int main()
{	
	long long int l,r;

	int bitl[64],bitr[64];

	for(int i=0;i<64;i++)
	{
		bitr[i] = 0;
		bitl[i] = 0;
	}

	cin >> l >> r ;

	long long int i;

	if( l == r )
	{
		cout << "0";
	}	
	else
	{	i=0;
		while(l!=0)
		{
			bitl[i] = l%2;
			l = l/2;
			i++;
		}

		i=0;

		while(r!=0)
		{
			bitr[i] = r%2;
			r = r/2;
			i++;
		}
		
		i=63;

		while(1)
		{
			if(bitl[i]!=bitr[i])
			break;
			
			i--;	
		}

		long long int ans = pow(2,i+1) - 1;

		cout << ans; 

	}	





	return 0;
}