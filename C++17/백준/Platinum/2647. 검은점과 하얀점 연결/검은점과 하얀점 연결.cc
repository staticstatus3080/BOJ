#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

int dp[101][101]={}, h[101][101]={}, sum[101]={};
vector<pair<int, int>> ans;
bool Check(int a, int b) {
    int one = sum[b]-sum[a-1];
    return !(one==(b-a+1)/2);
}
void Solve(int st, int en) {
    if (en-st==1) {
        ans.push_back({st,en});
        return;
    }
    if (sum[st]-sum[st-1] != sum[en]-sum[en-1]) {
        int tmp = dp[st+1][en-1]+2*(h[st+1][en-1]+1)+en-st;
        if (dp[st][en]==tmp) {
            ans.push_back({st, en});
            Solve(st+1, en-1);
            return;
        }
    }
    for (int a = st+1; a<en; a+=2) {
        if (dp[st][en] == dp[st][a]+dp[a+1][en]) {
            Solve(st, a);
            Solve(a+1, en);
            return;
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        sum[i]=sum[i-1];
        if (c-'0') sum[i]++;
    }

    for (int j=2; j<=n; j+=2) { // 길이
        for (int i=1; i+j-1<=n; i++) { // 시작점
            // 시작:i, 끝:i+j-1(k)
            int k = i+j-1;
            if (Check(i,k)) continue;
            if (j==2) {
                h[i][k]=1;
                dp[i][k]=3;
                continue;
            }
            dp[i][k]=1e9;
            for (int x=i+1; x<k; x+=2) {
                if (Check(i,x) || Check(x+1,k)) {
                    continue;
                }
                int tmp = dp[i][x]+dp[x+1][k];
                if (dp[i][k]>tmp) {
                    dp[i][k] = tmp;
                    h[i][k] = max(h[i][x],h[x+1][k]);
                }
            }
            if (sum[i]-sum[i-1] != sum[k]-sum[k-1]) {
                int tmp = dp[i+1][k-1]+2*(h[i+1][k-1]+1)+j-1;
                if (dp[i][k]>tmp) {
                    dp[i][k] = tmp;
                    h[i][k] = h[i+1][k-1]+1;
                }
            }
        }
    }
    Solve(1, n);
    sort(ans.begin(), ans.end());
    cout << dp[1][n] << '\n';
    for (auto cur : ans) {
        cout << cur.X << ' ' << cur.Y << '\n';
    }
}