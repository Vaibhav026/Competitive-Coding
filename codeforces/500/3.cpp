#include<bits/stdc++.h>
using namespace std;



int main()
{
	int n;

	cin >> n;

	long int a[2*n];

	long int siz = 2*n;
	
	for(int i=0;i<siz;i++)
		cin >> a[i];

	sort(a,a+siz);

	long long int x = a[n-1] - a[0];

	long long int y = a[siz-1] - a[n];



	cout << (x)*(y);





	return 0;
}