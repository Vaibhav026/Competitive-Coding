#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int , pair<int,int>> p1,pair<int , pair<int,int>> p2){

	return ( (p1.second.first < p2.second.first) || (p1.second.first == p2.second.first && p1.second.second <= p2.second.second) );
}
int main(){


	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int n;

	cin >> n;

	int l,r;
	std::vector< pair< int , pair< int , int > > > v;


	for(int i=0;i<n;i++){
		cin >> l >> r;
		v.push_back(make_pair(i+1,make_pair(l,r)));
	}

	sort(v.begin(),v.end(),compare);

	// for(int i=0;i<v.size();i++){
	// 	cout << v[i].second.first << " " << v[i].second.second << "\n";
	// }

	vector<int> final;

	for(int i=1;i<=n;i++){


		bool ans = true;

		int prev = 0;

		for(int j = 1;j<n;j++){

			pair< int , pair< int , int > > p = v[j];
			
			

			if(v[j].first == i){
				prev = j-1;
			}
			else if( v[prev].first != i && v[j].second.first < v[prev].second.second){
				ans = false;
				break;
			}
			else{
				prev = j;
			}
		}

		if(ans){
			final.push_back(i);
		}

	}

	cout << final.size() << endl;

	for(int i=0;i<final.size();i++)
		cout << final[i] << " ";
	return 0;
}	