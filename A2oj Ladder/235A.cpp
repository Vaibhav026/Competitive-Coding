#include <bits/stdc++.h>
using namespace std;




int main()
{
	long long int n;

	cin >> n;

	long long int ans;

	if(n == 1)
		ans = 1;
	else if(n == 2)
		ans = 2;
	else if(n%2 == 1){

		ans = (n)*(n-1)*(n-2);
	}
	else{

		if(n%3 != 0)
			ans = n*(n-1)*(n-3);
		else
			ans = (n-1)*(n-2)*(n-3);

	}

	cout << ans;
	return 0;
}