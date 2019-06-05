#include <bits/stdc++.h>
using namespace std;

int main()
{	
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

	int n,x,y;

	cin >> n >> x >> y;

	int b[n];

	int val;

	std::vector<int> v;
	for(int i=0;i<n;i++){

		cin >> b[i];

		if(b[i] <= x){
			val++;
			v.push_back(b[i]);
		}
	}

	sort(v.begin(),v.end());

	if(x < y){
		
		int l = v.size();

		int ans = 0;

		for(int i=0;i<v.size();i++){

			if(v[i] <= x)
				ans++;

			v[l-1] += y;
			
			if(v[l-1] > x){
				l--;
			}
		}

		cout << ans;
	}
	else{
		cout << n;
	}





	return 0;
}