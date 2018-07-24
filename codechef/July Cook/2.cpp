#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin >>t;

	char a[1000][1000];

	int n,m;

	bool rows[1000];
	bool col[1000];
	while(t--){


		for(int i=0;i<1000;i++){
			rows[i] = false;
			col[i] = false;
		}
			
		cin >> n >> m;

		bool possible = false;

		for(int i=0;i<n;i++){

			for(int j=0;j<m;j++){
				cin >> a[i][j];

				if(a[i][j] == '1'){
					possible = true;	
					rows[i] = true;
					col[j] = true;
				}	
			}
		}

		for(int i=0;i<n;i++){

			for(int j=0;j<m;j++){
				
				if(!possible)
					cout << "-1 ";
				else if(a[i][j] == '1')
					cout <<"0 ";
				else if(rows[i] || col[j])
					cout << "1 ";
				else
					cout << "2 ";
			}
			cout << endl;
		}
	} 












	return 0;
}