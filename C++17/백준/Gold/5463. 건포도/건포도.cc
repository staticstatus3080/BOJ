#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define ti tuple<ll,ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

// 크기가 i, j이고 a, b에서 시작함
ll dp[51][51][51][51]={}, arr[51][51], sum[51][51]={};
ll Sum(int a, int b, int c, int d) {
    return sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1];
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> arr[i][j];
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (i==1 && j==1) continue;
            for (int k=1; k+i<=n+1; k++) {
                for (int l=1; l+j<=m+1; l++) {
                    dp[i][j][k][l] = 1e18;
                    // 사각형은 k~k+i-1, l~l+j-1 형태이다.
                    // 길이 길이 시작 시작
                    if (j!=1) {
                        for (int b=1; b<j; b++) {
                            // l~l+j를 l~l+b, l+b~l+j로 분할
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][b][k][l]+dp[i][j-b][k][l+b]+Sum(k, l, k+i-1, l+j-1));
                        }
                    }
                    if (i!=1) {
                        for (int a=1; a<i; a++) {
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[a][j][k][l]+dp[i-a][j][k+a][l]+Sum(k, l, k+i-1, l+j-1));
                        }
                    }
                }
            }
        }
    }
    cout << dp[n][m][1][1];
    //Sum(k, l, k+i-1, l+j-1)
}   