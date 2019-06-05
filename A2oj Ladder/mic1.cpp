#include<bits/stdc++.h>
using namespace std;
#include<string.h>


char* dec(char* input1){
	int l = strlen(input1);


	int z,x,tmp;

	char* ans;

	for(int i =0;i<l;i++){

		if(input1[i] == 'a'){
			ans[i] = 'x';			
		}
		else if(input1[i] == 'b'){
			ans[i] = 'y';
		}
		else if(input1[i] == 'c'){
			ans[i] = 'z';
		}
		else{
			z = input1[i] - 'a' + 1;

			x = z -3;

			//x = (x + 26)%26 ;

			tmp = x + 'a' - 1;

			ans[i] = (char) tmp;
		}
		

		cout << ans[i];
	}

	return ans;

}	

int main()
{	 
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     freopen("error.txt", "w", stderr);
     #endif



	// char ch[] = "abcdef";

	// char* o = dec(ch);

	// int l = strlen(o);

	// cout << endl;
	// for(int i=0;i<l;i++){
	// 	cout << o[i];
	// }

     https://tests.mettl.com/test-window-api?ecc=WZ5Q0Kgwl0B6WLbtN%2BKETAqSz9XGWjRoj9GH9O3a1ls%3D&showReg=true#/testApi
	return 0;
}