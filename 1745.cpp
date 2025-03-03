#include<bits/stdc++.h>
using namespace std;

#define int long long
#define debug(x) cerr << #x << " = " << x << '\n'

int is[2010][2010];

bool checkPartitioning(string s) {
    int n = s.size();
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            if (len == 1) {
                is[l][r] = 1;
            } else if (len == 2) {
                if (s[l] == s[r]) is[l][r] = 1;
            } else {
                if (s[l] == s[r] && is[l + 1][r - 1]) is[l][r] = 1;
            }
        }
    }
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r <= n - 2; ++r) {
            //[0, l] [l + 1, r] [r + 1, n - 1]
            if (is[0][l] && is[l + 1][r] && is[r + 1][n - 1]) return true;
        }
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s;
    cin >> s;
    bool ans = checkPartitioning(s);
    if (ans) cout << "true\n";
    else cout << "false";

    return 0;
}
