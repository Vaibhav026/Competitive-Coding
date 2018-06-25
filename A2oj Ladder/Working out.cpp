#include<bits/stdc++.h>
using namespace std;

long long int max(long long int a,long long int b)
{
	if(a<=b)
		return b;
	else
		return a;
}



int main()
{
	int n,m;

	cin >> n >> m;

	long long int a[n][m];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];
		}	

	}	

	// first person

	long long int best11toij[n][m];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0)
			{
				if(j == 0)
				best11toij[i][j] = a[i][j];
				else
				best11toij[i][j] = best11toij[i][j-1] + a[i][j];	
			}
			else if(j==0)
			{
				best11toij[i][j] = best11toij[i-1][j] + a[i][j];	
			}
			else
			{
				best11toij[i][j] = a[i][j] + max(best11toij[i-1][j],best11toij[i][j-1]);
			}		
		}	

	}	



	long long int bestijtonm[n][m];

	

	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			if(i == n-1)
			{
				if(j == m-1)
				bestijtonm[i][j] = a[i][j];
				else
				bestijtonm[i][j] = bestijtonm[i][j+1] + a[i][j];

				
			}
			else if(j == m-1 )
			{
				bestijtonm[i][j] = bestijtonm[i+1][j] + a[i][j];

				
			}
			else
			{	

				bestijtonm[i][j] = a[i][j] + max(bestijtonm[i+1][j],bestijtonm[i][j+1]);
			}

		}	

	}

	// long long int best1ij[n][m];

	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		best1ij[i][j] = best11toij[i][j] +bestijtonm[i][j] - 2*a[i][j];		
	// 	}	

	// }



	
	// second person

	long long int bestn1toij[n][m];

	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<m;j++)
		{
			if(i == n-1)
			{
				if(j == 0)
				bestn1toij[i][j] = a[i][j];
				else
				bestn1toij[i][j] = bestn1toij[i][j-1] + a[i][j];	
			}
			else if(j==0)
			{
				bestn1toij[i][j] = bestn1toij[i+1][j] + a[i][j];	
			}
			else
			{
				bestn1toij[i][j] = a[i][j] + max(bestn1toij[i+1][j],bestn1toij[i][j-1]);
			}		
		}	

	}	


	long long int bestijto1m[n][m];

	for(int i=0;i<n;i++)
	{
		for(int j=m-1;j>=0;j--)
		{
			if(i == 0)
			{
				if(j == m-1)
				bestijto1m[i][j] = a[i][j];
				else
				bestijto1m[i][j] = bestijto1m[i][j+1] + a[i][j];	
			}
			else if(j == m-1 )
			{
				bestijto1m[i][j] = bestijto1m[i-1][j] + a[i][j];	
			}
			else
			{	
				if(bestijto1m[i-1][j]<bestijto1m[i][j+1] )
					bestijto1m[i][j] = a[i][j] + bestijto1m[i][j+1];
				else
					bestijto1m[i][j] = a[i][j] + bestijto1m[i-1][j];

			}		
		}	

	}

	// long long int best2ij[n][m];

	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<m;j++)
	// 	{
	// 		best2ij[i][j] = bestn1toij[i][j] +bestijto1m[i][j] - 2*a[i][j];		
	// 	}	

	// }

	long long int ans[n][m];

	long long int temp1,temp2,temp3;
	long long int maxi = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		
			if(i!=0 && j!=0 && i!=n-1 && j!=m-1)
			{
				temp1 = best11toij[i][j-1] + bestn1toij[i+1][j] + bestijtonm[i][j+1] + bestijto1m[i-1][j];
				temp2 = best11toij[i-1][j] + bestn1toij[i][j-1] + bestijtonm[i+1][j] + bestijto1m[i][j+1];

				temp3 = max(temp1,temp2);
				if(maxi < temp3)
					maxi = temp3;

 			}	
			
			
		}

		
			

	}

	cout << maxi;
	return 0;
}	