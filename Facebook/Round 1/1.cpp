#include <bits/stdc++.h>
using namespace std;


int main()
{	
	#ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
 
	#endif
	
	int t;

	int n;

	cin >> t ;
    
    long long int mod = 1000000007;
    
	char path[3][1002];

	long long int ans;

	for(int in=1;in<=t;in++){


		cin >> n;

		ans = 1;

		for(int i=0;i<3;i++){

			for(int j=1;j<=n;j++)
				cin >> path[i][j];

		}


		cout << "Case #"<<in<<": ";
		if(n%2 != 0 || path[1][1] == '#' || path[0][1] == '#')
			ans = 0;
		else
		{	long long int temp;  
			for(int i=2;i<=n;i = i+2 ){

				if(i == n){

					if(path[1][i] == '.' && path[2][i] == '.')
						ans = ans*1;
					else
						ans = 0;

					break;
				}
				temp = 0;

				if(path[1][i] == '#' || path[1][i+1] == '#'){
					ans = 0;
					break;

				}

				if(path[0][i] == '.' && path[0][i+1] == '.' )
					temp++;

				if(path[2][i] == '.' && path[2][i+1] == '.' )
					temp++;

				if(temp == 0){
					ans = 0;
					break;
				}
				else
					ans = (ans * temp)%mod;
			

			}


		}


		cout << ans << "\n";

	}





	return 0;
}