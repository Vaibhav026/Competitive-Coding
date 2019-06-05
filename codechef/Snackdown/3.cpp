#include <bits/stdc++.h>
using namespace std;

bool is_composite[201];
std::vector <int> prime;

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 2; i * j < n; ++j)
			is_composite[i * j] = true;
	}
}

bool is(int x){

	int sq = sqrt(x);

	for(int i=2;i<=sq;i++){
		
		if(x%i == 0 && !is_composite[i]){

			if( (x/i)!= i && !is_composite[x/i])
				return true;		
		}
	}

	return false;
}



int main()
{	
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

	int t,n;

	cin >> t ;

	sieve(201);

	while(t--){

		cin >> n;

		int left = 1;
		int right = n-1;
		bool ans = false;

		while(left <= right){

			if(is(left) && is(right)){
				
				//cout << left << " " << right << endl;	
				ans = true;
				break;
			}

			left++;
			right--; 
		}

		if(ans)
			cout << "YES\n";
		else
			cout << "NO\n";

	}





	return 0;
}