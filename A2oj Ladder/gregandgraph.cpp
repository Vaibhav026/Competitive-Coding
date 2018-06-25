#include<bits/stdc++.h>
using namespace std;

long long int min(long long int a,long long int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

int main()
{
	int n;
	cin >> n;

	long int a[n+1][n+1];

	for(int i=1;i<=n;i++){

		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	}

	int vertex[n+1];

	long long int path[n+1][n+1];

	for(int i=1;i<=n;i++){

		for(int j=1;j<=n;j++)
			path[i][j] = 0;
	}



	for(int i=1;i<=n;i++)
		cin >> vertex[i];	

 	long long int temp;

 	bool inside[n+1];

 	long long int ans[n+1];

 	for(int i=1;i<=n;i++)
		inside[i] = false;

	for(int k=n;k>=1;k--){

		inside[vertex[k]] = true;

		for(int i=1;i<=n;i++){

			for(int j=1;j<=n;j++)
			{
				if(inside[i] && j == vertex[k])
				{	path[i][j] = a[i][j];	
					path[j][i] = a[j][i];
				}

				
			}
		
		}

		int in =vertex[k];
		
		for(int z=n;z>=k;z--){

		for(int j=1;j<=n;j++)
		{
			if(inside[j])
			{
				path[in][j] = min(path[in][j],path[in][vertex[z]]+path[vertex[z]][j]);
			}	

		}	

		}


		for(int z=n;z>=k;z--){

		for(int i=1;i<=n;i++)
		{
			if(inside[i])
			{
				path[i][in] = min(path[i][in],path[i][vertex[z]]+path[vertex[z]][in]);
			}	

		}	

		}



		long long int sum = 0;

		for(int i=1;i<=n;i++){

			for(int j=1;j<=n;j++)
			{
				if(inside[i] && inside[j])
				{
					temp = path[i][vertex[k]] + path[vertex[k]][j];

					if(temp < path[i][j])
						path[i][j] = temp;
				}

				sum += path[i][j];	

			}
		
		}

		ans[k] = sum;

	}




	for(int i=1;i<=n;i++){

		cout << ans[i] << " ";
	}






	return 0;
}