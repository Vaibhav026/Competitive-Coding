// Problem name Greenhouse effect
#include <bits/stdc++.h>
using namespace std;

int lis(int a[], int n)
{
    int d[n];

    for(int i=0;i<n;i++)
    	d[i] = 1;

    for(int i=1;i<n;i++)
    {
    	for(int j=i-1;j>=0;j--){

    		if(a[j] <= a[i])
    			d[i] = max(d[i],d[j]+1);
    	}

    }

    int max = 0;
    for(int i=0;i<n;i++){

    	if(d[i] > max)
    		max = d[i];
    }
    	
    return max;

}
int main()
{
	int n,m;

	cin >> n >> m;

	int type[n];
	double x[n];

	for(int i=0;i<n;i++)
	{
		cin >> type[i] >> x[i];
	}	



	cout << n-lis(type,n);




	return 0;
}