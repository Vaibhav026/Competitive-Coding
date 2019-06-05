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

bool isSuffix(string s1, vector<char> s2) 
{ 
    int n1 = s1.length(), n2 = s2.size(); 
    if (n1 > n2) 
      return false; 
    for (int i=0; i<n1; i++) 
       if (s1[n1 - i - 1] != s2[n2 - i - 1]) 
           return false; 
    return true; 
} 


pair<int,int> gen(vector<char> v){

    if(isSuffix("lios",v)){
        return mp(1,1);
    }

    if(isSuffix("liala",v)){
        return mp(2,1);
    }

    if(isSuffix("etr",v)){
        return mp(1,2);
    }

    if(isSuffix("etra",v)){
        return mp(2,2);
    }

    if(isSuffix("initis",v) ) {
        return mp(1,3);
    }

    if(isSuffix("inites",v)){
        return mp(2,3);
    }

    return mp(3,0);

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    char line[500005];

    scanf ("%[^\n]%*c", line);


    int l = strlen(line);

    vector< char > v[100001];

    int it = 0;

    for(int i=0;i<l;i++){

        if(line[i] == ' '){
            it++;
        }
        else{
            v[it].pb(line[i]);
        }

    }

    int vsiz = it + 1;

    pair<int,int> gender = gen(v[0]);

    //cout << gender.first<< endl;
    if(gender.first == 3){

        cout << "NO";
        return 0;
    }

    if(vsiz == 1 && gender.first != 3){
        cout << "YES";
        return 0;
    }

    if(gender.first == 1){

        

            int x = 0;

            int adj = 0;

            int noun = 0;

            int verb = 0;

            while(x<vsiz && isSuffix("lios",v[x])){
                x++;
                adj++;
            }

            while(x<vsiz && isSuffix("etr",v[x])){
                x++;
                noun++;
            }

            while(x<vsiz && isSuffix("initis",v[x])){
                x++;
                verb++;
            }

            if(x == vsiz){
                if(adj >= 0 && noun == 1 && verb >= 0){
                    cout << "YES";
                }
                else
                    cout << "NO";

                return 0;
            }
            else{
                cout << "NO";
                return 0;
            }                        
        
    }
    else{

            int x = 0;

            int adj = 0;

            int noun = 0;

            int verb = 0;

            while(x<vsiz && isSuffix("liala",v[x])){
                x++;
                adj++;
            }

            while(x<vsiz && isSuffix("etra",v[x])){
                x++;
                noun++;
            }

            while(x<vsiz && isSuffix("inites",v[x])){
                x++;
                verb++;
            }

            if(x == vsiz){
                if(adj >= 0 && noun == 1 && verb >= 0){
                    cout << "YES";
                }
                else
                    cout << "NO";

                return 0;
            }
            else{
                cout << "NO";
                return 0;
            }              





    }







    return 0;

}