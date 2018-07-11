#include <bits/stdc++.h>
using namespace std;

int main()
{

	int n;

	cin >> n;

	int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	int num_ways = 0;
	int steps = 0;

	vector<int> ans;
	for(int i=0;i<n;i++){

		if(a[i] == 1){

			if(i!= 0){

				ans.push_back(steps);
			}

			num_ways++;
			steps = 1;
		}
		else
			steps++;

		if(i == n-1){
			ans.push_back(steps);
		}

	}


	int l = ans.size();

	cout << num_ways << endl;
	for(int i=0;i<l;i++)
		cout << ans[i] << " ";





	return 0;
}