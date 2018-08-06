#include <bits/stdc++.h>
using namespace std;

string s;

int solve(int l,int r,bool first){


	if(first){
		if(s[l] == '1')
			return solve(l+1,r,false);
		else
			return pow(2,r-l);
	}


	if(l == r){
		if(s[l] == '0')
			return 1;
		else 
			return 2;
	}
		


	if(s[l] == '0'){
		return solve(l+1,r,false);
	}
	else if(s[l] == '1'){

		return (solve(l+1,r,false) + pow(2,r-l));
	}
	else{
		return pow(2,r-l+1);
	}
}

int main()
{
	

	cin >> s;

	int l = s.length();

	long int ans;

	ans = pow(2,l-1) - 1;

	if(l == 1){

		ans = 1;

	}
	else{

		int z;

		long int temp = 1;

		ans += solve(0,l-1,true);

	}	




	cout << ans;






	return 0;
}
