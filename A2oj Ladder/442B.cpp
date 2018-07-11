#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	double a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	sort(a,a+n);

	double p1[n];
	double p0[n];

	double s = 0 ;

	int i;
	for(i=n-1;i>=0;i--){

		if(i == n-1){
			s += a[i]/(1-a[i]) ;
			p1[i] = a[i];
			p0[i] = 1-a[i];
		}
		else{
			p1[i] = a[i]*(p0[i+1]) + (1-a[i])*p1[i+1];
			p0[i] = (1-a[i])*p0[i+1];

			s += a[i]/(1-a[i]) ;
		}

		if(s>1)
			break;
	}

	cout << std::fixed;
  
  cout << std::setprecision(9) ;
  

	

	if(i<0)
		cout << p1[0];
	else
	cout << p1[i];



	return 0;
}