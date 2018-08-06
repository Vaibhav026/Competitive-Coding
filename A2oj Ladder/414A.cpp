#include <bits/stdc++.h>
using namespace std;


long int MAXN = 10000001;


std::vector <long int> prime;
bool is_composite[10000001];


void sieve (long int n) {

	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int main()
{
	long int n,k;

	cin >> n >> k;

	if(n == 1){
		if(k == 0)
			cout << "1";
		else
			cout << "-1";
	}
	else{

		long int pairs = n/2 ;

		if(pairs > k){
			cout << "-1";
			return 0;
		}
		else{

			sieve(10000001);

			long int s = k - (pairs-1);

			cout << s << " " << s*2 << " "; 

			long int left = pairs-1;

			int j = 2;

			while(1){

				if(left == 0)
					break;

				if(prime[j]!=s && prime[j+1]!=s){
					cout << prime[j] << " " << prime[j+1] << " ";
					left--; 
				}
				j = j+2;
			}

			
			
			if(pairs*2 != n){
				cout << "100000000";
			}
		}


	}






	return 0;
}