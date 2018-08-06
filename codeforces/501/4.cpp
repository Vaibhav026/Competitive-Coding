#include <bits/stdc++.h>
using namespace std;


int main()
{
	
	int n,m;


	cin >> n >> m;


	char a[n][m];

	bool b[n][m];

	for(int i=0;i<n;i++){

		for(int j=0;j<m;j++)
			cin >> a[i][j];

	}

	for(int i=0;i<n;i++){

		for(int j=0;j<m;j++)
			b[i][j] = false;

	}

	int u,d,l,r;

	for(int i=0;i<n;i++){

		u =0;
		l=0;
		d =0;
		r =0;

		for(int j=0;j<m;j++){

			if(a[i][j] == '*'){

				k = i-1;
				while(k>0){
					if(a[k][j] == '*'){
						u++;
						k--;
				   }	
				}
			}



		}


	}

	return 0;
}