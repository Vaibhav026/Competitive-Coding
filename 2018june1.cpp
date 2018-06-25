#include <iostream>

using namespace std;




int main()
{
	int t;
	cin >>t;

	long long int a,b,n;

	long long int a2,b2;
	while(t--){

		cin >> a >> b >> n;

		if(n%2 ==0)
		{	
			a2 = a*a;
			b2 = b*b;

			if(a2 > b2)
			{
				cout << "1\n";
			}
			else if(a2<b2)
			{
				cout << "2\n";
			}
			else
			{
				cout << "0\n";
			}	
		}
		else
		{
			if(a > b)
			{
				cout << "1\n";
			}
			else if(a<b)
			{
				cout << "2\n";
			}
			else
			{
				cout << "0\n";
			}
		}	
	}










	return 0;
}