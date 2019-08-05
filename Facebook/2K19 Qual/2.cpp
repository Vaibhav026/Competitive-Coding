#include<bits/stdc++.h>
using namespace std;




int main() {

	// #ifndef ONLINE_JUDGE    
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int t;

	cin >> t;

	string s;

	int cnt;

	int val;

	int len;

	for(int i=1;i<=t;i++){

		cnt = 0;

		cin >> s;

		len = s.length();
		
		for(int j=1;j<len;j++){
			
			if(s[j] == 'B')
				cnt++;
		}


		cout << "Case #" << i << ": ";


		if((len-1)%2 == 0){
			val = (len-1)/2;
		}
		else
			val = (len)/2;

		if(cnt!= 0 && cnt!= len-1 && (cnt >= val || cnt >1) ){
			cout << "Y\n";	
		}
		else{
			cout << "N\n";
		}


	}


	return 0;
}	