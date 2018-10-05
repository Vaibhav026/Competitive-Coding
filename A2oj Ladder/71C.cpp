#include<bits/stdc++.h>
using namespace std;

int a[100005];
int n;

bool solve(int x){
	bool arr[100005];

	if(n%2 == 0){

		if(x >= (n/2))
			return false;
	}	
	else{
		if(x > (n/2))
			return false;
	}

	arr[0] = true;

	for(int i=1;i<=x;i++){
		if(a[i] == 1)
			arr[i] = true;
		else
			arr[i] = false;
	}

	//cout << arr[1]  << endl;
	for(int i=x+1;i<=n;i++){	

		
		if(a[i] == 1 && arr[i-x] == true)
			arr[i] = true;
		else
			arr[i] = false;
	}

	for(int i=n;i>=(n-x+1);i--){

		//cout << i << " " << arr[i] << endl << endl;
		if(arr[i])
			return true;
	}

	return false;
}
int main()
{	
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

	cin >> n;

	for(int i=1;i<=n;i++)
		cin >> a[i];

	//cout << solve(1) << endl;
	if(solve(1)){
		cout << "YES";
		return 0;
	}

	for(int i=2;i<=sqrt(n);i++){

		if(n%i == 0){

			if(solve(i) || solve(n/i)){
				//cout << i << endl;
				cout << "YES";
				return 0;
			}

		}

	}

	cout << "NO";
}