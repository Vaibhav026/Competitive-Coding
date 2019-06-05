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




vector<ll> initializeDiffArray(vector<ll>& A) 
{ 
    long int n = A.size(); 
  
    // We use one extra space because 
    // update(l, r, x) updates D[r+1] 
    vector<ll> D(n + 1); 
  
    D[0] = A[0], D[n] = 0; 
    for (long int i = 1; i < n; i++) 
        D[i] = A[i] - A[i - 1]; 
    return D; 
} 
  
// Does range update 
void update(vector<ll>& D, ll l, ll r, ll x) 
{   
    if(l >=0 && l<= 1000000 && r >=0 && r <= 1000000){
        D[l] += x; 
        D[r + 1] -= x;
    }
     
} 
  
// Prints updated Array 
void printArray(vector<ll>& A, vector<ll>& D) 
{ 
    for (long int i = 0; i < A.size(); i++) { 
        if (i == 0) 
            A[i] = D[i]; 
        else
            A[i] = D[i] + A[i - 1]; 
  
        //cout << A[i] << " "; 
    } 
    //cout << endl; 
}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    ll n,q;

    cin >> n >> q;


    vector<ll> A;

    rep(i,1000001)
        A.pb(0);

    vector<ll> D = initializeDiffArray(A);    

    ld x[n],y[n],r[n];

    rep(i,n){
        cin >> x[i] >> y[i] >> r[i];
    }    

    long double dis;

    long double maxdis,mindis;

    ll mn,mx;

    rep(i,n){

        fl(j,i+1,n){

            dis = ((x[i]-x[j])*((x[i]-x[j]))  + (y[i]-y[j])*((y[i]-y[j])) );
            

            ld  xx = (r[i]+r[j])*(r[i]+r[j]);

            if(dis == xx){
                mn = 0;
                mx = (2)*(r[i]+r[j]);
            }
            else if(dis > xx){
                mindis = sqrt(dis) - (r[i] + r[j]);
                mn = ceil(mindis);
                maxdis = sqrt(dis) + (r[i] + r[j]);
                mx = floor(maxdis);
            }
            else if(dis < xx && dis> ( abs(r[i]-r[j])*abs(r[i]-r[j]) ) ){

                mn = 0;
                maxdis = sqrt(dis) + (r[i] + r[j]);
                mx = floor(maxdis);

            }
            else{
                mindis = abs(r[i]-r[j]) -sqrt(dis);
                mn = ceil(mindis);
                maxdis = sqrt(dis) + (r[i] + r[j]);
                mx = floor(maxdis);

            }

            update(D,mn,mx,1);

        }

    }


    printArray(A,D);

    ll k;
    rep(i,q){

        cin >> k;
        cout << A[k] << "\n";

    }
    return 0;
}