#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

 #define pb              push_back
std::vector<ll> primes;
std::vector<int> cnt;

void factorize(long long n)
{
    int count = 0;
 
    // count the number of times 2 divides 
    while (!(n % 2)) {
        n >>= 1; // equivalent to n=n/2;
        count++;
    }
 
    // if 2 divides it
    if (count){
    	primes.pb(2);
    	cnt.pb(count);
        //cout << 2 << "  " << count << endl;
    }
 
    // check for all the possible numbers that can 
    // divide it
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count){
        	primes.pb(i);
        	cnt.pb(count);
        }

            //cout << i << "  " << count << endl;
    }
 
    // if n at the end is a prime number.
    if (n > 2){
        primes.pb(n);
        cnt.pb(1);	
        //cout << n << "  " << 1 << endl;
    }
}

int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n;

	cin >> n;
	if(n == 1){
		cout << "1\n";
		cout << "0";
		return 0;
	}
	factorize(n);

	int l = primes.size();

	if( l == 1){
		if(cnt[0] == 1){
			cout << "1\n";
			cout << "0";
		}
		else if(cnt[0] == 2){
			cout << "2";
		}
		else{
			cout << "1\n";
			
			ll tmp = primes[0]*primes[0];

			cout << tmp;
		}
	}
	else if(l == 2){

		if( (cnt[1]+cnt[0]) == 2){
			cout << "2";
		}
		else{
			cout << "1\n";
			ll tmp = primes[0]*primes[1];

			cout << tmp;
		}

	}
	else{

		cout << "1\n";
		
		ll tmp = primes[0]*primes[1];

		cout << tmp;

	}

	return 0;
}