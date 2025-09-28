#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;

int dp[2001]={};
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int c, n;
    cin >> c >> n;
    vector<pii> v(n);
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    for(int i=0; i<n; i++) cin >> v[i].X >> v[i].Y;
    for (int i=1; i<=2000; i++) {
        for (int j=0; j<n; j++) {
            if (i-v[j].Y>=0) dp[i]=min(dp[i], dp[i-v[j].Y]+v[j].X);
        }
    }
    int ans=1e9;
    for (int i=c; i<=2000; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans;
}   