#include<bits/stdc++.h>
using namespace std;

#define int long long
#define debug(x) cerr << #x << " = " << x << '\n'

const int N = 20;

vector<string> vs;
vector<vector<string>> ans;

int is_p(string s, int l, int r) {
    for (int i = l, j = r; j - i >= 1; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

void dfs(string s, int l) {
    int n = s.size();
    if (l == n) {
        ans.push_back(vs);
        return;
    }
    for (int i = l; i < n; ++i) {
        // [l, i]
        int is = is_p(s, l, i);
        if (is) {
            vs.push_back(s.substr(l, i - l + 1));
            dfs(s, i + 1);
            vs.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    dfs(s, 0);
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    ans = partition(s);
    for (auto v : ans) {
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " \n"[i == v.size() - 1];
        }
    }
    return 0;
}
