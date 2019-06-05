#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c){

	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true; 

	return false;
}

// 4 aaaa
// 1 aabb
//2 abab
//3 abba
int rhyme(string s1,string s2,string s3,string s4){

	if(s1 == s2 && s2 == s3 && s3 == s4){
		//cout << s1  << " " << s2 << endl;	
		return 4;
	}

	if(s1 == s2 && s3 == s4){
		return 1; 
	}

	if(s1 == s3 && s2 == s4){
		return 2;
	}

	if(s1 == s4 && s2 == s3){
		return 3;
	}

	return -1;
}
int main(){

	int n,k;

	cin >> n >> k;

	string str[4*n+1];

	for(int i=1;i<=(4*n);i++){
		cin >> str[i];
	}

	string sub[4*n + 1];
	
	for(int i=1;i<=(4*n);i++){

		int l = str[i].length();

		int num = 0;

		string tmp = "";

		for(int j = l-1;j>=0;j--){

			if(is_vowel(str[i][j])){
				num++;
			}
			tmp += str[i][j];

			if(num == k){
				break;
			}
		}

		if(num != k){
			cout << "NO";
			return 0;
		}
		else{
			sub[i] = tmp;
			//cout << sub[i] << endl;
		}
	}

	int scheme[n+1];

	int grp;

	set<int> un;

	for(int i=1; i<= (4*n);i += 4){

		grp = (i+3)/4 ;

		scheme[grp] = rhyme(sub[i],sub[i+1],sub[i+2],sub[i+3]);

		un.insert(scheme[grp]);
	}
// 4 aaaa
// 1 aabb
//2 abab
//3 abba

	if(un.size() == 1){
		auto it= un.begin();

        if(*it == 1){
        	cout << "aabb";
        } 
        else if(*it == 2){
        	cout << "abab";
        }
        else if(*it == 3){
			cout << "abba";
        }
        else if(*it == 4){
        	cout << "aaaa";
        }
        else
        	cout << "NO";
	}
	else if(un.size() == 2){
		auto it= un.begin();

		int gr1 = *it;

		it++;

		int gr2 = *it;

		if(gr1 == 4){
			if(gr2 == 1){
        		cout << "aabb";
        	} 
        	else if(gr2 == 2){
        		cout << "abab";
        	}
        	else if(gr2 == 3){
				cout << "abba";
        	}
        	else if(gr2 == 4){
        		cout << "aaaa";
        	}
        	else{
        		cout << "NO";
        	} 
		}
		else if(gr2 == 4){
			if(gr1 == 1){
        		cout << "aabb";
        	} 
        	else if(gr1 == 2){
        		cout << "abab";
        	}
        	else if(gr1 == 3){
				cout << "abba";
        	}
        	else if(gr1 == 4){
        		cout << "aaaa";
        	}
        	else{
        		cout << "NO";
        	}
		}
		else{
			cout << "NO";
		}		
	}
	else{
		cout << "NO";
	}

}	