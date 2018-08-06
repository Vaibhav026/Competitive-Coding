#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;

	cin >> n;

	int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	std::vector< pair<int,int> > v;
		 
	for(int i=0;i<n;i++){

		v.push_back(make_pair(a[i],i+1));
	}

	sort(v.begin(),v.end());

	long int left = 0;
	long int right = 0;


	std::vector<int> l;
	std::vector<int> r;

	int i = n-1;

	while(i>=0){

		if(i == 0){

			if(left >= right){

				right += v[0].first;
				r.push_back(v[0].second);
			}
			else{

				left += v[0].first;
				l.push_back(v[0].second);	
			}

			i--;

		}
		else if(left >= right){

			right += v[i].first;
			left += v[i-1].first;
			r.push_back(v[i].second);
			l.push_back(v[i-1].second);
			i = i-2; 
		}	
		else{

			right += v[i-1].first;
			left += v[i].first;
			r.push_back(v[i-1].second);
			l.push_back(v[i].second);
			i = i-2;

		}


	}


	int s1 = l.size();

	cout << s1 << endl;
	for(int i=0;i<s1;i++){

		cout << l[i] << " "; 
	}

	cout << endl;

	int s2 = r.size();

	cout << s2 << endl;

	for(int i=0;i<s2;i++){

		cout << r[i] << " "; 
	}










	return 0;
}