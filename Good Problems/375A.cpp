#include <bits/stdc++.h>
using namespace std ;
int arr[20];
string dp[]={"1869","6198","1896","9186","9168","6189","8691"};
int main  ()
{
	memset(arr,0,sizeof arr);
	
	string s ;
	cin >> s ;
	for ( int i = 0 ;i < s.size();i++)
		arr[s[i]-'0']++;
	arr[1]--;
	arr[8]--;
	arr[6]--;
	arr[9]--;
	int rem=0;
	for ( int i = 1 ; i< 10 ; i++)
	{
		while ( arr[i]>0)
		{
			cout << i ;
			rem=rem*10+i;
			rem=rem%7;
			arr[i]--;
		}
	}
	cout << dp[rem];
	while ( arr[0]>0)
	{
		cout <<"0";
		arr[0]--;
	}
	cout << endl ;
	return 0 ;
}