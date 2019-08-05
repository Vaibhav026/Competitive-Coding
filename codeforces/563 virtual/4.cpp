#include<bits/stdc++.h>
using namespace std;


int main(){

	#ifndef ONLINE_JUDGE    
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif


	int n;
	cin >> n;

	long int x;

	cin >> x;

	int bit[18];

	for(int i=0;i<18;i++)
		bit[i] = 0;	

	int i=0;
	while(x){

		bit[i] = x%2;
		x = x/2;
		i++;
	}

	bool ans = false;

	for(int i=1;i<17;i++){

		if(bit[i+1] == 1 && bit[i] == 0 && bit[i-1] == 1){
			ans = true;
			break;
		}

		if(bit[i+1] == 0 &&  bit[i] == 1 && bit[i-1] == 0){
			ans = true;
			break;
		}		
	}





	return 0;
}