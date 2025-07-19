#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int n, m, dp[101][10001]={};
deque<pair<int, int>> dq;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int a, b, c; // 무게, 만족도, 개수
        cin >> a >> b >> c;
        for (int j=0; j<a; j++) {
            dq.clear();
            dp[i][j] = max(dp[i-1][j], dp[i][max(j-1,0)]);
            for (int k=j+a; k<=m; k+=a) {
                while (!dq.empty() && dq.front().Y<k-a*c) dq.pop_front();
                while (!dq.empty() && dq.back().X+(k-dq.back().Y)/a*b<dp[i-1][k-a]+b) dq.pop_back();
                dq.push_back({dp[i-1][k-a], k-a});
                dp[i][k] = max(dp[i-1][k], max(dp[i][k-1], dq.front().X+(k-dq.front().Y)/a*b)); 
            }
        }
    }
    cout << dp[n][m];
} 

