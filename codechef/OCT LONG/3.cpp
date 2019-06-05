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

ll n,d;

ll ff(ll x){

	ll ans = 0;
	while(x){

		ans += x%10;
		x = x/10;
	}

	
	return ans;
}

ll f(ll x){

	ll ans = 0;
	while(x){

		ans += x%10;
		x = x/10;
	}

	if(ans >= 10){
		return f(ans);
	}
	else
	return ans;
}


ll g(ll x){

	ll ans = 0;
	
	if(x <= 9)
		return 0;

	while(x){

		ans += x%10;
		x = x/10;
	}

	
	return (1+g(ans));
	
}

ll m(ll x,ll val,int i){

	if(i > 20)
		return 100;
	if(x == val)
		return 0;

	return(1+min(m(x+d,val,i+1),m(ff(x),val,i+1)));
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    //cout << g(19) << endl;

    int t;
    cin >> t;

    

    //cout << g(109) << endl;
    ll nsum,dsum;

    while(t--){

    	nsum = 0;
    	dsum = 0;

    	cin >> n >> d;

    	

    	nsum = f(n);

    	dsum = f(d);

    	//cout << nsum << " " << dsum;
    	
    	//cout << g(n) << endl;

    	// bool k[10];

    	// for(int i = 0;i<10;i++)
    	// 	k[i] = false;

    	// k[nsum%9] = true;

    	// int state = nsum;

    	// while(1){

    	// 	state += dsum;
	
    	// 	state = state%9 ;

    	// 	if(k[state] == true)
    	// 		break;

    	// 	k[state] = true;
    			
    	// }

    	// int ans = -1;
    	// for(int i = 1;i<10;i++){

    	// 	if(k[i] == true){
    	// 		ans = i;
    	// 		break;
    	// 	}
    	// }

    	// if(ans == -1 && k[0])
    	// 	ans = 9;

    	ll tmp = n;
    	ll moves = 0;

    	ll ans = nsum;

    	ll val = n;	



    	for(int i =1;i<15;i++){

    		tmp += d;

    		if(f(tmp) < ans){
    			ans = f(tmp);
    			val = tmp;
    			moves = i;
    		}

    	}

    	moves = m(n,ans,0);
    	cout << ans << " " << moves << endl;

    }








	return 0;
}