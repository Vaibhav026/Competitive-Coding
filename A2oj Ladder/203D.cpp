#include<bits/stdc++.h>
using namespace std;



int main()
{	
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

	int a,b,m;

	cin >> a >> b >> m;

	int vx,vy,vz;

	cin >> vx >> vy >> vz;

	vy = -1*vy;

	long double t;

	t = (long double) m/(long double) (vy);


	long double ansz;


	long double d = t*vz;

	int df = floor(d);

	long double fractional = (d - (long double) df);

	if( (df/b)%2 == 0){
		ansz = df%b + fractional;
	}
	else{
		ansz = b - (df%b + fractional) ;
	}


	int vxplus = abs(vx);

	d = t*vxplus;


	long double firs;

	long double ansx;


	firs = (long double) a/ (long double) (2*vxplus) ;

	if( firs < t){


		d = d - (long double)a/(long double)2 ;


		df = floor(d);

		fractional = d - df;

		if(vx > 0){

			if( (df/a)%2 != 0){
				ansx = df%a + fractional;
			}
			else{
				ansx = a - (df%a + fractional);
			}

		}	
		else{
			//cout << "yes";

			if( (df/a)%2 == 0){
				ansx = df%a + fractional;
			}
			else{
				ansx = a - (df%a + fractional);
			}
		}

	}
	else{
		ansx = (long double) a/ (long double)2 + (long double)(t * (long double) vx);  
	}


	std::cout << std::fixed;
  	std::cout << std::setprecision(6) << ansx <<" ";
  	std::cout << std::setprecision(6) << ansz;

	return 0;
}