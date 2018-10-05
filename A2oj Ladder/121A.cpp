#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll next(ll l){

	std::vector<int> v;

	ll z = l;

	int n;

	int cnt = 0;

	while(z){
		n = z%10;
		v.push_back(n);	
		z = z/10;
	}

	int siz = v.size();

	ll ans = 0;
	if(v[siz-1] > 7){

		ll m = pow(10,siz);

		for(int i=0;i<=siz;i++){
			ans += (m)*(4);
			m = m/10;
		}

		return ans;
	}

	if(v[siz-1] < 4){

		ll m = pow(10,siz-1);

		for(int i=0;i<siz;i++){
			ans += (m)*(4);
			m = m/10;
		}

		return ans;
	}

	if(v[siz-1] == 4){

	}

	if(v[siz-1] < 7){

		ll m = pow(10,siz-1);

		ans += m*(7);
		m = m/10;
		for(int i=1;i<siz;i++){
			ans += (m)*(4);
			m = m/10;
		}

		return ans;
	}

	// if(v[siz-1] == 7){

	// }



}


ll solve(ll l,ll r){

	ll a = next(l);

	if(l == r){
		return a;
	}

	if(l > r)
		return 0;

	if(a <= r){
		return a*(a-l) + solve(a,r);
	}
	else{
		return a*(r-l+1);
	}

}


int main()
{





	cout << next(87);







	return 0;
}