#include <bits/stdc++.h>
using namespace std;


int main()
{
	long int n;
	long int m;


	cin >> n >> m;

	long int a[n],b[n];

	long int diff[n];

	long long int sum = 0;
	for(long int i=0;i<n;i++){

		cin >> a[i] >> b[i];

		sum += a[i];

		diff[i] = a[i] - b[i];
	}

	sort(diff,diff+n);

	long long int req;

	if(sum<=m){
		cout << "0";
	}
	else{	

		req = sum - m;
		long long int ans = 0,temp = 0;
		bool is = false;

		for(int j=n-1;j>=0;j--){

			temp += diff[j];
			ans++;

			if(temp >= req){
				is = true;
				break;
			}

		}


		if(is)
			cout << ans;
		else
			cout << "-1";

	}






	return 0;
}