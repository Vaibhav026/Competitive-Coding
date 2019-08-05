#include <bits/stdc++.h>
using namespace std;




int main(){

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	long double H,L;

	cin >> H >> L;

	long double ans;

	long double two = (long double) 2;

	ans = (L*L - H*H)/(two * H);

	std::cout << std::fixed;
  	std::cout << std::setprecision(8) << ans;
  	
	return 0;
}	