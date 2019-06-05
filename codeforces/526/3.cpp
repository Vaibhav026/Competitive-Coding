#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef long double         ld;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
    typedef vector < vll >  vvll;
    typedef vector < vpii > vvpii;
    typedef set <int>       si;
typedef complex <double>    pnt;
typedef vector <pnt>        vpnt;
typedef priority_queue <pii, vpii, greater<pii> > spq;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i < (b); i ++)
    #define rep(i, n)       fl(i, 0, n)
    #define rep1(i, n)      fl(i, 1, n)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    #define mt              make_tuple
    /* String methods */
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define F               first
    #define S               second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define endl            '\n'
    /* Mathematical */
    #define oo              0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl
/* Constants */
    const ll MOD = 100000000LL;
    const ll MAX = 100010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

bool operator <= (const string &a, const string &b){

    if(a.size() < b.size()) return true;
    if(a.size() > b.size()) return false;

    rep(i, sz(a)){
        if(a[i] < b[i]) return true;
        if(a[i] > b[i]) return false;
    }

    return true;
}

ll v[1001];
ll n,s;

bool solve(ll x){

    ll val = s;
    //cout << v[0] << endl; 
    rep(i,n){
        if(v[i] > x){
            val = val - (v[i]-x);
        } 
        
        if(val <= 0){
            return true;
        }

        //cout << val << endl;
    }

    if(val <= 0){
        return true;
    }

    return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    //bool vis[10000][1000];

    ll mod = pow(10,9) + 7;

    string s;

    cin >> s;

    char c[100001];

    ll l = s.length();

    int j = 0;

    rep(i,l){

        if(s[i] == 'a'){
            c[j] = 'a';
            j++;
        }
        else if(i == 0 && s[i] == 'b'){
            c[j] = 'b';
            j++;
        }
        else if (s[i] == 'b' && i>0 && s[i-1] != 'b'){
            c[j] = 'b';
            j++;   
        }

    }

    vector <ll> v;

    ll cnt = 0;

    // rep(i,j){
    //     cout << c[i];
    // }
    rep(i,j){

        if( c[i] == 'b'){
            v.pb(cnt+1);
            cnt = 0;
        }
        else{
            cnt++;

            if(i == j-1){
                v.pb(cnt + 1);
            }
        }

    }

    ll prod = 1;

    for(int i =0;i<v.size();i++){
        //cout << v[i] << endl;
        prod = (prod * v[i])% mod;
    }

    ll ans = ( prod + (mod-1)%mod ) % mod;

    cout << ans;

    return 0;

}    