#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;

vector<int> v;
map<int, int> m;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, s;
    cin >> n >> s;
    for (int i=1; i<=n; i++) {
        int h, c;
        cin >> h >> c;
        if (m[h]<c) m[h]=c;
        v.push_back(h);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int siz=v.size();
    int dp[300001]={};
    for (int i=0; i<siz; i++) {
        if (v[i]<s) continue;
        if (i>0) dp[i] = dp[i-1];
        int front = upper_bound(v.begin(), v.end(), v[i]-s) - v.begin();
        int prev = front-1;
        if (prev>=0) dp[i] = max(dp[i], dp[prev]+m[v[i]]);
        else dp[i] = max(dp[i], m[v[i]]);
    }
    cout << dp[siz-1];
}