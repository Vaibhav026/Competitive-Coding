#include <bits/stdc++.h>
using namespace std;

int main()
{
	long int n,k,d;

	cin >> n >> k >> d;


	long long int tmp = 1;
    bool check = false;
    for (int i = 0; i < d; i ++)
    {
        tmp *= k;
        if (tmp >= n)
        {
            check = true;
            break;
        }
    }

    if (!check) 
    {
        cout << -1 << endl;
        return 0;
    }

	long int ans[n][d];

	for(int i=0;i<n;i++){

		for(int j=0;j<d;j++)
			ans[i][j] = 0;

	}

	int j;
	for(int i=0;i<n;i++){

		int num = i;

		j = d-1;

		while(num){
			ans[i][j] = num%k;
			num = num/k;
			j--;

		}



	}


	for(int j=0;j<d;j++){

		for(int i=0;i<n;i++)
			cout << ans[i][j]+1 << " ";

		cout << endl;
	}










	return 0;
}