#include <bits/stdc++.h>
// 참고 사이트 : https://velog.io/@dltmdrl1244/알고리즘-외판원-순회TSP-알고리즘
using namespace std;

int dp[17][65540], cost[17][17], n;

int DFS(int cur, int state) {
    if (state == (1<<n)-1) {
        if (cost[cur][1] == 0) return 1e9;
        else return cost[cur][1];
    }
    if (dp[cur][state] != -1) return dp[cur][state];
    dp[cur][state] = 1e9;
    for (int i=1; i<=n; i++) {
        if (cost[cur][i] == 0) continue;
        if ((state & (1<<(i-1))) > 0) continue;
        int tmp = DFS(i, state | (1<<(i-1)));
        if (tmp >= 1e9) continue;
        dp[cur][state] = min(dp[cur][state], tmp + cost[cur][i]);
    }
    return dp[cur][state];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    fill(&dp[0][0], &dp[16][65540], -1);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> cost[i][j];
        }
    }
    
    int ans = DFS(1, 1);
    cout << ans;
}