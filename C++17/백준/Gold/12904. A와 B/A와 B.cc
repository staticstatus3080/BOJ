#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    int diff = t.length()-s.length();
    while (diff--) {
        char c = t[t.length()-1];
        t.pop_back();
        if (c=='B') {
            reverse(t.begin(), t.end());
        }
    }
    cout << (s==t);
}