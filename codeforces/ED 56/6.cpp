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
    const ll MOD = 998244353LL;
    const ll MAX = 100010LL;
/* Templates */
template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<typename T> T gcd(T a, T b){ if(b == 0) return a; return gcd(b, a % b); }
template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }


std::vector<ll> adj[300001];

bool visited[300001];

int color[300001];

ll odd ,even;
ll po(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 

bool bfs0(int x){

    queue <ll> q;

    visited[x] = true;

    color[x] = 0;
    even++;

    q.push(x);

    while(!q.empty()){

        int x = q.front();

        //visited[x] = true;
        q.pop();

        int num = 0;

        for(int i=0;i<adj[x].size();i++){

            if(color[adj[x][i]]!= -1){

                if(num == 0){
                    color[x] = (color[adj[x][i]] + 1)%2 ;

                    if(color[x] == 0)
                        even++;
                    else
                        odd++;

                    num++;
                }
                else{

                    if(color[x] == color[adj[x][i]])
                        num = -1;
                }
            }
            
            if(!visited[adj[x][i]])
            {
                visited[adj[x][i]] = true;
                q.push(adj[x][i]);
            }
        }

        if(num == -1)
            return false;

    }

    return true;
}

bool bfs1(int x){

    queue <ll> q;

    visited[x] = true;

    color[x] = 1;

    q.push(x);

    while(!q.empty()){

        int x = q.front();

        visited[x] = true;
        q.pop();

        int num = 0;

        for(int i=0;i<adj[x].size();i++){

            if(visited[adj[x][i]]){

                if(num == 0){
                    color[x] = (color[adj[x][i]] + 1)%2 ;
                    num++;
                }
                else{

                    if(color[x] == color[adj[x][i]])
                        num = -1;
                }
            }
            else
                q.push(adj[x][i]);
        }

        if(num == -1)
            return false;

    }

    return true;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    FAST_IO;
    
    ll t;
    cin >>t;

    ll mm = 998244353; 
    ll n,m;


    ll e = 2;

    ll x,y;

    while(t--){

        

        cin >> n >> m;


        rep(i,m){

            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        for(int i=1;i<=n;i++)
            visited[i] = false;

        bool done = true;

        odd = 0,even = 0;
        ll ans = 0;

        ll tmp = 1;

        for(int i=0;i<=n;i++)
            color[i] = -1;

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                

                if(!bfs0(i)){
                    tmp = 0;
                    done = false;
                    break;
                }       
            

                ans = ( po(e,odd,mm) + po(e,even,mm) )%mm;

                //cout << odd << " " << even << endl;

                tmp = (tmp * ans)%mm;

                //cout << tmp << endl;
                // for(int i=1;i<=n;i++){
                //     color[i] = -1;
                // }

                odd =0;
                even = 0;
            }
        }

        

        cout << tmp << endl;

        for(int i=1;i<=n;i++){
            adj[i].clear();
        }        

    }

    return 0;
}