#include <bits/stdc++.h>
using namespace std;




int main(){


	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	long long int n,m,s;

	long long int ans = 0;

	cin >> n >> m >> s;

	if(s>=n && s>= m){
		cout << (n*m);
		//cout << "a";
		return 0;
	}
	else if(s >=n){

		long long int idx;

		long long int left = 1;
		long long int right = m;

		while(left <= right) {

			long long int mid = (left+right)/2 ;
			
			long long int tmp = 1+(mid-1)*s;

			if(tmp <=  m){
				idx = mid;
				left = mid+1;
			}
			else{
				right = mid-1;
			}
		}


		// long long int ans = 0;

		for(long long int i=1;i<=m;i++){

			long long int tmp = i + (idx-1)*s;

			if(tmp <= m){
				ans++;
			}
			else
				break;
		}


		ans  =	ans*n*idx; 
	}
	else if(s >= m){

		long long int idx;

		long long int left = 1;
		long long int right = n;

		while(left <= right) {

			long long int mid = (left+right)/2 ;
			
			long long int tmp = 1+(mid-1)*s;

			if(tmp <=  n){
				idx = mid;
				left = mid+1;
			}
			else{
				right = mid-1;
			}
		}


		// long long int ans = 0;

		for(long long int i=1;i<=n;i++){

			long long int tmp = i + (idx-1)*s;

			if(tmp <= n){
				ans++;
			}
			else
				break;
		}


		ans  =	ans*m*idx;
	}
	else{

		long long int idx;

		long long int left = 1;
		long long int right = m;

		while(left <= right) {

			long long int mid = (left+right)/2 ;
			
			long long int tmp = 1+(mid-1)*s;

			if(tmp <=  m){
				idx = mid;
				left = mid+1;
			}
			else{
				right = mid-1;
			}
		}


		// long long int ans = 0;

		for(long long int i=1;i<=m;i++){

			long long int tmp = i + (idx-1)*s;

			if(tmp <= m){
				ans++;
			}
			else
				break;
		}


		ans  =	ans*idx;



		long long int idx2;

		left = 1;
		right = n;

		while(left <= right) {

			long long int mid = (left+right)/2 ;
			
			long long int tmp = 1+(mid-1)*s;

			if(tmp <=  n){
				idx2 = mid;
				left = mid+1;
			}
			else{
				right = mid-1;
			}
		}


		long long int ans2 = 0;

		for(long long int i=1;i<=n;i++){

			long long int tmp = i + (idx2-1)*s;

			if(tmp <= n){
				ans2++;
			}
			else
				break;
		}

		ans2 = ans2*idx2;

		ans = ans*ans2;
		
	}

	cout << ans;
	return 0;
}