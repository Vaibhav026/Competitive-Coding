#include<bits/stdc++.h>
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


int main()
{   
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif

    ll n,num;

    cin >> n >> num;

    ll s[n];

    rep(i,n){
        cin >> s[i];
    }

    ll p[n];


    rep(i,n){
        cin >> p[i];
    }


    s[num-1] += p[0];

    ll tmp = s[num-1];


    sort(s,s+n,greater<ll>());

    int index;

    rep(i,n){

        if(s[i] == tmp){
            index = i;
            break;
        }
    }

    int it = 1;

    for(int i = index-1;i >=0; i--){
        s[i] += p[it];
        it++;
    }

    int last = n-1;

    int l,r,mid;

    bool mark = false;

    int ind;

    for(int i= index+1;i<n;i++){
        
        mark = false;

        l = it;

        r = n-1;

        while(l<=r){

            mid = (l+r)/2;

            if(p[mid] == -1){
                r = mid-1;
            }
            else if((s[i] + p[mid]) <= tmp ){
                mark = true;
                ind = mid;
                r = mid-1;
            }
            else{
                l = mid+1 ;
            }
        }

        if(mark){
            s[i] += p[ind];
            p[ind] = -1; 
        }
        else{
            s[i] += p[it];
            p[it] = -1;
            it++;
        }    
    }


    sort(s,s+n,greater<ll>());


    int ans;

    // rep(i,n){

    //     if(s[i] == tmp){
    //         ans =  i;
    //     }
    // }


    std::vector<ll> v;

    v.pb(s[0]);


    rep1(i,n){

        if(s[i] != s[i-1])
            v.pb(s[i]);
    }

    ll siz = v.size();

    rep(i,siz){
        
        //cout << v[i] << " ";    
        if(v[i] == tmp){
            ans = i+1;
        }
        //cout << endl; 
    }

    cout << (ans);





    return 0;
}