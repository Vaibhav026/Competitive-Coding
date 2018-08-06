#include <bits/stdc++.h>
using namespace std;



int main()
{

	int n;
	cin >> n;

	string s,t;

	cin >> s >> t;

	int scnt[27],tcnt[27];

	for(int i=0;i<27;i++){
		scnt[i] = 0;
		tcnt[i] = 0;
	}	

	int z1,z2;

	for(int i=0;i<n;i++){

		z1 = s[i] - 'a' + 1;

		z2 = t[i] - 'a' + 1;

		scnt[z1]++;

		tcnt[z2]++;
	}

	bool res = true;

	for(int j=1;j<=26;j++){

		if(scnt[j] != tcnt[j]){
			res = false;
			break;
		}

	}

	std::vector<int> v;
	if(res == false){
		cout << "-1";
	}
	else{

		for(int i=0;i<n;i++){

			if(s[i] != t[i]){

				int index;

				for(int j = i+1;j<n;j++){
					if(t[i] == s[j]){
						index = j;
						break;
					}

				}


				for(int j = index -1;j>=i;j--){

					swap(s[j],s[j+1]);
					v.push_back(j+1);
					//cout << (j+1) << endl;
				}


			}



		}


		int siz = v.size();

		cout << siz << endl;

		for(int j=0;j<siz;j++){

			cout << v[j] << " ";
		}


	}




	return 0;
}