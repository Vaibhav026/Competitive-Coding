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

ll n,m,k;

ll type[100001];

ll c[501];

ll component[100001];

bool visited[100001];

std::vector<ll> adj0[100001];
std::vector< pair<ll,ll> > adj1[100001];

//std::vector< pair<ll,ll> > grp_adj[501];

ll  grp_2d[501][501];

int sum[501];

ll grp = 1;

void dfs(ll x){

    visited[x] = true;
    component[x] = grp;

    ll siz = adj0[x].size();

    ll u;

    for(int i=0;i<siz;i++){

        u = adj0[x][i];

        if(!visited[u])
            dfs(u);
    }
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    FAST_IO;
    
    
    cin >> n >> m >> k;

    sum[0] = 0;

    rep(i,k){
        cin >> c[i];
        sum[i] = c[i] + sum[i-1];
    }
    

    ll mark = c[1];

    ll ct = 1;

    ll itr = 1;

    //cout << "va";
    rep(i,n){   

        if(i<=mark){
            type[i] = ct;
        }
        else{
            itr++;
            mark += c[itr];
            ct++;
            type[i] = ct;
        }

    }

    // rep(i,n){   

    //     cout << type[i] << " ";
    // }

//    cout << endl;
    ll u,v,x;


    rep(i,k){
        rep(j,k)
            grp_2d[i][j] = LLINF;
        grp_2d[i][i] = 0;    
    }

    rep(i,m){

        cin >> u >> v >> x;

        adj1[u].pb(mp(v,x));
        adj1[v].pb(mp(u,x));
        
        if(x == 0){
            adj0[u].pb(v);
            adj0[v].pb(u);
        }

        if(type[u] != type[v]){
            
            grp_2d[type[u]][type[v]] = min(x,grp_2d[type[u]][type[v]]); 
            grp_2d[type[v]][type[u]] = min(x,grp_2d[type[v]][type[u]]);
            
        }

    }

    
    rep(i,n){

        if(!visited[i]){
            dfs(i);
            grp++;
        }
    }


    for(int i=1;i<=k;i++){

        for(int j=sum[i-1]+1;j<=sum[i];j++){

            int zz = sum[i-1] +1;
            if(component[j] != component[zz]) {
                cout << "No";
                return 0;
            }
        }
    }


    cout << "Yes\n";

    // rep(i,k){
    //     rep(j,k)
    //         cout << grp_2d[i][j] << " ";

    //     cout << "\n";    
    // }

    for(int mid=1;mid<=k;mid++){

        for(int i=1;i<=k;i++){

            for(int j=1;j<=k;j++){

                
                grp_2d[i][j] = min(grp_2d[i][j],grp_2d[i][mid] + grp_2d[mid][j]);
            }
        }

    }

    rep(i,k){
        rep(j,k){
            if(grp_2d[i][j] == LLINF){
                cout << "-1 ";     
            }
            else
                cout << grp_2d[i][j] << " ";
        }

        cout << "\n";    
    }
    return 0;
}