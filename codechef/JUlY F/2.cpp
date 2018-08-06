#include<bits/stdc++.h>
using namespace std;

std::vector <int> prime;


long int MAXN = 1000001;

long int a[1000000];

long int cnt[1000001];

int binarySearch(long int val,int l,int r){

	int mid;

	while(l<=r){

		mid = (l+r)/2 ;

		if(a[mid] == val)
			return mid;

		if(a[mid] < val)
			l = mid + 1;
		else
			r = mid-1;
	}

	return -1;
}

int spf[1000001];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
void getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        prime.push_back(spf[x]);
        x = x / spf[x];
    }

    
}

int main()
{
	int t;

	long int n;

	

	long int sum[1000000];

	cin >> t;

	//int primes;

	sieve();

	

	long int ans;

	sieve();
	while(t--){

		ans = 0;
		cin >> n;


		



		for(int i=0;i<n;i++)
			cin >> a[i];

		

		sort(a,a+n);

		for(int i=0;i<=a[n-1];i++)
			sum[i] = 0;

		for(int i=0;i<=a[n-1];i++)
			cnt[i] = 0;

		for(int i=0;i<n;i++){
			cnt[a[i]]++;
		}


		int size;

		for(int i=2;i<=a[n-1];i++){


			if(cnt[i] > 0){

			ans += cnt[i]*(cnt[i]-1);	
			getFactorization(i);

			int siz = prime.size();

			int prev = 0; 
			
			for(int j=0;j<siz;j++){

				if(prime[j] != prev){
					sum[i] += prime[j];
					prev = prime[j];
				}
			}

			prime.clear();

			}
		}

		
		 // cout << sum[2] << endl << sum[3] << endl << sum[30]<<endl;
		
		for(int i=1;i<=a[n-1];i++){

			if(cnt[i] > 0){


				int max = a[n-1]/i;

				for(int j=2;j<=max;j++){

					int num = i*j;

					if(num <= a[n-1] && cnt[num] > 0 && sum[num]%sum[i] == 0){

						//cout << i << " "<< num << endl;
						ans += cnt[i]*cnt[num];

					}


				}

			}

		}


		cout << ans << endl;
	}



	return 0;
}