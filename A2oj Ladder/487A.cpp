#include <bits/stdc++.h>
using namespace std;

long int hp_y,atk_y,def_y;

long int hp_m,atk_m,def_m;

long int h,a,d;

bool solve(long int hh,long int aa,long int dd){

	if(aa == def_m)
		return false;

	if(atk_m <= dd)
		return true;

	double x = (double) (hp_m)/(aa-def_m) ;
	//cout << x;

	int f = ceil(x);

	double y = (double) (hh)/(atk_m-dd);

	int s = ceil(y);

	if(f < s)
		return true;

	return false;	 

}

int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	cin >> hp_y >> atk_y >> def_y;

	cin >> hp_m >> atk_m >> def_m;

	cin >> h >> a >> d;


	long int pre = 0;

	if(atk_y < def_m){

		pre += a*(def_m-atk_y);

		atk_y = def_m;
	}

	long int ans = 1000000000;

	long int tmp;

	int max_j = def_m + 100;

	
	long int mid;

	for(long int j = atk_y;j<=max_j;j++){

		for(long int k = def_y;k<=max(def_y,atk_m);k++){

			long int l = hp_y;
			long int r = 10001;
			while(l <= r){ 
				
				mid = (l+r)/2 ;
				if(solve(mid,j,k)){
					
					tmp = (mid-hp_y)*h + (j-atk_y)*a + (k-def_y)*d;
					
					if(tmp < ans)
					ans = tmp;

					r = mid-1;
				}
				else
					l = mid+1;
			}	
		}
	}
	




	cout << (ans + pre);


	return 0;
}