#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:200000000")
 
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <iomanip>
#include <queue>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define mset(mas,val) memset(mas,val,sizeof(mas))
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
       
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
long double eps = 1e-6;
const long double pi = 3.14159265358979323846;
 
const int N = 1e6 + 100;
long long fact[N], modulo = INF + 7;
int n, a, b;
bool read()
{
        if (!(cin >> a >> b >> n))
                return false;
        assert(a >= 1 && a <= 9);
        assert(b >= a + 1 && b <= 9);
        assert(n >= 1 && n <= (int)1e6);
        return true;
}
long long binpow(long long val, long long deg, long long mod) {
        if (!deg) return 1 % mod;
        if (deg & 1) return binpow(val, deg - 1, mod) * val % mod;
        long long res = binpow(val ,deg >> 1, mod);
        return (res*res) % mod;
}
bool check(long long val, int a, int b) {
        while (val > 0) {
                if (val % 10 == a || val % 10 == b) {
                        val /= 10;
                } else return false;
        }
        return true;
}
void initfact() {
        fact[0] = 1;
        for(int i = 1; i < N; i++) {
                fact[i] = (fact[i-1] * i);
                fact[i] %= modulo;
        }
}
long long getC(int n, int i) {
        long long res = fact[n];
        long long div = fact[n-i] * fact[i];
        div %= modulo;  div = binpow(div, modulo - 2, modulo);
        return (res * div) % modulo;
}
void solve()
{
        long long ans = 0;
        for(int i = 0; i <= n; i++) {
                long long expsum = a * i + b*(n-i);
                if (check(expsum, a, b)) {
                        ans += getC(n, i);
                        ans %= modulo;
                }
        }
        cout << ans << endl;
}
 
int main(){
#ifdef gridnevvvit
        freopen("input.txt","rt",stdin);
        freopen("output.txt","wt",stdout);
#endif
        initfact();
        assert(read());
        solve();
        return 0;
}