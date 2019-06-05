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

bool isSuffix(string s1, string s2) 
{ 
    int n1 = s1.length(), n2 = s2.length(); 
    if (n1 > n2) 
      return false; 
    for (int i=0; i<n1; i++) 
       if (s1[n1 - i - 1] != s2[n2 - i - 1]) 
           return false; 
    return true; 
} 

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    FAST_IO;
    //cout << "!\n";
    ll n;
    cin >> n;

    vector<int> row[n+1];

    vector<int> col[n+1];

    
    int x,y;

    //cout << "!\n";
    for(int i=0;i<n;i++){
        cin >> x >> y;
        row[x].pb(y);
        //cout << "!\n";
        col[y].pb(x);
    }

    for(int i=1;i<=n;i++){
        sort(row[i].begin(),row[i].end());
        sort(col[i].begin(), col[i].end());
    }

    std::vector<int> op;

    std::vector<pair<int,int> > v;

    for(int i=n;i>=2;i--){

        //cout << "!\n";


        if(col[i].size() != 0 ){

            //cout << i << endl;
            // if(col[i][0] > i)
            //     break;
            //cout << "!\n";
            int col_index = -1;

            for(int j=i-1;j>=1;j--){
                if(col[j].size() == 0 ){
                    col_index = j;
                    break;
                }
            }

            if(col_index != -1){
                swap(col[col_index],col[i]);

                op.pb(2);
                v.pb(mp(col_index,i));

                for(int j=1;j<=n;j++){

                    for(int k=0;k<row[j].size();k++){

                        if(row[j][k] == col_index){
                            row[j][k] = i;
                        }
                        else if(row[j][k] == i){
                            row[j][k] =  col_index;
                        }
                    }
                }
            }
                

            

        }

        if(row[i].size() == 0){

            int row_index = -1;

            for(int j=i-1;j>=1;j--){
                if(row[j].size() != 0){
                    row_index = j;
                    break;
                }
            }

            if(row_index != -1){
                swap(row[i],row[row_index]);

                op.pb(1);
                v.pb(mp(row_index,i));
                
                for(int j=1;j<=n;j++){

                    for(int k=0;k<col[j].size();k++){

                        if(col[j][k] == row_index){
                            col[j][k] = i;
                        }
                        else if(col[j][k] == i){
                            col[j][k] =  row_index;
                        }
                    }
                }

            }
                

        }

        for(int x=1;x<=n;x++){
            
            auto it = row[x].begin();
            while( it != row[x].end()){

                if(*it == i){
                    it++;
                    auto it2 = it-1;
                    row[x].erase(it2);
                }
                else{
                    it++;
                }
            } 
         
        }

        for(int x=1;x<=n;x++){
            
            auto it = col[x].begin();
            while( it != col[x].end()){

                if(*it == i){
                    it++;
                    auto it2 = it-1;
                    col[x].erase(it2);
                }
                else{
                    it++;
                }
            }
        }        
        
    }

    cout << op.size()<< endl;

    for(int i=0;i<v.size();i++){
        cout << op[i] << " " << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}