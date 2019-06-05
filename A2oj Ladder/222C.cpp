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
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i <= (b); i ++)
    #define rep(i, n)       fl(i, 1, n)
    #define loop(i, n)      fl(i, 0, n - 1)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    #define rrep(i, n)      rfl(i, n, 1)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    /* String methods */
    #define dig(i)          (s[i] - '0')
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define fr              first
    #define sc              second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define clr(a)          fill(a, 0)
    #define endl            '\n'
    /* Mathematical */
    #define IINF            0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl
    /* Fast Input Output */
    #define FAST_IO                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 100010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

ll MAXN = 10000001;

ll spf[10000001];

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

ll p1[10000001];

ll p2[10000001];

void getFactorization(ll x,bool var) 
{ 
    //vector<int> ret; 
    while (x != 1) 
    { 	
    	if(var)
        	p1[spf[x]]++;
        else
        	p2[spf[x]]++;

        x = x / spf[x]; 
    } 
    //return ret; 
} 
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    FAST_IO;

    
    for(int i=0;i<=MAXN;i++){
    	p1[i] = 0;
    	p2[i] = 0;
    }

    ll n,m;

    cin >> n >> m;

    ll a[n],b[m];

    sieve();

    rep(i,n){
    	cin >> a[i];
    	getFactorization(a[i],true);
    }

    rep(i,m){
    	cin >> b[i];
    	getFactorization(b[i],false);
    }

    vector< pair<ll,ll> > prm1;
    vector< pair<ll,ll> > prm1;

    for(int i=2;i<=MAXN;i++){
    	
    	if(p1[i] != 0 && p2[i]!= 0){

    		if(p1[i] >= p2[i]){
    			p1[i] -= p2[i];

    			if(p1[i] != 0)
    				prm1.pb(mp(i,p1[i]));
    		}
    		else{
    			p2[i] -= p1[i];

    			if(p2[i] != 0)
    				prm2.pb(mp(i,p2[i]));
    		}
    	}
    	else if(p1[i] != 0){
    		prm1.pb(mp(i,p1[i]));	
    	}
    	else if(p2[i] != 0){
    		prm2.pb(mp(i,p2[i]));
    	}
    }	


    vector<ll> v1;
    vector<ll> v2;

    ll i =2;
    while(i<= prm1.size()){
    	
    	
    	ll prev = 1;	
    	
    	while(1){

    		ll val = MAXN/prev;


    		if(p1[i] <= ((double) log(val)/log(i)) ){
    			prev = prev * pow(i,p1[i]);
    			p1[i] = 0;
    			i++;
    		}
    		else{
    			int red = log(val)/log(i);
    			prev =  prev * pow(i,red);
    			p1[i] -= red; 
    			v1.pb(prev);
    			break;
    		}
    	}	

    }

    i =2;
    while(i<=MAXN){
    	
    	if(p2[i] == 0)
    		continue;	
    	ll prev = 1;	
    	
    	while(1){

    		ll val = MAXN/prev;


    		if(p2[i] <= ((double) log(val)/log(i)) ){
    			prev = prev * pow(i,p2[i]);
    			p2[i] = 0;
    			i++;
    		}
    		else{
    			int red = log(val)/log(i);
    			prev =  prev * pow(i,red);
    			p2[i] -= red; 
    			v2.pb(prev);
    			break;
    		}
    	}	

    }
    return 0;
}