#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;

int dp[501][501]={};
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int siz = s.size();
    int ans=0;
    for (int j=1; j<=siz; j++) { // 길이
        for (int i=0; i+j<=siz; i++) { // 시작 위치
            // 시작:i, 끝:i+j-1
            if (j==2 && ((s[i]=='a')&&(s[i+1]=='t')) || ((s[i]=='g')&&(s[i+1]=='c'))) dp[i][i+1]=2;
            if (j<=2) continue;
            else if (((s[i]=='a')&&s[i+j-1]=='t') || ((s[i]=='g')&&(s[i+j-1]=='c'))) dp[i][i+j-1]=2+dp[i+1][i+j-2];
            for (int k=i; k<i+j-1; k++) {
                dp[i][i+j-1]=max(dp[i][i+j-1], dp[i][k]+dp[k+1][i+j-1]);
            }
        }
    }
    cout << dp[0][siz-1];
}