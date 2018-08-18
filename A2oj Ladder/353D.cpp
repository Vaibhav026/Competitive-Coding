#include <bits/stdc++.h>
using namespace std;


int main()
{
	string s;
	cin >> s;

	std::vector<long int> indices;
	std::vector<long int> t;

	long int l = s.length();

 

	for(long int i=0;i<l;i++){

		if(s[i] == 'F')
			indices.push_back(i);

	}

	long int siz = indices.size();

	long int temp;

	for(long int i=0;i<siz;i++){

		if(indices[i] == i)
			t.push_back(0);
		else if(i == 0  || (indices[i]-i) > t[i-1] )
			t.push_back((indices[i]-i));
		else{
			temp = t[i-1];
			t.push_back(temp+1);
		}

	} 	

	if(siz == 0)
		cout << "0";
	else
	cout << t[siz-1];



	return 0;
}