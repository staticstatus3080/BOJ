#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;

int dp[201][201][21]; // 구간 a~b를 m로 만드는 최소 횟수
int arr[201];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> arr[i];
    memset(dp, 0x3f, sizeof(dp));
    for (int i=1; i<=n; i++) { // 길이
        for (int st=1; i+st-1<=n; st++) { // 위치
            int en = i+st-1; // 끝점
            if (st==en) {
                for (int k=1; k<=m; k++) {
                    if (arr[st]==k) dp[st][en][k]=0;
                    else dp[st][en][k]=1;
                }
                continue;
            }
            for (int j=1; j<en; j++) {
                int minn=1e9;
                for (int k=1; k<=m; k++) {
                    dp[st][en][k] = min(dp[st][en][k], dp[st][j][k]+dp[j+1][en][k]);
                    minn = min(minn, dp[st][j][k]+dp[j+1][en][k]);
                }
                for (int k=1; k<=m; k++) {
                    dp[st][en][k] = min(dp[st][en][k], minn+1);
                }
            }
        }
    }
    int ans=1e9;
    for (int i=1; i<=m; i++) ans = min(ans, dp[1][n][i]);
    cout << ans;
}