#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;


int arr[1010][1010], m=1e9, dr, dc;
bool solve(string s, string t) {
    while (s.length()<t.length()) {
        if (t[0]=='A') {
            if (t[t.length()-1]!='A') return 0;
            t.pop_back();
        }
        else if (t[t.length()-1]=='B') {
            reverse(t.begin(), t.end());
            t = t.substr(0, t.length()-1);
        }
        else {
            string tmps = t;
            reverse(tmps.begin(), tmps.end());
            tmps = tmps.substr(0, tmps.length()-1);
            bool tmp = solve(s, tmps);
            if (tmp) return 1;
            t.pop_back();
        }
    }
    return (s==t);
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    cout << solve(s,t);
}