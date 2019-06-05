#include <bits/stdc++.h>
using namespace std;


int main()
{
	// #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int n,m,k;

    cin >> n >> m;

    long long ans[n+1][m+1];

    cin >> k;

    long long x[k],y[k];

    for(int i=0;i<k;i++){
    	cin >> x[i] >> y[i];
    }

    for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
    		ans[i][j] = 40000000; 
    	}
    }

    for(long long i=1;i<=n;i++){

    	for(long long j=1;j<=m;j++){

    		for(int it=0;it<k;it++){
    			ans[i][j] = min(ans[i][j],abs(y[it]-j) + abs(x[it] -i));
    		}
    	}
    }

	
	long long final = 0;

	long long xindex,yindex;

	xindex = 1;
	yindex = 1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){

			if(final < ans[i][j]){
				final = ans[i][j];
				xindex = i;
				yindex = j;
			}
 			//final = max(final,ans[i][j]);
    	}
    }

    cout << xindex << " " << yindex;
    return 0;	
}