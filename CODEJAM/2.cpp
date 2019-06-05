#include <bits/stdc++.h>
using namespace std;


int main(){

	#ifndef ONLINE_JUDGE
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;

    cin >> t;

    long int n;

    string s;

    long int east,south;

    vector<char> v;

    long int origx,origy;
    long int myx,myy;

    for(int i=1;i<=t;i++){

        east = 0;
        south = 0;

        cin >> n;

        cin >> s;

        origx = 1;
        origy = 1;

        if(s[0] == 'E'){
            v.push_back('S');
        

            myx = 2;
            myy = 1;
        }
        else{
            v.push_back('E');

            

            myx = 1;
            myy = 2;    

        }


        for(int i=0;i<s.length();i++){

            if(s[i] == 'E'){
                origy++;
            }
            else
                origx++;

            if(myx == origx && myy == origy){
                if(myx == n && myy == n){
                    break;
                }
                else{
                    if(s[i+1] == 'E')
                }    
            }
            else{
                if(s[i] == 'E'){
                    myy++;
                    v.push_back('E');
                }
                else{
                    myx++;
                    v.push_back('S');
                }

            }
        }
    }
	return 0;
}