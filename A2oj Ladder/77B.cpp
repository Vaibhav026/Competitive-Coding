#include <bits/stdc++.h>
using namespace std;


int main()
{
	
	 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

	int t;
	cin >> t;

	long double a,b;

	long double ans;
	while(t--){

		cin >> a >> b;

		if(a == 0 && b ==0 ){
			ans = 1.0000000000;
		}
		else if(a == 0){
			ans = 0.50000000000;
		}
		else if(b == 0){
			ans = 1.000000000000;
		}
		else if(a > (4*b)){
			ans = 0.500000000 + (long double)((long double)(a-2*b)/(long double)(2*a)) ;
		}
		else{
			ans = 0.5000000000 + (long double)((long double)(a)/(long double)(16*b)) ;	
		}
		

		std::cout << std::fixed;
  		std::cout << std::setprecision(9) << ans << '\n';
	}







	return 0;
}