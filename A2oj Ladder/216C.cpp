#include <bits/stdc++.h>
using namespace std;


int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

	int n,m,k;

	cin >> n >> m >> k;

	if(m < n){

		int num = (2*k);
		
		if(k == 1 && m == n-1)
			num++;

		cout << num << endl;

		for(int i=1;i<=k;i++)
			cout << "1 ";

		if(k == 1 && m == n-1)
			k++;

		for(int i=1;i<k;i++)
			cout << (m+1) << " ";

		cout << (m+2) << " ";
	}
	else{

		int num = (2*k + 1);

		if(n == 2 && k == 1)
			num++;

		cout << num << endl;

		

		for(int i=1;i<=k;i++)
			cout << "1 ";

		cout << m << " ";

		if(n == 2 && k == 1)
			k++;

		for(int i=1;i<=(k-1);i++)
			cout << (m+1) << " ";

		cout << (m+2) << " ";


	}










	return 0;
}