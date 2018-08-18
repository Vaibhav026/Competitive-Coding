#include<bits/stdc++.h>
using namespace std;


long long int a[100001];
long int n;

bool possible(long long int x){

	int j =0;
	long long int rounds = 0;

	while(j<n){

		rounds += (x - a[j]);
		
		if(rounds >= x){
			return true;
		}

		j++;	
	}

	

	return false;
}

int main(){

	

	cin >> n;

	long long int mx = -1;
	for(int i=0;i<n;i++){
		cin >> a[i];

		if(a[i]>mx)
			mx = a[i];
	}


	long long int l = mx;
	long long int r = 1000000000000000000;

	long long int mid;

	long long int ans = r;

	while(l<=r){

		mid = (l+r)/2;

		//cout  << l << " " << r << endl;
		if(possible(mid) ){
			
			if(mid < ans)
				ans = mid;

			r = mid-1;
		}
		else{
			l = mid+1;
		}

	}

	cout << ans;
 return 0;
}