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

			for(int i=1;i<l;i++){
				if(s[i] != '0')
					check = false;
			}

			if(check){
				for(int i=0;i<(l-1);i++){
					cout << "9";
				}
				cout << endl;
			}
			else{
				
				int indx;

				if(s[0] == '1'){

					for(int i=1;i<l;i++){

						if(s[i] != '0'){
							indx = i;
							break;
						}

					}

					bool t= true;

					for(int i = indx+1;i<l;i++){
						if(s[i] != '9'){
							t = false;
							break;
						}
					}

					if(t == false){
						char ch = s[indx];

						int z = s[indx] - '0';

						char ch2 = '0' + (char) (z-1);

						s[indx] = ch2;

						for(int i = indx+1;i<l;i++)
							s[i] = '9';

					}
				}
				else{

					char ch = s[0];
					
					int z = ch - '0';

					bool check = true;

					for(int i=1;i<l;i++){
						if(s[i] != '9'){
							check = false;
							break;
						}
					}

					if(!check){
						s[0] = '0' + (char) (z-1);

						for(int j = 1;j<l;j++)
							s[j] = '9';
	
					}
					

				}
				cout << s << endl;	
			}
		
		}


	}

	


	return 0;	
}	