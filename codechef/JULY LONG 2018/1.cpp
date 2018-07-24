#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	int n,m;

	int a[31];
	long int count;
	while(t--){

		count = 1;

		cin >> n >> m;

		for(int i=0;i<n;i++){

			cin >> a[i];

			if(a[i]%m == 0){
				count = count*2;
			}
		}

		cout << count -1 << endl;
	}








	return 0;
}