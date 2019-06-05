#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 100000;
int val[MAXN];
int tdeath[MAXN];

int main() {
    cin.sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", val+i);
    }

    tdeath[0] = -1;
    vector<int> S(1, 0);
    int sol = 0;
    for (int i=1; i<n; ++i) {
        tdeath[i] = 0;
        while (S.size()>0 && val[S.back()]<val[i]) {
            tdeath[i] = max(tdeath[i], tdeath[S.back()]+1);
            S.pop_back();
        }
        if (S.size() == 0) {
            tdeath[i] = -1;
        }
        S.push_back(i);
        sol = max(sol, tdeath[i]+1);
    }

    printf("%d\n", sol);
    return 0;
}