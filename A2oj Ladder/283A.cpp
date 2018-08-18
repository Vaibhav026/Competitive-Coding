#include<bits/stdc++.h>
using namespace std;


int main()
{
	long int n;
	cin >> n;

	int t;

	long int a,x,k;

	long long int sum= 0;


	std::vector<int> v;

	v.push_back(0);

	std::vector<int> inc;
	inc.push_back(0);

	for(long int i=1;i<=n;i++){

		cin >> t ;

		if(t == 1){

			cin >> a >> x;

			sum += a*x;

			inc[a-1] += x;
			
		}
		else if(t == 2){
			
			cin >> k;

			v.push_back(k);
			inc.push_back(0);

			sum += k;

		}
		else{
			
			int siz = v.size();

			sum -= (v.back()+inc[siz-1]);	
			
			inc[siz-2] += inc[siz-1];


			v.pop_back();
			inc.pop_back();

		}


		double avg ;

		avg =(double) sum/v.size() ;



		 std::cout << std::fixed;
  		 std::cout << std::setprecision(9) << avg << '\n';
		

	}







}