#include <bits/stdc++.h>
using namespace std;




int main()
{
	int t;

	long int n,m;
	cin >> t;

	long int mod = 1000000007;

	long int a[100000],b[100000];


	long long int fib[100005];

	fib[1] = 1;
	fib[2] = 1;

	for(int i=3;i<=100000;i++)
		fib[i] = (fib[i-1]+fib[i-2])%mod;
	
	

	long int base_a,base_b;

	long long int sum_x,sum_y;

	long long int ans;

	while(t--){

		sum_x = 0;
		sum_y = 0;

		cin >> m >> n;

		for(long int i=0;i<m;i++)
			cin >> a[i];

		for(long int i=0;i<m;i++)
			cin >> b[i];

		// base_a = min_element(a,a+m);

		// base_b = min_element(b,b+m);

		for(long int i=0;i<m;i++){

			sum_x = (sum_x + (a[i]))% mod;
			sum_y = (sum_y + (b[i]))% mod;
		}
		
		if(n == 1){
			ans = sum_x;
		}
		else if(n == 2){
			ans = sum_y;
		}
		else
		ans = ((fib[n-1])*sum_y)% mod  +  ((fib[n-2])*sum_x)% mod;

		ans = (ans * m )% mod;
		
		cout << ans << "\n";
	}











	return 0;
}