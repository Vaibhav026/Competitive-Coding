#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	long int t;
	cin>>t;

	long double x1,x2,x3,v1,v2; 

	long double tm1,tm2;

	while(t--)
	{	
		cin>>x1>>x2>>x3>>v1>>v2;

		tm1 = abs(x1 - x3)/v1 ;

		tm2 = abs(x2 - x3)/v2 ;

		if( tm1 == tm2 )
		{
			cout<<"Draw\n";
		}
		else if(tm1 <tm2)
		{
			cout<<"Chef\n";
		}
		else
		{
			cout<<"Kefa\n";
		}	
	}

  return 0;
}