#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s,t;

	cin >> s ;
	cin >> t ;

	long int l1,l2; 

	l1 = s.length();
	l2 = t.length();

	long int l = min(l1,l2);

	long int i = l1-1;
	long int j = l2-1;

	while(true && i>=0 && j>=0){

		if(s[i] != t[j])
			break;

		i--;
		j--;

	}

	long int ans = (i+1) + (j+1);

	cout << ans;


	return 0;
}