#include <bits/stdc++.h>
using namespace std;


int main()
{
	long int n;

	cin >> n;


	long int rhs = n;

	long int y = 0;

	long int x;

	long int tempx;
	bool ans = false;

	long int yans;
	while(rhs >=0){
 
		 

		if(rhs%4 == 0){
			
			x= rhs/4;
			ans = true;
			yans = y;
			//break;
		}

		y++;

		rhs = n - 7*y;
	}


	if(ans){
		for(long int i=1;i<=x;i++)
			cout <<"4";
		for(long int i=1;i<=yans;i++)
			cout << "7";

	}
	else
		cout << "-1\n";









	return 0;
}