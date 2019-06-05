#include<bits/stdc++.h>
using namespace std;

#define FAST_IO                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{	
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
 //    freopen("error.txt", "w", stderr);
 //    #endif

    FAST_IO;

	int n;

	cin >> n;

	set<int> x;

	set<int> y;

	std::vector<int> ans;
	int tmp;

	for(int i=1;i<=n;i++){
		cin >> tmp;
		x.insert(tmp); 
	}

	for(int i=1;i<=(1000000);i++){

		if(x.find(i) == x.end()){
			y.insert(i);
		}
	}

	for(auto it = x.begin();it != x.end();it++){

		if(y.find((1000001-*it)) != y.end()){
			ans.push_back(1000001-*it);	
			y.erase(1000001-*it);
			x.erase(it);
		}
	}	

	int j=1;

	int siz = x.size()/2 ;

	while( j<= siz){

		auto it2 = y.begin();

		ans.push_back(1000001 - *it2);
		ans.push_back(*it2);

		y.erase(1000001 - *it2);
		y.erase(it2);

		j++;	
	}	



	cout << ans.size() << "\n";

	for(int i=0;i<ans.size();i++){

		cout << ans[i] << " ";
	}



	return 0;
}