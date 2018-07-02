#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,m;

	cin >> n >> m;

	char a[n][m];

	int count[m];

	for(int i=0;i<m;i++)
		count[i] = 0;
	
	for(int i=0;i<n;i++){

		
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];

			if(a[i][j] == '1')
				count[j]++;
		}

	}


	int min;

	int ans = 0;
	for(int i=0;i<m;i++){

		min = count[i];

		for(int j=i;j<m;j++){

			if(j == 0){

				min = count[0];
				ans = count[0];
			}
			else{

				if(count[j]<min)
					min = count[j];

				if(ans < (j-i+1)*min)
					ans = (j-i+1)*min ;
					
		    }
		}
	}

	cout << ans;








	return 0;
}	