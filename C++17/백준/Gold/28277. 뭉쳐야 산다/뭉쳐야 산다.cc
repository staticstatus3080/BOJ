#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
using namespace std;

set<int> s[500001];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        for (int j=1; j<=k; j++) {
            int a;
            cin >> a;
            s[i].insert(a);
        }
    }
    while (q--) {
        int t;
        cin >> t;
        if (t==1) {
            int a, b;
            cin >> a >> b;
            if (s[b].size()>s[a].size()) {
                swap(s[a],s[b]);
            }
            for (auto cur : s[b]) s[a].insert(cur);
            s[b].clear();
        }
        else {
            int a;
            cin >> a;
            cout << s[a].size() << '\n';
        }
    }
}   