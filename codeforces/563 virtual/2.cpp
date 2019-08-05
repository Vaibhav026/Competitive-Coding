#include<bits/stdc++.h>
using namespace std;




int main() {

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;

	cin >> n;

	long int a[n];

	int even = 0;
	int odd = 0;

	for(int i=0;i<n;i++){
		cin >> a[i];

		if(a[i]%2 == 0){
			even++;
		}
		else
			odd++;
	}

	if(even == 0 || odd == 0){
		for(int i=0;i<n;i++)
			cout << a[i] << " ";
	}
	else{
		sort(a,a+n);
		for(int i=0;i<n;i++)
			cout << a[i] << " ";	
	}

	return 0;

}