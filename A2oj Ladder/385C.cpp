#include<bits/stdc++.h>
using namespace std;


long int cnt[10000001];

long int F[10000001];

long long int sum[10000001];

bool is_composite[10000001];

void sieve (long int n) {
	
	std::fill (is_composite, is_composite + n, false);
	for (long int i = 2; i < n; ++i) {

		if (!is_composite[i]){
			
			F[i] += cnt[i];	
			for (long int j = 2; i * j < n; ++j){
				is_composite[i * j] = true;
				F[i] += cnt[i * j]; 	
			}
			
		}
	}
}
	
int main()
{
	long int n;

	cin >> n;

	long int x[n];


	for(long int i=0;i<=10000000;i++)
		cnt[i] = 0;

	for(long int i=0;i<=10000000;i++)
		F[i] = 0;

	for(long int i=0;i<n;i++){
		
		cin >> a[i];
		cnt[a[i]]++;

	}

	sieve(10000001);

	sum[0] = 0;

	for(long int i=1;i<=10000000;i++){
		sum[i] += sum[i-1] +F[i];
	}

	long int m;
	cin >> m;

	long int l,r;

	for(int i=1;i<=m;i++){

		cin >> l >> r;
		l = min(l,10000000);
		r = min(l,10000000);

		cout << sum[r] - sum[l-1];
	}
	return 0;
}