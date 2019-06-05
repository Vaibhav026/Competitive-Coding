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


    int n,m;

    cin >> n >> m;

    char ch[n+1][m+1];

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++)
            cin >> ch[i][j];
    }

    int l = min(n,m);

    int dpw[n+1][m+1][l+1],dpb[n+1][m+1][l+1];
    
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            dpw[i][j][0] = 0;
            dpb[i][j][0] = 0;

            if(ch[i][j] == '0'){
                dpw[i][j][1] = 0;
                dpb[i][j][1] = 1;
            }
            else{
                dpb[i][j][1] = 0;
                dpw[i][j][1] = 1;
            }


            for(int k=2;k<=l;k++){
                dpw[i][j][k] = -1;
                dpb[i][j][k] = -1;
            }
        }
    }    


    int ans[l+1];

    int p1w,p2w,p3w;

    int p1b,p2b,p3b;

    for(int k=2;k<=l;k++){

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                if(i+1 >n || j+1 >m){

                    dpw[i][j][k] = -1;
                    dpb[i][j][k] = -1;
                }
                else{

                    p1w = dpb[i+1][j][k-1];
                    p2w = dpb[i][j+1][k-1];
                    p3w = dpw[i+1][j+1][k-2];

                    if(p1w == -1 || p2w == -1 ||  p3w == -1){

                        dpw[i][j][k] =  -1;
                    }
                    else{

                        dpw[i][j][k] = p1w + p2w - p3w;

                        if(ch[i+k-1][j+k-1] == '1')
                            dpw[i][j][k]++;  

                        if(ch[i][j] == '1')
                            dpw[i][j][k]++;                            
                    }

                    p1b = dpw[i+1][j][k-1];
                    p2b = dpw[i][j+1][k-1];
                    p3b = dpb[i+1][j+1][k-2];

                    if(p1b == -1 || p2b == -1 ||  p3b == -1){

                        dpb[i][j][k] =  -1;
                    }
                    else{

                        dpb[i][j][k] = p1b + p2b - p3b;  
                    
                        if(ch[i+k-1][j+k-1] == '0')
                            dpb[i][j][k]++;

                        if(ch[i][j] == '0')
                            dpb[i][j][k]++;
                    }
                }





            }
                
        }
        
    }
    
    //cout << dpb[2][2][2] << " " << dpb[1][3][2] << " " << dpb[2][3][1]  << endl;
    ans[1] = 0;

    for(int k=2;k<=l;k++){

        ans[k] = 400001;
        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){


                if(dpw[i][j][k] != -1 && dpw[i][j][k] < ans[k]){
                    ans[k] = dpw[i][j][k];

                }

                if(dpb[i][j][k] != -1 && dpb[i][j][k] <  ans[k])
                    ans[k] = dpb[i][j][k];

            }
        }

    }

    // for(int k=1;k<=l;k++){
    //     cout << dpw[1][2][k] << " ";
    // }
    // cout << endl;
    long int q;

    cin >> q;

    long int c;

    int index;

    // for(int i=1;i<=l;i++)
    //     cout << ans[i] << "\n";
    
    for(int i=1;i<=q;i++){

        cin >> c;

        index = l;
        for(int k=1;k<=l;k++){

            if(ans[k] > c){
                index = k-1;
                break;
            }
        }

        cout << index << "\n";

    }

    return 0;
}