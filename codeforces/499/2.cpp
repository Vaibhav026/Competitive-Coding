#include <bits/stdc++.h>
using namespace std;


int main()
{
	
	int n,k;

	cin >> n >> k;

	string s;

	cin >> s;

	int count[27];

	for(int i=0;i<=26;i++)
		count[i] = 0;

	int z;

	for(int i=0;i<n;i++){

		z = s[i]-'a' + 1;
		count[z]++;
	}

	int wt = 0;
	int sum = 0;

	bool ans = false;
	for(int i=1;i<=26;i++){

		if(count[i]>0){

			wt += i;
			sum++;
			i++;

		}

		if(sum == k){
			ans = true;
			break;
		}
	}

	if(ans){
		cout << wt;
	}
	else
		cout << "-1";







	return 0;
}