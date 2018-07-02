#include <bits/stdc++.h>
using namespace std;


int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m;

	cin >> n >> m;

	
	char a[n][m];

	int prefix[n][m];


	char ch;

	for(int i=0;i<n;i++){

			
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];

			// a[i][j] = ch;

			if(a[i][j] == '1'){
				
				if(j == 0)
					prefix[i][j] = 1;
				else		
					prefix[i][j] = prefix[i][j-1] + 1;
			}
			else
				prefix[i][j] = 0;
		}

	}

	int count[m+1];

	 int ans = 0;
	 int temp= 0;
    
    int rem ;
	for(int j=0;j<m;j++){

		for(int i=0;i<=j+1;i++)
			count[i] = 0;

		for(int i=0;i<n;i++)
			count[prefix[i][j]]++;

	     rem = n;
		for(int i=0;i<=j+1;i++){

			temp = rem*i;

			if(temp > ans)
				ans = temp;

			rem = rem - count[i];

		}

	}


	printf("%d",ans);


	return 0;
}	