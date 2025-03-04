#include<bits/stdc++.h>
using namespace std;

#define int long long
#define debug(x) cerr << #x << " = " << x << '\n'

const int N = 20;

string breakPalindrome(string palindrome) {
    int n = palindrome.size();
    if (n == 1) {
        return "";
    }
    
    // 0 1 2 3 4
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        if ((n & 1) && i == n / 2) continue;
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a';
            flag = 1;
            break;
        }
    }

    if (!flag) palindrome[n - 1] = 'b';
    return palindrome;
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    string s;
    cin >> s;
    string ans = breakPalindrome(s);
    cout << ans << '\n';

    return 0;
}
