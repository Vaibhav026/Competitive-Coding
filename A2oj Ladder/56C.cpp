#include <bits/stdc++.h>
using namespace std;




int main(){


	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;

	cin >> s;

	int i,l;

	i = 0;
	l = s.length();

	string str = "";
	
	std::vector<string> v;

	long int ans = 0;
	while(i<l){

		if(s[i] == '.' || s[i] == ':' || s[i] == ','){

			if(str != ""){
				v.push_back(str);
				
				int lst = v.size()-1;

				for(int j = v.size()-2; j>=0;j--){
					
					if(v[lst] == v[j]){
						ans++;
					}			
				}
				str = "";
			}

			if(s[i] == '.'){
				v.pop_back();
			}

		}
		else{
			str += s[i];
		}

		i++;
	}

	cout << ans;
	return 0;
}