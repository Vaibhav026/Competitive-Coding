#include<bits/stdc++.h>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int t;
	cin >> t;

	string s;

	int l;

	while(t--){

		cin >> s;

		l = s.length();

		if( l == 1){
			cout << s << endl;
		}
		else{

			bool check = true;

			if(s[0] != '1'){
				check = false;
			}

			for(int i=1;i<l-1;i++){
				if(s[i] != '0')
					check = false;
			}

			if(check && s[l-1] == '0'){
				for(int i=0;i<(l-1);i++){
					cout << "9";
				}
				cout << endl;
			}
			else if(s[l-1] == '9' || check){
				cout << s << endl;
			}
			else{
				
				int j = l-2;

				s[l-1] = '9';
				while(j>=0){
					if(s[j] != '0'){

						char ch = s[j];

						int z = (s[j] - '0');

						char ch2 = '0' + (z-1);

						s[j] = ch2;

						break;
					}
					else{
						s[j] = '9';
					}

					j--;
				}

				cout << s << endl;	
			}
		}


	}

	


	return 0;	
}	