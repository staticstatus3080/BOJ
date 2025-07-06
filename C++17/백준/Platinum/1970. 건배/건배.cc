#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;

int dp[1001][1001]={}, arr[1001];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, ans=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for (int j=2; j<=n; j++) { // 길이
        for (int i=0; i+j<=n; i++) { // 시작 위치
            // 시작:i, 끝:i+j-1
            for (int k=i+1; k<i+j-1; k++) {
                dp[i][i+j-1] = max(dp[i][i+j-1], dp[i][k]+dp[k+1][i+j-1]);
            }
            if (arr[i]==arr[i+j-1]) dp[i][i+j-1] = max(dp[i][i+j-1], 1+dp[i+1][i+j-2]);
            dp[i][i+j-1] = max(max(dp[i+1][i+j-1], dp[i][i+j-2]), dp[i][i+j-1]);
        }
    }
    cout << dp[0][n-1];
}