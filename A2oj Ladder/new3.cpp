#include <bits/stdc++.h>
using namespace std;



int main()
{
	int n,k;

	cin >> n >> k;

	int a[n+1],sum[n+1];
	
	a[0] = 0;
	sum[0] = 0;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];

		sum[i] = sum[i-1] + a[i];
	}

	double max=0,temp;
	
	for(int i=1;i<=n;i++){

		for(int j = i+k-1;j<=n;j++){

			temp =(double) (sum[j] - sum[i-1])/(j-i+1) ;

			if(temp > max)
				max = temp;
		}

	}

	cout << std::fixed;
  
    cout << std::setprecision(9) ;
  
	cout << max;
}