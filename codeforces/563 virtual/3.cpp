#include<bits/stdc++.h>
using namespace std;

bool prime[100001];

int ans[100001];

void p(int n){

	for(int i=0;i<=n;i++)
		prime[i] = true;

	prime[2] = true;

	int curr = 1;
	for(int i=2;i<=n;i++){

		if(!prime[i])
			continue;

		ans[i] = curr;

		for(int j= (2*i) ;j<=n; j += i){
			prime[j] = false;
			ans[j] = curr;
		}
		curr++;

	}

	for(int i=2;i<=n;i++)
		cout << ans[i] << " ";

	cout << endl;

}



int main() {

	#ifndef ONLINE_JUDGE    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n; 

	p(n);

	return 0;	
}