#include <bits/stdc++.h>
using namespace std;


int main(){

	#ifndef ONLINE_JUDGE
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;

    cin >> t;

    string s;

    char ch1[200];

    char ch2[200];

    int l;

    for(int j=1;j<=t;j++){

    	cin >> s;

    	l = s.length();

    	for(int i=0;i<l;i++){

    		if(s[i] == '4'){
    			ch1[i] = '2';
    			ch2[i] = '2';
    		}
    		else{
    			ch1[i] = s[i];
    			ch2[i] = '0';
    		}
    	}

    	
    	cout << "Case #" << j << ": ";

    	for(int i=0;i<l;i++){
    		cout << ch1[i];
    	}

    	cout << " ";

    	int it = 0;

    	while(ch2[it] == '0'){
    		it++;
    	}

    	for(int i=it;i<l;i++){
    		cout << ch2[i];
    	}

    	cout << "\n";
    }
    

	return 0;
}