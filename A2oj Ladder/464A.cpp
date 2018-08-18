#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,p;

	string s;

	cin >> n >> p;

	cin >> s;

	int z[n];

	int x;

	for(int i=0;i<n;i++){

		x = s[i] - 'a' + 1;
		z[i] = x;
	}

	

	if(p == 1){
		cout << "NO";
	}
	else if(p == 2){

		if(n == 1){

			if( s[0] == 'a')
				cout << "b";
			else
				cout << "NO";
		}
		else if (n == 2){
			if( s == "ab")
				cout << "ba";
			else
				cout << "NO";
		}
		else
			cout << "NO";
	}
	else{

		

		int index = -1;
		for(int i=n-1;i>=2;i--){

			for(int j=1;j<=(p-z[i]);j++){

				if( (z[i]+j != z[i-1] ) && (z[i]+j != z[i-2] )){
					index = i;
					z[i] = z[i]+j;
					break;
				}
			}

			if(index != -1)
				break;
		}

		if(index == -1){
				
			for(int j=1;j<=(p-z[1]);j++){

				if( (z[1]+j != z[0] ) ){
					index = 1;
					z[1] = z[1]+j;
					break;
				}
			}
		}

		if(index == -1){

			if(z[0] == p){
				cout << "NO";
				return 0;
			}
			else{

				index = 0;
				z[0]= z[0]+1;
			}

		}


		for(int i=index+1;i<n;i++){


			if((i-2)>=0){

				for(int j=1;j<=p;j++){
					
					if( (j != z[i-1]) && (j != z[i-2]) ) { 
						
						z[i] = j;
						break;	
					}
				}

			}
			else{

				for(int j=1;j<=p;j++){
					
					if( (j != z[i-1]) )  { 
						
						z[i] = j;
						break;	
					}
				}

			}
		

		}


		for(int i=0;i<n;i++){

			char c = (char) (z[i] + 'a' - 1);
			cout << c;  
		}




	}









	return 0;
}