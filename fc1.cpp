#include<bits/stdc++.h>
using namespace std;

int main()
{

	int a,b,c,n;

	cin>>a>>b>>c>>n;

	int x = a+b-c;

	int ans = n - x;

	if(ans>=1 && a>=c && b>=c && a<=n && b<=n && c<=n)
		cout<<ans;
	else
		cout<<"-1";












	return 0;
}
