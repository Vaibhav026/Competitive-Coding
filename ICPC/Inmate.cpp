#include<bits/stdc++.h>
using namespace std;

long long int a[100000];
long long int t,n,c;

bool sol(long int val){

	long int prev = a[0];

	long int diff;

	long int siz = 1;
	for(int i=1;i<n;i++){

		diff = a[i]-prev;

		if(diff >= val){
			prev = a[i];
			siz++;
		}

		if(siz ==  c){
			return true;
		}
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
	

	cin >> t;


	while(t--){

		cin >> n >> c;

		for(int i=0;i<n;i++)
			cin >> a[i];


		sort(a,a+n);

		long long int left = 0;

		long long int right = 1000000000;

		long long int mid;

		long long int ans;

		while(left <= right){

			mid = (left + right)/2 ;

			if(sol(mid)){
				left = mid + 1;
				ans = mid;
			}
			else
				right = mid -1;

		}

		if(n < c)
			cout << "-1\n";
		else
		cout << ans << endl;
	}


}