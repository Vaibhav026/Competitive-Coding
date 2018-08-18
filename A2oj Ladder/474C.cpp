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



// Structure of a point in 2D space
struct Point
{
    long double x, y;
};
 
// A utility function to find square of distance
// from point 'p' to poitn 'q'
int distSq(Point p, Point q)
{
    return (p.x - q.x)*(p.x - q.x) +
           (p.y - q.y)*(p.y - q.y);
}
 
// This function returns true if (p1, p2, p3, p4) form a
// square, otherwise false
bool isSquare(Point p1, Point p2, Point p3, Point p4)
{
    ld d2 = distSq(p1, p2);  // from p1 to p2
    ld d3 = distSq(p1, p3);  // from p1 to p3
    ld d4 = distSq(p1, p4);  // from p1 to p4
    
    if(d2 == 0 || d3 == 0 || d4 == 0)
        return false;

    // If lengths if (p1, p2) and (p1, p3) are same, then
    // following conditions must met to form a square.
    // 1) Square of length of (p1, p4) is same as twice
    //    the square of (p1, p2)
    // 2) p4 is at same distance from p2 and p3
    if (d2 == d3 && 2*d2 == d4)
    {
        ld d = distSq(p2, p4);
        return (d == distSq(p3, p4) && d == d2);
    }
 
    // The below two cases are similar to above case
    if (d3 == d4 && 2*d3 == d2)
    {
        ld d = distSq(p2, p3);
        return (d == distSq(p2, p4) && d == d3);
    }
    if (d2 == d4 && 2*d2 == d3)
    {
        ld d = distSq(p2, p3);
        return (d == distSq(p3, p4) && d == d2);
    }
 
    return false;
}

int main(int argc, char const *argv[])
{
    int n;

    cin >> n;


    ld x[4],y[4],a[4],b[4];

    int sum = 0;

    rep(i,n){

        sum = 0;

        std::vector<ld> xpos[4];
        std::vector<ld> ypos[4];

        cin >> x[0] >> y[0] >> a[0] >> b[0];
        cin >> x[1] >> y[1] >> a[1] >> b[1];
        cin >> x[2] >> y[2] >> a[2] >> b[2];
        cin >> x[3] >> y[3] >> a[3] >> b[3];

        bool aa = false;
        rep(j,4){
            ld r = sqrt( (ld) (x[j]-a[j])*(x[j]-a[j]) + (ld) (y[j]-b[j])*(y[j]-b[j]) );

            ld cos_theta =  (ld) (x[j]-a[j])/r ;
            ld sin_theta =  (ld) (y[j]-b[j])/r ;

            cout << cos_theta << endl;
            cout << sin_theta << endl;

            xpos[j].pb(x[j]);
            ypos[j].pb(y[j]);

            xpos[j].pb(a[j]-r*cos_theta);
            ypos[j].pb(b[j]+r*sin_theta);

            xpos[j].pb(a[j]-r*cos_theta);
            ypos[j].pb(b[j]-r*sin_theta);

            xpos[j].pb(a[j]+r*cos_theta);
            ypos[j].pb(b[j]-r*sin_theta);
        }

        rep(j,4){

            rep(k,4){

                rep(l,4){

                    rep(m,4){

                        Point p1 = {xpos[0][j],ypos[0][j]};
                        Point p2 = {xpos[1][k],ypos[1][k]};
                        Point p3 = {xpos[2][l],ypos[2][l]};
                        Point p4 = {xpos[3][m],ypos[3][m]};

                        if(isSquare(p1,p2,p3,p4)){
                            sum += j+k+l+m;
                            aa = true;
                            break;
                        }

                    }

                    if(aa)
                        break;
                }

                if(aa)
                    break;
            }

            if(aa)
                break;
        }


        if(aa)
            cout << sum << endl;
        else
            cout << "-1\n";

    }


    return 0;
}