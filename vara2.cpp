#include <iostream>
using namespace std;


int main()
{

	int n,k;

	cin >> n >> k;

	long int a[n+1][k+1];
		
	long int sum[n+1][k+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			a[i][j] = 0;

			sum[i][j] = 0;
		}
	}	

	// a[1][1] = 1;
	// sum[1][1] = 0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(j==1)
			a[i][j] =1;
			else if(i<j)
			a[i][j] = 0;
			else{		
			
			for(int z=i-1;z>=0;z--)
			{	
				if(a[z][j-1]!=0)
				a[i][j]+= a[z][j-1] + sum[i-z-1][j-1];
			}	
			
			}

			sum[i][j] += sum[i][j-1] + a[i][j];
		}
	}

	// for(int i=1;i<=3;i++)
	// {
	// 	for(int j=1;j<=3;j++)
	// 		cout << sum[i][j]<<" ";

	// 	cout << endl;
		
	// }

	cout << a[n][k];
	return 0;
}