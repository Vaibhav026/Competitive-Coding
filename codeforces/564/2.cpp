#include<bits/stdc++.h>
using namespace std;




int main() {

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int val;

	double f = (double) (n+1)/2;
	// cout << f << endl;

	val = ceil(f);

	int left = n;

	cout << val << endl;

	for(int i=1;i<=val && left >0 ;i++){
		cout << "1 " << i << endl;
		left--;
	}

	for(int j=2;j<=val && left >0;j++){
		cout << j << " " << val << endl;
		left--;
	}

	return 0;
}