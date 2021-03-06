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
	 #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    
    #endif
	int n;
	cin >> n;

	priority_queue <ll> a,b;

	ll x;
	rep(i,n){

		cin >> x;
		a.push(x);
	}

	rep(i,n){

		cin >> x;
		b.push(x);
	}

	// make_heap(a.begin(), a.end());

	// make_heap(b.begin(), b.end());

	int sizea = n;
	int sizeb = n;

	ll scorea = 0,scoreb= 0 ;

	ll vala,valb;

	int turn = 0;
	while(sizea > 0 && sizeb > 0){

		vala = a.top();
		valb = b.top();

		if(turn%2 == 0){
			if(vala >= valb){
				scorea += vala;
				a.pop();
				sizea--;
			}
			else{
				b.pop();
				sizeb--;
			}
		}
		else{

			if(valb >= vala){
				scoreb += valb;
				b.pop();
				sizeb--;
			}
			else{
				a.pop();
				sizea--;
			}

		}

		turn++;

	}

	ll ans;

	if(sizea == 0 && sizeb == 0){
		ans = scorea - scoreb;
		cout << ans;
		return 0;
	}

	if(sizea == 0){

		while(sizeb != 0){

			if(turn%2 == 0 ){
				b.pop();	
			}
			else{
				scoreb += b.top();
				b.pop();
			}	
			
			sizeb--;
			turn++;
		}

		ans = scorea - scoreb;
		cout << ans;

		return 0;

	}

	if(sizeb == 0){

		while(sizea != 0){

			if(turn%2 == 0 ){
				scorea += a.top();
				a.pop(); 	
			}
			else
				a.pop();

			sizea--;

			turn++;

		}

	}

	ans = scorea - scoreb;
	cout << ans;





	return 0;
}