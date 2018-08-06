#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;

	int n,m;

	string s;

	cin >> t;

	char pattern[100][100];

	int rows[100];

	int col[100];

	while(t--){

		cin >> n >> m;

		for(int i=0;i<n;i++)
			rows[i] = 0;

		for(int i=0;i<m;i++)
			col[i] = 0;

		for(int i=0;i<n;i++){

			for(int j=0;j<m;j++)
				cin >> pattern[i][j];
		}

		cin >> s;

		for(int i=0;i<n;i++){

			for(int j=0;j<m;j++){

				if(pattern[i][j] == '1'){
					rows[i]++;
					col[j]++;
				}

			}
				
				
		}


		int l = s.length();

		for(int i=0;i<l;i++){

			if(s[i] == 'R'){


				for(int j=0;j<n;j++){

					for(int k=0;k<m;k++){

						if(k>=m-rows[j])
							pattern[j][k] = '1';
						else
							pattern[j][k] = '0';
					}	
				}

			}
			else if(s[i] == 'L'){

				for(int j=0;j<n;j++){

					for(int k=0;k<m;k++){

						if(k<rows[j])
							pattern[j][k] = '1';
						else
							pattern[j][k] = '0';
					}	
				}

			}
			else if(s[i] == 'U'){


				for(int k=0;k<m;k++){

					for(int j=0;j<n;j++){

						if(j<col[k])
							pattern[j][k] = '1';
						else
							pattern[j][k] = '0';
					}
				}

			}
			else{

				for(int k=0;k<m;k++){

					for(int j=0;j<n;j++){

						if(j>=(n-col[k]))
							pattern[j][k] = '1';
						else
							pattern[j][k] = '0';
					}
				}


			}

			for(int j=0;j<n;j++)
			rows[j] = 0;

			for(int k=0;k<m;k++)
			col[k] = 0;	

			for(int j=0;j<n;j++){

			for(int k=0;k<m;k++){

				if(pattern[j][k] == '1'){
					rows[j]++;
					col[k]++;
				}

			}
				
				
		  }


	}	



		for(int i=0;i<n;i++){

			for(int j=0;j<m;j++){

				cout << pattern[i][j];

			}

			cout << endl;
		}	

	}	

	return 0;
}