#include<bits/stdc++.h>
using namespace std;

int main()
{	long int n,h,a,b,k;

	cin >> n >> h >> a >> b >> k;

	long int fa,ta,fb,tb;

	long int t;

	while(k--){

		cin >> ta >> fa >> tb >> fb;

		if(ta == tb){
			cout << abs(fa-fb) << endl;
		}
		else{

		t = 0;
		int type = 0;

		if(fa > b){
			t += fa-b;
			type = 1;
		}
		else if(fa < a){
			t += a-fa;
			type = 2;
		}

		

		t += abs(ta-tb);

		

		if(type == 0){
			t += abs(fa - fb);
		}
		else if(type == 1){
			t += abs(b-fb);
		}
		else{
			t += abs(fb-a);
		}

		
		cout << t << endl;

		}
	}
	
	return 0;
}