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

        myx  = 1;
        myy = 1;
        
        for(int j=0;j<s.length();j++){
            if(s[j] == 'E'){
                east++;
            }
            else{
                south++;
            }

            if(east == n-1 || south == n-1){
                break;
            }
        }


        if(east == n-1){
            
            if(s[0] == 'E'){
                origy++;
                myx++;
                v.push_back('S');
            }
            else{
                origx++;
                myy++;
                v.push_back('E');
            }

            for(int j=1;j<s.length();j++){

                if(myx == n){
                    break;
                }

                if(origx == myx && origy == myy){
                    if(s[j] == 'E'){
                        origy++;
                        myx++;
                        v.push_back('S');
                    }
                    else{

                        origx++;
                        myy++;
                        v.push_back('E');
                    }
                }
                else{
                    myx++;
                    v.push_back('S');

                    if(s[j] == 'E'){
                        origy++;
                    }
                    else{
                        origx++;
                    }
                }

                

                        
            }

            cout << "Case #" << i << ": ";

            for(int j=0;j<v.size();j++){

                cout << v[j];
            }

            for(int j=1;j<=(2*(n-1)-v.size());j++){
                cout << "E";
            }

            cout << "\n";
        } 
        else{

            if(s[0] == 'E'){
                origy++;
                myx++;
                v.push_back('S');
            }
            else{
                origx++;
                myy++;
                v.push_back('E');
            }

            
            for(int j=1;j<s.length();j++){

                if(myy == n){
                    break;
                } 

                if(origx == myx && origy == myy){
                    if(s[j] == 'E'){
                        origy++;
                        myx++;
                        v.push_back('S');
                    }
                    else{

                        origx++;
                        myy++;
                        v.push_back('E');
                    }
                }
                else{
                    myy++;
                    v.push_back('E');

                    if(s[j] == 'E'){
                        origy++;
                    }
                    else{
                        origx++;
                    }
                }

                

                       
            }

            cout << "Case #" << i << ": ";

            for(int j=0;j<v.size();j++){

                cout << v[j];
            }

            for(int j=1;j<=(2*(n-1)-v.size());j++){
                cout << "S";
            }

            cout << "\n";


        }   


        v.clear();
    }
	return 0;
}