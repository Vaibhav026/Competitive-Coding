#include <bits/stdc++.h>
using namespace std;

int n,m;

int ix;

int a[101];

int cnt[101];

int arr[101];

int arrcp[101];

bool solve(int val){

	int it = ix -1;

	for(int i=1;i<=n;i++){

		if(arrcp[it] < val){
			return false;
		}
		else
		{
			arrcp[it] = arrcp[it] - val;
			if(arrcp[it] < val){
			 	it--;	
			}

			if(i!= n && it<0)
				return false;	
		}	
	}

	return true;
}

int main()
{
	cin >> n >> m;

	for(int i=1;i<=100;i++)
		cnt[i] = 0;

	for(int i=1;i<=m;i++){
		cin >> a[i];
		cnt[a[i]]++;
	}

	int l =1;
	int r = 100;

	int mid;

	int ans = 0;

	

	ix = 0;
	for(int i=1;i<=100;i++){

		if(cnt[i]>0){
			arr[ix] = cnt[i];
			arrcp[ix] = arr[ix];
			ix++;
		}
	}

	sort(arr,arr+ix);
	sort(arrcp,arrcp+ix);

	while(l<=r){


		mid = (l+r)/2;

		if(solve(mid)){
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid -1;


		for(int i=0;i<ix;i++)
			arrcp[i] = arr[i];
	}

	cout << ans;

	return 0;
}