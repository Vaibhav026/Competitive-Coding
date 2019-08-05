#include <bits/stdc++.h>
using namespace std;

int main(){


	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;

	cin >> n;

	string s[n];

	for(int i=0;i<n;i++){
		cin >> s[i];
	}

	string orig;

	cin >> orig;

	char letter;

	cin >> letter;


	string final = orig;


	int l1 = orig.length();

	int l2;

	for(int i=0;i<n;i++){

		l2 = s[i].length();

		if(l2 > l1)
			continue;

		bool ans;
		for(int j =0;j< l1;j++){

			ans = true;
			
			for(int k=0;k<l2;k++){

				if((j+k) >= l1){
					ans = false;
					break;
				}

				int z1 = orig[j+k] - 'A' + 1;
				int z2 = s[i][k]-'A' +1;

				if(  !( z1==z2 || (z1+32) == z2  || (z1-32) == z2) ){
					ans = false;
					break;
				}		
			}

			if(ans){

				for(int k=j;k<(j+l2);k++){

					int z1 = orig[k] - 'A' + 1;

					int z2 = letter - 'A' + 1;

					// orig letter is not capital
					if(z1 > 26){

						// kth letter is = 'letter'
						if(z1 == z2 || z1 == z2+32){

							if(letter == 'a' || letter == 'A'){
								final[k] = 'b';
							}		
							else{
								final[k] = 'a';
							}
						}
						else{

							// 'letter' is small
							if(z2 > 26){
								final[k] = letter;
							}	
							else{

								
								final[k] = (char) z2 + 'a'-1;		
							}

						}
					}
					else{

						// orig letter is capital

						if(z1 == z2 || z1 == z2-32){

							if(letter == 'a' || letter == 'A'){
								final[k] = 'B';
							}
							else{
								final[k] = 'A';
							}

						}
						else{

							if(z2 <=26){
								final[k] = letter;
							}
							else{

								z2 = z2-32;
								// cout << z2;
								final[k] = (char) z2 + 'A'-1;
							}
						}
					}

				}

				j = j+l2-1;
			}
		}

	}


	cout << final;



	return 0;
}