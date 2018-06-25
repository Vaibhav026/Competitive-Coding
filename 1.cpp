#include <iostream>

using namespace std;


int main()
{
	int n,m;

	cin >> n >> m;

	int x[n];

	for(int i=0;i<n;i++)
	cin>>x[i];
	
	bool y[10];

	int z;
	for(int i=0;i<10;i++)
		y[i] = false;
	
	for(int i=0;i<m;i++)
	{	
		cin >>z;
		y[z] = true;

	}	

	for(int i=0;i<n;i++)
	{
		if(y[x[i]])
			cout<<x[i]<<" ";
	}	


	return 0;
}