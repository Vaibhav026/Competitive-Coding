#include<bits/stdc++.h>
using namespace std;




int main() {

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int x,y,z;

	cin >> x >> y >> z;


	if(x > (y+z)){
		cout << "+";
	}
	else if(y > (x+z)){
		cout << "-";
	}
	else if(z == 0 && x == y){
		cout << "0";
	}
	else{
		cout << "?";
	}

	return 0;
}