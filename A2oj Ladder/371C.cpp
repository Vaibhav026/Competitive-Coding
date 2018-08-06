#include<bits/stdc++.h>
using namespace std;



int main()
{
	string str;
	cin >> str;

	int num_bread = 0;
	int num_sausage = 0;
	int num_cheese = 0;

	int price_bread;
	int price_sausage;
	int price_cheese;

	long long int r;

	cin >> num_bread >> num_sausage >> num_cheese;

	cin >> price_bread >> price_sausage >> price_cheese;

	cin >> r;


	int l = str.length();

	int req_bread =0;
	int req_sausage = 0;
	int req_cheese  = 0;

	for(int i=0;i<l;i++){

		if(str[i] == 'B')
			req_bread++;
		else if(str[i] == 'S')
			req_sausage++;
		else
			req_cheese++;

	}


	int b = INT_MAX;

	if(req_bread)
		b = num_bread/req_bread ;


	int s = INT_MAX;


	if(req_sausage)
		s = num_sausage/req_sausage ;
	
	int c = INT_MAX;

	if(req_cheese)
		c = num_cheese/req_cheese ;



	long long int intial = min(b,min(s,c));


	int bread_left = num_bread - intial*req_bread;

	int sausage_left = num_sausage - intial*req_sausage;

	int cheese_left = num_cheese - intial*req_cheese;

	bool bread,sausage,cheese;

	

		
		
		while(r>0 ){

		bread = true;
		sausage = true;
		cheese = true;
			
		if((req_bread ==0 || bread_left == 0) && (req_sausage==0 || sausage_left == 0) && (req_cheese ==0 || cheese_left == 0) )
			break;

		if(req_bread != 0){		
		if(bread_left < req_bread && (req_bread - bread_left)*(price_bread) <= r){

			r -= (req_bread - bread_left)*(price_bread);
		}
		else if(bread_left < req_bread)
			bread = false;
		}

		if(req_sausage != 0){
		if(sausage_left<req_sausage && (req_sausage-sausage_left)*(price_sausage)<=r)
			r -= (req_sausage-sausage_left)*(price_sausage);	
		else if(sausage_left < req_sausage)
			sausage = false;
		}

		if(req_cheese != 0){
		if(cheese_left<req_cheese && (req_cheese-cheese_left)*(price_cheese)<=r)
			r -= (req_cheese-cheese_left)*(price_cheese);	
		else if(cheese_left < req_cheese)
			cheese = false;
		}

		if(bread && cheese && sausage){
			intial++;

			if(bread_left < req_bread)
				bread_left = 0;
			else
				bread_left -= req_bread;


			if(sausage_left<req_sausage)
				sausage_left = 0;
			else
				sausage_left -= req_sausage;

			if(cheese_left<req_cheese)
				cheese_left = 0;
			else
				cheese_left -= req_cheese;
		}
		else{
			//cout << "a";	
			cout << intial ;
			return 0;
		}
		
		}
		long long int money_for_one = req_bread*price_bread + req_cheese*price_cheese + req_sausage*price_sausage;

		//cout << r << endl;
		if(r > 0){

			intial += r/money_for_one ;
		}

	


	cout << intial;
	return 0;
}