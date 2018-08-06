#include <bits/stdc++.h>
using namespace std;


int main()
{
	vector< pair<long int ,long int > > v;

	long int n;
	cin >> n;

	long int x,y;

	for(long int i=0;i<n;i++){

		cin >> x >> y;

		v.push_back(make_pair(x,y));
	}

	sort(v.begin(), v.end());
 	
 	long int endmax = v[0].second;

 	long int ans =0;
	for(int i=1;i<n;i++){

		if(v[i].second < endmax){
			ans++;
		}
		else
			endmax = v[i].second;

	}




	cout << ans;
	return 0;
}
