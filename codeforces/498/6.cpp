#include <bits/stdc++.h>
using namespace std;

int n,m;
long long int k;

long long int a[20][20];

long int ans[20][20];

long int solve(int i,int j,long long int temp){

	if(i >= n || j>=m)
		return 0;

	if(i == n-1 && j == m-1){
		if(temp == a[i][j])
			return 1;

		return 0;
	}

	long int x = solve(i+1,j,temp^a[i][j]);
	
	long int y = solve(i,j+1,temp^a[i][j]);

	return (x+y);
} 


int main()
{

	

	

	cin >> n >> m >> k;

	

	for(int i=0;i<n;i++){

		for(int j=0;j<m;j++){

			cin >> a[i][j];
		}
	}

	long int ans = solve(0,0,k);

	cout << ans;

	return 0;
}