#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,m;

	cin >> n >> m;

	int l[n],r[n];

	for(int i=0;i<n;i++){
		cin >> l[i] >> r[i];
	}

	std::vector<int> v;

	for(int i=1;i<=m;i++){

		bool is = true;

		for(int j=0;j<n;j++){

			if(l[j]<=i && i<=r[j]){
				is = false;
				break;
			}
		}

		if(is == true){
			v.push_back(i);
		}
	}

	int siz = v.size();

	cout << siz << "\n";

	for(int j=0;j<siz;j++){
		cout << v[j] << " ";
	}



	return 0;
}