#include <bits/stdc++.h>
using namespace std;


int main()
{

	int n,m;

	cin >> n >> m;

	bool row[n+1];

	bool col[n+1];

	for(int i=0;i<=n;i++){

		row[i] = false;
		col[i] = false;

	}

	int x,y;
	for(int i=1;i<=m;i++){
		cin >> x >> y;

		row[x] = true;
		col[y] = true;

	}

	int ans = 0;

	int mid;
	if(n%2 == 0){
		//cout << "vainbhav";
		for(int i=2;i<=(n-1);i++){
			if(!row[i])
				ans++;

			if(!col[i])
				ans++;
		}
	}
	else{

		double x = (double) n/2;
		
		mid = ceil(x);

		//cout << mid << endl;
		for(int i=2;i<=(n-1);i++){
			

			if( i == mid ){

				if(!row[i] || !col[i])
				ans++;
			}
			else{
			if(!row[i])
				ans++;

			if(!col[i])
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
	
}
