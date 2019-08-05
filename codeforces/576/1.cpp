#include <bits/stdc++.h>
using namespace std;




int main(){
	
	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	long int n,x,y;

	cin >> n >> x >> y;

	long int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	bool flag;

	for(int i = 0;i< n ;i++){

		flag = true;

		for(int j = i-1; j >=0 && j >=(i-x);j--){
			if(a[i] > a[j] ){
				flag = false;
				break;
			}
		}

		for(int j = i+1 ; j < n && j <= (i+y) ; j++ ){
			if(a[i] > a[j]){
				flag = false;
				break;
			}
		}

		if(flag){
			cout << (i+1);
			return 0;
		}
	}

	return 0;
}	