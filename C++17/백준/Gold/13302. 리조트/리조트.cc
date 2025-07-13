#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;

ll dp[101][101]; // a번째 날까지 쿠폰이 b장일 때 최소
bool chk[101]={};
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    memset(dp, 0x7f, sizeof(dp));
    for (int i=1; i<=m; i++) {
        int a;
        cin >> a;
        chk[a]=1;
    }
    dp[0][0]=0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (chk[i] && dp[i-1][j]<1e9) dp[i][j] = dp[i-1][j];
            if (i>=3 && j>0 && dp[i-3][j-1]<1e9) dp[i][j] = min(dp[i][j], dp[i-3][j-1]+25000);
            if (i>=5 && j>1 && dp[i-5][j-2]<1e9) dp[i][j] = min(dp[i][j], dp[i-5][j-2]+37000);
            if (j<=n-3 && dp[i-1][j+3]<1e9) dp[i][j] = min(dp[i][j], dp[i-1][j+3]);
            if (dp[i-1][j]<1e9) dp[i][j] = min(dp[i][j], dp[i-1][j]+10000); 
        }
    }
    ll ans=1e9;
    for (int j=0; j<=n; j++) {
        ans = min(ans, dp[n][j]);
    }
    cout << ans;
}