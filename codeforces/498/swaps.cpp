#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;

	string a,b;

	cin >> n;

	cin >> a;

	cin >> b;

	bool first,second;

	int l = 0,r = n-1;

	int sum = 0;

	while(l<=r){

		if(l == r){

			if(a[l] != b[l])
				sum += 1;
		}
		else{

			if(a[l] == b[l])
				first = true;
			else
				first = false;

			if(a[r] == b[r])
				second = true;
			else
				second = false;


			if(first && second){
				sum += 0;
			}
			else if((first && !second) || (!first && second)){
				sum += 1;
			}
			else{


				bool top,bottom;


				if(a[l] == a[r])
					top = true;
				else
					top = false;

				if(b[l] == b[r])
					bottom = true;
				else
					bottom = false;



				if(top && bottom){
					sum += 0; 
				}
				else if(!top && bottom){
					sum += 1;
				}
				else if(top && !bottom)
					sum += 2;
				else{

					bool c1,c2;

					if(a[l] == b[r])
						c1 =true;
					else
						c1 = false;

					if(a[r] == b[l])
						c2 = true;
					else
						c2 = false;

					if(c1 && c2){
						sum += 0;
					}
					else if((c1 && !c2) || (c2 && !c1))
						sum += 1;
					else
						sum += 2;


				}
			}

		}



		l++;
		r--;


	}





	cout << sum;






	return 0;
}
