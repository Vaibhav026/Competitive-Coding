#include<bits/stdc++.h>
using namespace std;

int main()
{

	int n;
	cin >> n;

	int a[n];

	int sum = 0 ;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}

	double req = (4.5)*n - sum;

	int steps = 0;

	sort(a,a+n);
	for(int i=0;i<n;i++){

		if(req<=0)
			break;

		if(a[i]!=5){
			req = req - (5-a[i]);
			steps++;
		}

	}	

	cout << steps;

	return 0;
}

