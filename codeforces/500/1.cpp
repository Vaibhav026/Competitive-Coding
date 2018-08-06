#include <bits/stdc++.h>
using namespace std;


int main()
{

	int n;
	cin >> n;

	long int sum1 = 0;
	long int sum2 = 0;
	
	long int x;

	for(int i=0;i<n;i++){
		cin >> x;
		sum1 += x; 
	}

	for(int i=0;i<n;i++){
		cin >> x;
		sum2 += x; 
	}

	if(sum1 >= sum2){
		cout << "YES";
	}
	else
		cout << "NO";











	return 0;
}
