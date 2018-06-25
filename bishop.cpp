
#include <iostream>
using namespace std;

long long int maximum(long long int a,long long int b)
{
	if(a>b)
		return a;
	else
		return b;
} 


int main()
{
	int n;
	cin >> n;

	long int a[n+1][n+1];

	long long int d[2*n+1];

	int max_xd[2*n+1];
	int max_yd[2*n+1];

	long long int d2[2*n+1];

	int max_xd2[2*n+1];
	int max_yd2[2*n+1];

	int siz = 2*n;

	for(int i= 2;i<= siz;i++)
	{
		d[i] = 0;
		d2[i] = 0;

		max_xd[i] = 0;
		max_yd[i] = 0;

		max_xd2[i] = 0;
		max_yd2[i] = 0; 
	}	

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];

			d[i+j] += a[i][j];

			d2[i-j+n+1] += a[i][j];
		}	


	}	

	cout << endl;

	// for(int i=2;i<=2*n;i++)
	// cout << d2[i]<<" ";
		
	long long int sum[n+1][n+1];

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum[i][j] = d[i+j] + d2[i-j+n+1] - a[i][j];
		}	

	}	

	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		cout << sum[i][j] << " "; 		
	// 	}	

	// 	cout << endl;
	// }	

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if( max_xd[i+j] == 0 || ( sum[i][j] > sum[max_xd[i+j]][max_yd[i+j]] )  )
			{	
				max_xd[i+j] = i;
				max_yd[i+j] = j;
			}

			if( max_xd2[i-j+n+1] == 0 || ( sum[i][j] > sum[max_xd2[i-j+n+1]][max_yd2[i-j+n+1]] )  )
			{	
				max_xd2[i-j+n+1] = i;
				max_yd2[i-j+n+1] = j;
			}	
		}	

	}

	// for(int i=2;i<=2*n;i++)
	// 	cout << i << " "<<max_xd2[i] << " " << max_yd2[i] << endl;

	int x1,y1,x2,y2;

	int x1ans,y1ans,x2ans,y2ans;

	long long int ans = 0;

	long long int temp ;

	long long int t1,t2,t3,t4;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{	
			if(i+j != 2)
			t1 = sum[max_xd[i+j-1]][max_yd[i+j-1]];
			else
			t1 = -1;
			
			if(i+j != 2*n)	
			t2 = sum[max_xd[i+j+1]][max_yd[i+j+1]];
			else
			t2 = -1;
			
			if(i-j+n+1 != 2*n)	
			t3 = sum[max_xd2[i-j+n+1 +1 ]][max_yd2[i-j+n+1 +1]];
			else
			t3 = -1;
			
			if(i-j+n+1 != 2)
			t4 = sum[max_xd2[i-j+n+1 -1 ]][max_yd2[i-j+n+1 -1]];
			else
			t4 = -1;	

			long long int z= maximum(maximum(t1,t2),maximum(t3,t4));

			if(z == t1)
			{
				x1 = max_xd[i+j-1];
				y1 = max_yd[i+j-1]; 
			}	
			else if(z == t2)
			{
				x1 = max_xd[i+j+1];
				y1 = max_yd[i+j+1];
			}
			else if( z == t3)
			{
				x1 = max_xd2[i-j+n+1 +1 ];
				y1 = max_yd2[i-j+n+1 +1 ];
			}
			else
			{
				x1 = max_xd2[i-j+n+1 -1 ];
				y1 = max_xd2[i-j+n+1 -1 ];
			}

			temp = sum[i][j] + z;

			if(temp>ans)
			{
				x1ans = x1;
				y1ans = y1;

				x2ans = i;
				y2ans = j;

				ans = temp;

			}	

		}	
	}

	cout << ans << endl;
	cout << x1ans << " "<<y1ans<<" "<<x2ans<<" "<<y2ans;

	return 0;
}
