#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

// dp[i][j+d] : i 시각에서 온도가 j일때 최대
// 필요한 범위의 이전 온도는 -D<x<=m+D임
int n, m, c, d, arr[201], dp[201][25001];
deque<pair<int, int>> dq;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m >> c >> d;
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=n; i++) cin >> arr[i];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=c; j++) {
            dq.clear();
            for (int k=0; k<d; k+=c) {
                while (!dq.empty() && dq.back().X < dp[i-1][k+j]) dq.pop_back();
                dq.push_back({dp[i-1][k+j], k+j});
            }
            for (int k=j; k<=m; k+=c) {
                while (!dq.empty() && dq.front().Y < k-d) dq.pop_front();
                while ((k+d)<=m && !dq.empty() && dq.back().X < dp[i-1][k+d]) dq.pop_back();
                if ((k+d)<=m) dq.push_back({dp[i-1][k+d], k+d});
                dp[i][k] = dq.front().X+m-abs(arr[i]-k);
            }
        }
    }
    int ans=0;
    for (int i=1; i<=m; i++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
} 

