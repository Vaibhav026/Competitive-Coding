#include <bits/stdc++.h>
using namespace std;

int main(){

	string s;

	std::vector< pair<long double,long int> > v;

	cin >> s;

	long int l = s.length();

	long double left  = 0;
	long double right =  1;

	for(long int i=0;i<l;i++){

		long double mid = (long double) (left+right)/2 ;

		v.push_back(make_pair(mid,i+1));

		if(s[i] == 'l')
			right = mid;
		else
			left = mid;


	}
	

	sort(v.begin(),v.end());

	for(int i=0;i<l;i++)
		cout << v[i].first << endl;















	return 0;
}