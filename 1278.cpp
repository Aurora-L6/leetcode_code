#include<bits/stdc++.h>
using namespace std;

#define int long long
#define debug(x) cerr << #x << " = " << x << '\n'


const int N = 105;

int c[N][N], dp[N][N];

int palindromePartition(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // [i, j] abc
            int cnt = 0;
            for (int l = i, r = j; r - l >= 1; ++l, --r) {
                if (s[l] != s[r]) cnt++;
            }
            c[i][j] = cnt;
            // printf("c[%d][%d] = %d\n", i, j, cnt);
        }
    }

    for (int i = 0; i < 103; ++i) {
        for (int j = 0; j < 103; ++j) {
            dp[i][j] = 0x3f3f3f3f;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[0][1] = 0;
            continue;
        }
        for (int j = 1; j <= min(k, i + 1); ++j) {
            for (int p = 0; p <= i; ++p) {
                if (p == 0) {
                    if (j == 1) dp[i][j] = c[0][i];
                } else {
                    dp[i][j] = min(dp[i][j], dp[p - 1][j - 1] + c[p][i]);
                }
            }
        }
    }

    return dp[n - 1][k];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int ans = 0, k;
    string s;
    cin >> s >> k;
    ans = palindromePartition(s, k);
    cout << ans << '\n';

    return 0;
}
