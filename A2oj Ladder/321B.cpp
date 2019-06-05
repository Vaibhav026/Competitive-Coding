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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    FAST_IO;

    int n,m;

    cin >> n >> m;

    priority_queue<int> def1;

    priority_queue<int> ciel;


    priority_queue <int, vector<int>, greater<int> > atk1; 
    // min heap for storing values of ATK for J

    string s[n];
    int val[n];

    std::vector<int> ATT;

    std::vector<int> DD;

    for(int i=0;i<n;i++){
        cin >> s[i] >> val[i];

        if(s[i] == "ATK"){
            atk1.push(val[i]);
            ATT.pb(val[i]);
        }
        else
            DD.pb(val[i]);
    }    

    //int cl[m];

    std::vector<int> cl;

    int tmp;

    for(int i=0;i<m;i++){
        cin >> tmp;
        cl.pb(tmp);
        ciel.push(cl[i]);
    }

    ll ans = 0;
    while(ciel.size() > 0){

        int x = ciel.top();

        ciel.pop();

        int y = 0;

        if( atk1.size() > 0){
            y = atk1.top();
            atk1.pop();
        }
        else
            break;

        if(x >= y){
            ans += (x-y);
        }
        else
            break;

    }


    sort(cl.begin(),cl.end());
    std::vector<int>::iterator upper1;

    for(int i=0;i<DD.size();i++){

        upper1 = upper_bound(cl.begin(),cl.end(),DD[i]);

        if(upper1 != cl.end()){
            cl.erase(upper1);
        }
        else{
            cout << ans;
            return 0;
        }     

    }

    ll ans2 =0;

    for(int i=0;i<ATT.size();i++){

        upper1 = upper_bound(cl.begin(),cl.end(),ATT[i]-1);

        if(upper1 != cl.end()){
            ans2 += (*upper1 - ATT[i]);
            cl.erase(upper1);
        }
        else{
            cout << ans;
            return 0;
        }     

    }

    for(int i=0;i<cl.size();i++){
        ans2 += cl[i];
    }

    cout << max(ans,ans2);    
    return 0;
}
