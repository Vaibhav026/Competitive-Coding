#include <bits/stdc++.h>
using namespace std;

#define fl(i, a, b)     for(int i(a); i < (b); i ++)
#define rep(i, n)       fl(i, 0, n)
#define rep1(i, n)      fl(i, 1, n)
#define rfl(i, a, b)    for(int i(a); i >= (b); i --)


int main()
{
	int n;
	cin >> n;

	long int m,q;
	cin >> m >> q;

	long int p = pow(2,n);

	long int type[p];

	string sp[p];

	int w[n];

	rep(i,n){
		cin >> w[i];
	}


	string s;

	rep(i,m){

		cin >> s;

		long int sum = 0;
		for(int j=0;j<n;j++){
			
			if(s[j] == '1'){
				sum += pow(2,(i));
				
			}
			
				
		}

		type[sum]++;

	}	

	long int wu[p][p];

	rep(i,p){
		rep(j,p){
			wu[i][j] = 0;
		}
	}

	rep(i,p){

		rep(j,p){

			rep(k,n){
				
				long int y = i^j; 
				
				for(int i=n-1;i>=0;i--){
					
				}

				if(sp[i][k] == sp[j][k])
					wu[i][j] += w[k]; 
			}

		}

	}

	int ans[p][101];

	rep(i,p){
		rep(j,100){
			ans[i][j] = 0;
		}
	}

	

	rep(j,p){

		rep(i,p){
			ans[j][wu[i][j]] += type[j];
		}
	}


	rep(i,p){

		rfl(j,100,0){
			ans[i][j] += ans[i][j-1];
		}
	}

	string ss;

	int k;

	rep(i,q){

		cin >> ss;
		cin >> k;

		long int sum = 0;
		for(int j=0;j<n;j++){
			
			if(ss[j] == '1'){
				sum += pow(2,(j));
				
			}
	
		}

		cout << ans[sum][k] << endl;
	}


	return 0;
}