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

    string s1,s2,virus;

    vector<int> num[27];

    cin >> s1;
    cin >> s2;
    cin >> virus;


    int z;

    for(int i=0;i<s1.length();i++){
        z = s1[i] - 'A' + 1;

        num[z].pb(i);
    }


    int l2 = s2.length();

    int index[l2];

    int dp[l2];

    string str[l2];

    for(int i=0;i<l2;i++){
        
        index[i] = -1;    
        dp[i] = 0;
        str[i] = "";
    }

    for(int i=0;i<l2;i++){

        z = s2[i] - 'A' + 1;

        if(num[z].size() != 0){
            
            dp[i] = 1;
            str[i] += s2[i];
            index[i] = num[z][0];

            if(str[i] == virus){
                dp[i] = 0;
                index[i] = -1;
                str[i] = "";
            }

            for(int j=i-1;j>=0;j--){

                for(int k =0;k<num[z].size();k++){

                    if( index[j] != -1 && (num[z][k] > index[j]) ){

                        string tmp = "";
                        tmp = str[j] + s2[i];

                        string tmp2 = "";
                        tmp2 += s2[i];

                        if(tmp != virus && tmp2 != virus){
                            //dp[i] = max(dp[i],tmp.length());

                            if(dp[i] < tmp.length()){
                                dp[i] = tmp.length();
                                str[i] = tmp;
                                index[i] = num[z][k];
                            }
                        } 
                    }
                }
            }
        }    
    }

    cout << str[13] << endl;
    int ind = 0;
    for(int i=0;i<l2;i++){
        if(dp[i] > dp[ind])
            ind = i;
    }

    //cout << dp[ind];

    if(dp[ind] != 0){
        //cout << "\n";
        cout << str[ind];
    }
    else
        cout << "0";
    return 0;
}    