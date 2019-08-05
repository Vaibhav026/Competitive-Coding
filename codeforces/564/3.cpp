#include<bits/stdc++.h>
using namespace std;




int main() {

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;

	cin >> n;
	int a[n];

	set<int> ax;

	int b[n];

	set<int> bx;

	int one_index = -1;

	for(int i=0;i<n;i++){
		cin >> a[i];
		ax.insert(a[i]);
	}

	for(int i=0;i<n;i++){
		cin >> b[i];

		bx.insert(b[i]);

		if(b[i] == 1)
			one_index = i;
	}


	int ii = one_index;

	bool is = true;

	int val = 1;

	if(one_index == -1){
		is = false;
		ii = n+1;
	}

	while(ii < n){

		if(b[ii] != val){
			is = false;
			break;
		}

		val++;
		ii++;

	}

	if(is){

		if(one_index == 0){
			cout << "0";
			return 0;
		}

		int indx = 0;

		int moves = 0;
		while(val <= n){

			if(ax.find(val) == ax.end()){
				break;
			}
			else{

				ax.insert(b[indx]);
				moves++;
				indx++;
			}

			val++;
		}

		if(val == n+1){
			cout << moves << endl;
			return 0;
		}

	}


	int one = 0;

	for(int i=0;i<n;i++){

		if(b[i] != 0){
			one = max((i - b[i] + 2),one);
		}

	}

	int ans = one + n;
	cout << ans;
	return 0;
}