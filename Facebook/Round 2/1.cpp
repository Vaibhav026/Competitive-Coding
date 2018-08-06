#include <bits/stdc++.h>
using namespace std;


int main()
{
	
	#ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
 
	#endif


	int t;
	cin >> t;

	long long int n,k;

	
	std::vector<int> v;

	for(int i=1;i<=t;i++){

		cin >> n >> k;

		int vertex = 1;	

		int edges = 0;

		long int sum = 0;
		int val = k-1;
		while(n >2 && k>=3 && vertex<=(n-1) && val > 0){

			v.push_back(val);
			sum += val;
			val--;
			edges++;
			vertex++;
		}

		long int diff = (sum - k);

		if(diff < 0)
			diff = 0;

		cout << "Case #"<<i<<": ";
		cout << diff << endl;

		cout << edges+1 << endl;

		cout << "1 "<< n <<" " << k<<endl;

		int siz = v.size();

		for(int j=0;j<siz;j++){

			if(j!= siz -1){
				cout <<(j+1) << " " << (j+2) << " " <<v[j] << endl;

			}
			else
				cout << (j+1) << " " << n << " " << v[j] << endl;

		}

		v.clear();
	}






	
	return 0;
}