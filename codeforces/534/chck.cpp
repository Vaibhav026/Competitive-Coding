#include <bits/stdc++.h>

using namespace std;

vector<char>v;
long t = 0;

int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);
    #endif
    
    char c;
    while(cin >> c){
        if(!v.empty() && c == v.back()){
            t++;
            v.erase(v.end()-1);
        }else v.push_back(c);
    }
    if(t % 2 == 1)cout << "Yes";
    else cout << "No";
    return 0;
}