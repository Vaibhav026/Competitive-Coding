#include<bits/stdc++.h>
using namespace std;

#include <math.h>       /* tan */

#define PI 3.14159265

int main(){

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	long double w,h,alpha;

	cin >> w >> h >> alpha;


	long double ar = w*h;

	//cout << ar << endl;
	if( (alpha) == 0 || alpha == 180){
		cout << ar;
		return 0;	
	}

	if(alpha == 90){
		ar = h*h;
		cout << ar;
		return 0;
	}

	if(alpha > 90){
		alpha = 180 - alpha;
	}	
	long double m1  = tan ( alpha * PI / 180.0 );

	long double x1 = ( h*( (long double)(1)/cos(alpha * PI / (long double)180.0 )-(long double)1) )/((long double)2 * m1) ;

	long double y1 = - h/(long double)2;


	long double x2 = w/2;

	long double y2 = m1*w/(long double)2 - h/2*((1)/cos(alpha * PI / 180.0 ));


	long double x3 = w/(long double)2;
	long double y3 = - h/(long double)2;


	ar = ar - ( (y2-y3)*(x3-x1) );


	m1 = -(long double)1/tan ( alpha * PI / 180.0 );

	x1 = (long double)1/m1 *( w/((long double)2*sin(alpha * PI / 180.0 )) - h/2);

	y1 = m1*(-w/(long double)2) - (w/(long double)2)*((long double)1/sin(alpha * PI / 180.0 ));

	ar = ar - ( (y1 + h/(long double)2)*(x1 + w/(long double)2) );

	std::cout << std::fixed;
	cout << std::setprecision(6) << ar;
}