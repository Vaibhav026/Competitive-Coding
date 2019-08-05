#include<bits/stdc++.h>
using namespace std;




int main() {

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif



	int n;

	cin >> n;

	long long int a[2*n];

	long long int tot = 0;

	for(int i=0;i<2*n;i++){
		cin >> a[i];
		tot += a[i];
	}

	sort(a,a+2*n);

	long long int mids = 0;

	for(int i=0;i<n;i++){
		mids += a[i];
	}

	if(tot == 2*mids){
		cout << "-1";
	}
	else{

		for(int i=0;i<2*n;i++){
			cout << a[i] << " ";
		}
	}



	return 0;
}