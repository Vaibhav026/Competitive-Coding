#include <bits/stdc++.h>
using namespace std;

long int n;

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


// lookup[i][j] is going to store GCD of
// arr[i..j]. Ideally lookup table
// size should not be fixed and should be
// determined using n Log n. It is kept
// constant to keep code simple.
long int table[300001][100];
 
// it builds sparse table.
void buildSparseTable(ll arr[], int n)
{
    // GCD of single element is element itself
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];
 
    // Build sparse table
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = __gcd(table[i][j - 1],
                    table[i + (1 << (j - 1))][j - 1]);
}
 
// Returns GCD of arr[L..R]
int query(int L, int R)
{
    // Find highest power of 2 that is smaller
    // than or equal to count of elements in given
    // range.For [2, 10], j = 3
    int j = (int)log2(R - L + 1);
 
    // Compute GCD of last 2^j elements with first
    // 2^j elements in range.
    // For [2, 10], we find GCD of arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    return __gcd(table[L][j], table[R - (1 << j) + 1][j]);
}






long int lookup[300001][100];
 
// Fills lookup array lookup[][] in bottom up manner.
void min_buildSparseTable(ll arr[], int n)
{
    // Initialize M for the intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = arr[i];
 
    // Compute values from smaller to bigger intervals
    for (int j = 1; (1 << j) <= n; j++) {
 
        // Compute minimum value for all intervals with
        // size 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
 
            // For arr[2][10], we compare arr[lookup[0][7]] 
            // and arr[lookup[3][10]]
            if (lookup[i][j - 1] < 
                        lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = 
                         lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
 
// Returns minimum of arr[L..R]
int min_query(int L, int R)
{
    // Find highest power of 2 that is smaller
    // than or equal to count of elements in given
    // range. For [2, 10], j = 3
    int j = (int)log2(R - L + 1);
 
    // Compute minimum of last 2^j elements with first
    // 2^j elements in range.
    // For [2, 10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
 
    else
        return lookup[R - (1 << j) + 1][j];
}


std::vector<int> kk[300001];

bool solve(int length){

    for(int i=0;i<n;i++){

        if(i+length-1 < n){

             if(query(i,i+length-1) == min_query(i,i+length-1)){
                kk[length].pb(i+1);
             }   
        }
    }

    if(kk[length].size() > 0)
        return true;

    return false;
}


int main()
{
    
    cin >> n;

    ll a[n];

    rep(i,n){
        cin >> a[i];
    }


    min_buildSparseTable(a,n);

    buildSparseTable(a,n);


    long int l = 1;

    long int r = n;

    long int ans;

    while(l<=r){

        long int mid = (l+r)/2 ;

        if(solve(mid)){

            ans = mid;

            l = mid + 1;
        }
        else
            r = mid-1;


    }


    cout << kk[ans].size() << " " << (ans - 1) <<  endl;

    for(int i=0;i<kk[ans].size();i++){
        cout << kk[ans][i] << " ";
    }















    return 0;
}