#include <bits/stdc++.h>
using namespace std;


int main()
{

	int n,m;

	cin >> n >> m;

	long long int type[m];




	bool present[m][26];


	for(int i=0;i<m;i++){

		type[i] = 0;
		for(int j=0;j<26;j++)
			present[i][j] = false;
	}

	string s;

	int z;
	for(int i=0;i<n;i++){

		cin >> s;

		for(int j=0;j<m;j++){

			z = s[j]-'A';
			present[j][z] = true; 
		}

	}


	for(int i=0;i<m;i++){

		for(int j=0;j<26;j++){

			if(present[i][j])
				type[i]++;
		}


	}
    
    long int mod = 1000000007;

	long long int ans = 1;
	
	for(int i=0;i<m;i++){

		ans = (ans * type[i])% mod;

	}



	cout << ans;

	return 0;
}