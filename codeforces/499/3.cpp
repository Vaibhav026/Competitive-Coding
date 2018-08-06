#include <bits/stdc++.h>
using namespace std;

int n;
double m;
int a[1001],b[1001];



bool solve( double x){

	 double mass = ( double) m + x ;

	 double f,f1,f2;

	for(int i=1;i<=n;i++){

		
		if(i == 1){

			f = (double) mass/(double) a[i] ;
		}
		else if(i < n){

			f1  = (double) (mass)/(double) b[i] ;

			mass = mass - f1;

			if(mass < m){
			return false;
			}

			f2  =  (double) (mass)/(double) a[i] ;

			f =  f2;
		}
		else
		{
			f = (double) mass/(double) b[i] ;
		}

		mass = mass - f;

		if(mass < m){
			return false;
		}

		
				
	}

	f = (double) mass/(double) a[n] ;

	mass = mass - f;

	if(mass < m)
		return false;

	f = (double) mass/(double) b[1] ;
	
	mass = mass - f;

	if(mass < m)
		return false;

	return true;	
}

int main()
{
	

	cin >> n;
	cin >> m;

	for(int i=1;i<=n;i++){
		cin >> a[i];
	}

	for(int i=1;i<=n;i++){
		cin >> b[i];
	}

	 double l,r;
	l = 1;
	r = 1000000001;

	 double mid,ans;

	ans = -1;

	while(l<=r){

		mid = (double) (l+r)/2;

		if(solve(mid)){
			//cout << mid << endl;
			ans = mid;
			r = mid - 0.0000001;
		}
		else{
			l = mid + 0.0000001;
		}

		//cout << "inf" << endl;
	}

	
	if(ans == -1)
		cout << "-1";
	else{
	std::cout << std::fixed;
   std::cout << std::setprecision(6) << ans; 
	}

   // cout << endl;

   // 	cout << solve(10) << endl;
	return 0;
}
