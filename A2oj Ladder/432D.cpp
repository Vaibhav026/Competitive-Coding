#include <bits/stdc++.h>
using namespace std;

void getZarr(string str, int Z[])
{
    int n = str.length();
    int L, R, k;
 
    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        // if i>R nothing matches so we will calculate.
        // Z[i] using naive way.
        if (i > R)
        {
            L = R = i;
 
            // R-L = 0 in starting, so it will start
            // checking from 0'th index. For example,
            // for "ababab" and i = 1, the value of R
            // remains 0 and Z[i] becomes 0. For string
            // "aaaaaa" and i = 1, Z[i] and R become 5
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i-L;
 
            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
 
            // For example str = "aaaaaa" and i = 2, R is 5,
            // L is 0
            else
            {
                // else start from R and check manually
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}


int main()
{
	string s;
	cin >> s;

	int z[100005];

	getZarr(s,z);


	int n = s.length();
	
	int ans[n+1];

	bool is[n+1];

	for(int i=0;i<=n;i++){
		ans[i] = 0;
		is[i] = false;
	}

	z[0] = n;

	for(int i=n-1;i>=0;i--){

		int l = z[i];
		
		if(i+l == n)
			is[l] = true;	
		
		ans[l]++;

	}

	int rollback = 0;

	int temp;

	int total = 0;
	for(int i=n;i>=1;i--){

		if(is[i])
			total++;

		temp = ans[i];

		ans[i] += rollback;

		rollback += temp;

	}

	cout << total << endl;
	for(int i=1;i<=n;i++){


		if(is[i]){
			cout << i << " " << ans[i] << endl;
		}
	}


	return 0;
}


