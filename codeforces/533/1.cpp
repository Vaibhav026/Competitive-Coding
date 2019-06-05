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


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);
    #endif

    FAST_IO;

    //cout << "!";  

    int n;
    cin >> n;


    int a[n+1];

    rep(i,n){
        cin >> a[i];
    }

    sort(a+1,a+n+1);

    if(n == 1){
        cout << a[1] << " 0";
        return 0; 
    }
    if(n %2 == 1){
        int mid = n/2 + 1;

        int cost1 = 0;

        int cost2 = 0;

        int cost3 = 0;
            
        rep(i,n){

            if(a[i] < a[mid]){

                cost1 += (a[mid]-1) - a[i];

            }
            else if(a[i] > a[mid]){

                cost1 += a[i] - (a[mid] + 1);
            }
        }

        rep(i,n){

            if(a[i] < (a[mid]-1)){

                cost2 += (a[mid]-1-1) - a[i];

            }
            else if(a[i] > (a[mid]-1)){

                cost2 += a[i] - (a[mid]-1 + 1);
            }
        }

        rep(i,n){

            if(a[i] < (a[mid]+1)){

                cost3 += (a[mid]+1-1) - a[i];

            }
            else if(a[i] > (a[mid]+1)){

                cost3 += a[i] - (a[mid]+1 + 1);
            }
        }


        if(cost1 == min(cost1,min(cost2,cost3))){
            cout << a[mid] << " " << cost1;    
        }
        else if(cost2 == min(cost1,min(cost2,cost3)))
            cout << a[mid] -1 <<  " " << cost2;
        else
            cout << a[mid] + 1 << " " << cost3;
        //cout << a[mid] << " " << cost;
    }
    else{

        int mid1 = n/2;

        int mid2 = mid1 +1;

        int cost11 = 0;
        int cost12 = 0;
        int cost13 = 0;    
        
        int cost21 = 0;
        int cost22 = 0;
        int cost23 = 0;

        rep(i,n){

            if(a[i] < a[mid1]){

                cost11 += (a[mid1]-1) - a[i];

            }
            else if(a[i] > a[mid1]){

                cost11 += a[i] - (a[mid1] + 1);
            }
        }

        rep(i,n){

            if(a[i] < (a[mid1]-1)){

                cost12 += (a[mid1]-1-1) - a[i];

            }
            else if(a[i] > (a[mid1]-1)){

                cost12 += a[i] - (a[mid1]-1 + 1);
            }
        }

        rep(i,n){

            if(a[i] < (a[mid1]+1)){

                cost13 += (a[mid1]+1-1) - a[i];

            }
            else if(a[i] > (a[mid1]+1)){

                cost13 += a[i] - (a[mid1]+1 + 1);
            }
        }

        rep(i,n){

            if(a[i] < a[mid2]){

                cost21 += (a[mid2]-1) - a[i];

            }
            else if(a[i] > a[mid2]){

                cost21 += a[i] - (a[mid2] + 1);
            }
        }

        rep(i,n){

            if(a[i] < (a[mid2]-1)){

                cost22 += (a[mid2]-1-1) - a[i];

            }
            else if(a[i] > (a[mid2]-1)) {

                cost22 += a[i] - (a[mid2]-1 + 1);
            }
        }

    
        rep(i,n){

            if(a[i] < (a[mid2]+1)){

                cost23 += (a[mid2]+1-1) - a[i];

            }
            else if(a[i] > (a[mid2]+1)) {

                cost23 += a[i] - (a[mid2]+1 + 1);
            }
        }        
        

        int d = min(cost11,min(cost12,min(cost13,min(cost21,min(cost22,cost23)))));
        if(cost11 == d)
            cout << a[mid1] << " " << cost11;
        else if(cost12 == d)
            cout << a[mid1]-1 << " " << cost12;
        else if(cost13 == d)
            cout << a[mid1] + 1 << " " << cost13;
        else if(cost21 == d)
            cout << a[mid2] << " " << cost21;
        else if(cost22 == d)
            cout << a[mid2] - 1 << " " << cost22;
        else
            cout << a[mid2] + 1 << " " << cost23;             
    }

    return 0;
}    