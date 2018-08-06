#include <bits/stdc++.h>
using namespace std;

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(*array))

bool compare_ints(const int& a, const int& b ) {

    return abs(a) < abs(b) ;

}

std::vector< pair<long int,long int> > pos;

std::vector< pair<long int,long int> > neg;

std::vector< long int > pzero;

std::vector< long int > nzero;

int main()
{
	long int n;

	cin >> n;

	long int x[n],y[n];

	long int steps = 0;

	for(int i=0;i<n;i++){

		cin >> x[i] >> y[i];

		if(x[i] == 0){

			if(y[i] > 0){
				pzero.push_back(y[i]);

			}
			else
				nzero.push_back(-1*y[i]);
		}
		else if(x[i]>0){
			pos.push_back(make_pair(x[i],y[i]));
		}
		else{
			neg.push_back(make_pair(-1*x[i],y[i]));
		}

		if(x[i] == 0 || y[i] == 0)
			steps += 2;
		else
			steps += 4; 

	}
	steps += 2*n;

	cout << steps << endl;

	sort(pzero.begin(),pzero.end());
	
	int siz = pzero.size();

	for(int i=0;i<siz;i++){


		cout << "1 "<<pzero[i] << " U\n";

		cout << "2\n";
		cout << "1 "<<pzero[i] << " D\n";

		cout << "3\n";
	}

	siz = nzero.size();


	sort(nzero.begin(),nzero.end());

	for(int i=0;i<siz;i++){
		
		cout << "1 "<<nzero[i] << " D\n";
		
		cout << "2\n";
		cout << "1 "<<nzero[i] << " U\n";

		cout << "3\n";
	}


	sort( pos.begin() , pos.end() );


	
	siz = pos.size();

	long int a,b;

	for(int i=0;i<siz;i++){
		
		a = pos[i].first;
		b = pos[i].second;

		if(b == 0){
			cout << "1 "<< a<< " R\n";
			cout << "2\n";
			cout << "1 "<< a<< " L\n";
			cout << "3\n";
		}
		else if(b > 0){

			cout << "1 "<<b<<" U\n";
			cout << "1 "<<a<<" R\n";
			cout << "2\n";
			cout << "1 "<<a<<" L\n"; 
			cout << "1 "<<b<<" D\n";
			cout << "3\n";
		}
		else{

			cout << "1 "<<-1*b<<" D\n";
			cout << "1 "<<a<<" R\n";
			cout << "2\n";
			cout << "1 "<<a<<" L\n"; 
			cout << "1 "<<-1*b<<" U\n";
			cout << "3\n";

		}
		
	}



	siz = neg.size();
	
	sort( neg.begin() , neg.end() );

	for(int i=0;i<siz;i++){
		
		a = neg[i].first;
		b = neg[i].second;

		if(b == 0){
			cout << "1 "<< a<< " L\n";
			cout << "2\n";
			cout << "1 "<< a<< " R\n";
			cout << "3\n";
		}
		else if(b > 0){

			cout << "1 "<<b<<" U\n";
			cout << "1 "<<a<<" L\n";
			cout << "2\n";
			cout << "1 "<<a<<" R\n"; 
			cout << "1 "<<b<<" D\n";
			cout << "3\n";
		}
		else{

			cout << "1 "<<-1*b<<" D\n";
			cout << "1 "<<a<<" L\n";
			cout << "2\n";
			cout << "1 "<<a<<" R\n"; 
			cout << "1 "<<-1*b<<" U\n";
			cout << "3\n";

		}
		
	}	


	






	return 0;
}