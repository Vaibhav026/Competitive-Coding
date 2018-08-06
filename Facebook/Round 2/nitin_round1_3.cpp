#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

const int N = 200005;
const int M = 23;

ll n, m, w, x, y, z;
int H[N], top[N], bot[N];
ld mn[N], mx[N];

bool possible(ld t) {
	mn[1] = max(ld(0), H[1] - t);
	mx[1] = H[1] + t;
	for (int i=2; i<=n; i++) {
		mn[i] = max(H[i] - t, ld(0));
		mx[i] = H[i] + t;
		if (mn[i-1] - bot[i-1] > mx[i] || mx[i-1] + top[i-1] < mn[i])
			return false;
		mn[i] = max(mn[i], mn[i-1] - bot[i-1]);
		mx[i] = min(mx[i], mx[i-1] + top[i-1]);
	}
	return true;
}

int main() {
	int t;
	cin >> t;

	for (int ci=1; ci<=t; ci++) {
		cin >> n >> m;
		cin >> H[1] >> H[2] >> w >> x >> y >> z;
		top[1] = bot[1] = z + 1;
		top[2] = bot[2] = z + 1;
		for (int i=3; i<=n; i++) {
			H[i] = (w*H[i-2] + x*H[i-1] + y) % z;
			top[i] = bot[i] = z + 1;
		}
		for (int i=0, a, b, u, d; i<m; i++) {
			cin >> a >> b >> u >> d;
			if (b > a) {
				for (int j = a; j < b; j++) {
					top[j] = min(top[j], u);
					bot[j] = min(bot[j], d);
				}
			} else {
				for (int j = b; j < a; j++) {
					top[j] = min(top[j], d);
					bot[j] = min(bot[j], u);
				}
			}
		}

		ld lo = 0, hi = z;
		while (hi - lo > 1e-8) {
			ld mid = (lo + hi) / 2;
			if (possible(mid))
				hi = mid;
			else
				lo = mid;
		}

		cout << "Case #" << ci << ": ";
		cout << fixed << setprecision(7) << lo << "\n";
	}

	return 0;
}