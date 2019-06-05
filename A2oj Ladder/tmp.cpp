#include<bits/stdc++.h>
using namespace std;

#define FAST_IO                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{	
	#ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     freopen("error.txt", "w", stderr);
     #endif

    FAST_IO;

	long int n;

	cin >> n;

	set<long int> x;

	set<long int> y;

	std::vector<long int> ans;
	long int tmp;

	for(long int i=1;i<=n;i++){
		cin >> tmp;
		x.insert(tmp); 
	}

	for(long int i=1;i<=(1000000);i++){

		if(x.find(i) == x.end()){
			y.insert(i);
		}
	}
    
    auto it = x.begin();
    
	while(it != x.end()){
        
        long int val = 1000001-(*it);
        
		if(y.find((val)) != y.end()){
			
			it++;
			auto ut = it;
			ut--;
			ans.push_back(1000001-(*ut) );	
			y.erase(1000001-(*ut) );
			x.erase(ut);
			//cout << "1";
		}
		else
		    it++;
	}	

	long int j=1;

	long int siz = x.size()/2 ;

	while( j<= siz){

		auto it2 = y.begin();
        
		ans.push_back(1000001 - *it2);
		ans.push_back(*it2);

		y.erase(1000001 - *it2);
		y.erase(it2);

		j++;	
	}	



	cout << ans.size() << "\n";

	for(long int i=0;i<ans.size();i++){

		cout << ans[i] << " ";
	}



	return 0;
}