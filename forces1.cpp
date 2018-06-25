#include <bits/stdc++.h>
using namespace std;


int main()
{
	long int n; 

	cin >> n;

	long int a[n];


	for(long int i=0;i<n;i++)
		cin >> a[i];

	bool hash[100001];

	bool nhash[100001];

	for(long int i=0;i<=100000;i++)
	{
		hash[i] = false;
		nhash[i] = false;
	}	

	for(long int i=0;i<n;i++)
	{
		if(a[i]>0)
			hash[a[i]] = true;
		else if(a[i]<0)
			nhash[(-1*a[i])] = true;
	}
		
	long int ans = 0;	
	for(long int i=1;i<=100000;i++)
	{
		if(hash[i])
			ans++;

		if(nhash[i])
			ans++;
	}

	cout << ans;		
	return 0;
}