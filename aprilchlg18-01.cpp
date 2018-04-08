#include <iostream>
# include <algorithm>
using namespace std;


int main()
{
	int n;
	cin>>n;

	long int c[n];
	int t[n];

	for(int i=0;i<n;i++)
	cin>>c[i];
	
	for(int i=0;i<n;i++)	
	cin>>t[i];
	

	long int t1min = 1000001;
	long int t2min = 1000001; 	
	long int t3min = 1000001;

	for(int i=0;i<n;i++)
	{
		if(t[i] == 1)
		{
			if(c[i]<t1min)
			t1min=c[i];	
		}
		else if(t[i] == 2)
		{
			if(c[i]<t2min)
			t2min=c[i];	
		}
		else
		{
			if(c[i]<t3min)
			t3min=c[i];	
		}	

	}	

	long long int sum = t1min + t2min ;

	if(sum < t3min)
	cout<<sum;
	else 
	cout<<t3min;	
}