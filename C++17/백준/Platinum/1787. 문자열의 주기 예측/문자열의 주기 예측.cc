#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define ti tuple<ll,ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

ll ret=0;
vector<int> Z(const string &s) {
    int n = s.size();
    vector<int> z(n); z[0]=n;
    for (int i=1, l=0, r=0; i<n; i++) {
        if (i<r) z[i] = min(r-i, z[i-l]);
        while (i+z[i] < n && s[i+z[i]] == s[z[i]]) z[i]++;
        if (i+z[i]>r) r = i+z[i], l=i;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; string s;
    cin >> n >> s;
    auto ans = Z(s);
    int tmp=0;
    vector<pii> stk; // 시작 위치, 반경
    for (int i=0; i<n; i++) {
        if (ans[i]>0) {
            stk.push_back({i, ans[i]});
        }
        auto cur = stk.back();
        while (cur.X+cur.Y<=i) {
            stk.pop_back();
            cur = stk.back();
        }
        ret += cur.X;
    }
    cout << ret;
}
