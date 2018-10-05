#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int n;

	cin >> n;

	double y = (double) n/2;

	int s = ceil(y);

	//cout << s<< endl;
	for(int i=1;i<=s;i++){
		if(i != n-i+1)
			cout << i << " " << (n-i+1) << " ";
		else
			cout << i  << " ";
	}
	return 0;
}