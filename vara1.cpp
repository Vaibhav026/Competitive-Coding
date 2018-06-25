#include <iostream>
using namespace std;


int main()
{

	int n;

	cin >> n;

	long int a[n];

	
	long int max_or = 0;
	long int max_and = -1;

	for(int i=0;i<n;i++)
	{
		cin >> a[i];

		max_or = max_or | a[i] ;

		if(a[i]>max_and)
			max_and = a[i];
	}		

	long int ans = max_and + max_or;	

	
	cout << ans;



	return 0;
}