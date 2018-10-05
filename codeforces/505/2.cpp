#include <bits/stdc++.h>
using namespace std;

long int n;

long int a[150000];
long int b[150000];

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

bool solve(long int x){

    rep(i,n){

        if((a[i]%x) != 0 && (b[i]%x) != 0)
            return false;
    }

    return true;

}

std::vector<long int> first;
std::vector<long int> second;

void primeFactors(long int n)
{
    // Print the number of 2s that divide n
    
    if(n%2  == 0){
        first.pb(2);
    }
    while (n%2 == 0)
    {
        
        n = n/2;
    }
    
    long int sq = sqrt(n);
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (long int i = 3; i <= sq; i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            first.pb(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        first.pb(n);
}

void primeFactors_b(long int n)
{
    // Print the number of 2s that divide n
    
    if(n%2  == 0){
        second.pb(2);
    }
    while (n%2 == 0)
    {
        
        n = n/2;
    }
    
    long int sq = sqrt(n);
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (long int i = 3; i <= sq; i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            second.pb(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        second.pb(n);
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    rep(i,n){
        cin >> a[i] >> b[i];
    }

    primeFactors(a[0]);

    primeFactors_b(b[0]);


    long int s1 = first.size();
    long int s2 = second.size();

    bool res;

    for(long int i=0;i<s1;i++){

        res = true;

        for(long int j=0;j<n;j++){
            
            if(a[j]%first[i] != 0 && b[j]%first[i] != 0 ){
                
                res = false;
                break;    
            }    
        }

        if(res){
            cout << first[i];
            return 0;
        }
    }


    for(long int i=0;i<s2;i++){

        res = true;

        for(long int j=0;j<n;j++){
            
            if(a[j]%second[i] != 0 && b[j]%second[i] != 0 ){
                
                res = false;
                break;    
            }    
        }

        if(res){
            cout << second[i];
            return 0;
        }
    }

    cout << "-1";
    return 0;
}
