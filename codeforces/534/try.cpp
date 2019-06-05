#include <bits/stdc++.h>
using namespace std;
int main() {

#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    freopen("input.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);
    #endif		
  static char s[100005];
  for (int i = 1; i <= 5e4; ++i) s[i] = s[100000-i+1] = 'a' + (i&1);
  int Mid = 5e4;
  s[Mid] = s[Mid+1];
  cout << s+1;
  return 0;
}