#include <bits/stdc++.h>
using namespace std;


int main()
{

	int t;
	cin >> t;


	int n,k;

	string s;

	while(t--){

		cin >> n;

		cin >> s;

		for(int i=0;i<n;i = i+2){

			if(i != n-1){
				swap(s[i],s[i+1]);
			}
		}

		int z,x;

		for(int i=0;i<n;i++){

			z = s[i] - 'a' + 1;

			x = 27-z;

			s[i] = (char) (x+'a'-1);

			cout << s[i];
		}

		cout << endl;
	}





	return 0;
}