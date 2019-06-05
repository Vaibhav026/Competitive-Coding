#include<bits/stdc++.h>
using namespace std;


std::vector <int> prime;
bool is_composite[1002];

int mult[1002];

int prime_factor[1002];

int cnt[27];

bool done[1002];

void sieve (int n) {
	std::fill (is_composite, is_composite + n+1, false);
	for (int i = 2; i <=n; ++i) {
		if (!is_composite[i]){

			prime.push_back (i);
			for (int j = 2; i * j <= n; ++j){
				is_composite[i * j] = true;
				prime_factor[i*j] = i;
				mult[i]++;
			}

		}
	}
}


int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    int val[1002];

    string s;

    cin >> s;

    for(int i=0;i<=26;i++)
    	cnt[i] = 0;


    int l = s.length();
    //cout << l << endl;

    if(l == 1){
    	cout << "YES\n";
    	cout << s;
    	return 0;
    }

    for(int i=1;i<=1001;i++){
    	mult[i] = 1;
    	done[i] = false;
    }

    int z;

    for(int i=0;i<l;i++){
    	z = s[i] - 'a' + 1;
    	cnt[z]++;
    }

    sieve(l);
    //cout << prime[prime.size()-1] << endl;
    // for(int i=1;i<=10;i++)
    // 	cout << mult[i] << " ";

//    cout << endl;
    int min = 1002;
    int min_index = 0;

	for(int i=1;i<=26;i++){

		if(cnt[i]!= 0 && cnt[i] < min ){
	    	min = cnt[i];
	    	min_index = i;
	    }
	}

	if(min == 1002){
		//cout << "1" << endl;
		cout << "NO\n";
		return 0;
	}
	val[1] = min_index;
	cnt[min_index]--; 



    int max = 0;
    int max_index = -1;

    for(int i=1;i<=26;i++){

    	if(cnt[i] > max){
    		max = cnt[i];
    		max_index = i;
    	}
    }

    if(max_index == -1){
    	// cout << "1" << endl;
    	cout << "NO\n";
    	return 0;
    }

    int tmp = 0;

	for(int j=2;j<=l;j+= 2){
		if(!done[j]){
			tmp++;
			done[j] = true;
		}
	}

    if(cnt[max_index] >= tmp){
    	cnt[max_index] -= tmp;
    	val[2] = max_index; 
    }
    else{
    	//cout << "1" << endl;
    	cout << "NO";
    	return 0;
    }

    for(int i=3;i<=l;i++){

    	if(!is_composite[i]){

    		if((2*i) <= l){


    			int tmp = 0;

    			for(int j=i;j<=l;j+= i){
    				if(!done[j]){
    					tmp++;
    					done[j] = true;
    				}
    			}

    			if(cnt[val[2]] >= tmp){
    				
    				cnt[val[2]] -= (tmp);
    				
    				val[i] = val[2];
    			}
    			else{
    				cout << "NO\n";
    				return 0;
    			}

    		}
    		else{

    			int max = 0;
		    	int max_index = -1;

			    for(int j=1;j<=26;j++){

			    	if(cnt[j] > max){
			    		max = cnt[j];
			    		max_index = j;
			    	}
			    }

			    if(max_index == -1){
			    	// cout << i << endl;
			    	cout << "NO\n";
			    	return 0;
			    }

			    int tmp = 0;

    			for(int j=i;j<=l;j+= i){
    				if(!done[j]){
    					tmp++;
    					done[j] = true;
    				}
    			}

			    if(cnt[max_index] >= tmp){
			    	cnt[max_index] -= tmp;
			    	//cout << mult[i] << endl;
			    	val[i] = max_index; 
			    }
			    else{
			    	//cout << max_index << endl;
			    	cout << "NO";
			    	return 0;
			    }
			}
    	}
   //  	else{

   //  		int min = 1002;
		 //    int min_index = 0;

			// for(int j=1;j<=26;j++){

			// 	if(cnt[j]!= 0 && cnt[j] < min ){
			//     	min = cnt[j];
			//     	min_index = j;
			//     }
			// }

			// if(min == 1002){
			// 	cout << "NO\n";
			// 	return 0;
			// }
			// val[i] = min_index;
			// cnt[min_index]--; 
   //  	}
    }

    char c;

    cout << "YES\n";

    for(int i=1;i<=l;i++){

    	if(i == 1 || !is_composite[i])
    		z = val[i] + 'a' - 1;
    	else
    		z= val[prime_factor[i]] + 'a' - 1;

    	c = (char) z;
    	cout << c;
    }

	return 0;
}