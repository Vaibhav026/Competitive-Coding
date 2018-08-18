#include<bits/stdc++.h>
using namespace std;


long long int solve(long long int a,long long int b){

	if(a == 0 || b == 0)
		return 0;

	if(a>b)
		return (ceil(a/b) +solve(a%b,b));

	if(a < b)
		return (ceil(b/a) + solve(a,b%a));
}	
int main()
{

	long long int a,b;

	cin >> a >> b;
	

	cout << solve(a,b);














	return 0;
}