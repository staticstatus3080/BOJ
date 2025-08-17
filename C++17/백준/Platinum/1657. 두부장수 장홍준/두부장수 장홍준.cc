#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
using namespace std;


int n, m, dp[197][1<<14], val[6][6] = {
    10, 8, 7, 5, 0, 1,
    8, 6, 4, 3, 0, 1,
    7, 4, 3, 2, 0, 1,
    5, 3, 2, 2, 0, 1,
    0, 0, 0, 0, 0, 0, 
    1, 1, 1, 1, 0, 0
};
char board[197]={};
int Solve(int idx, int info) {
    if (dp[idx][info] != -1) return dp[idx][info];
    if (idx>=n*m) {
        return 0;
    }
    int ret=0;
    ret = max(ret, Solve(idx+1, info>>1));
    if ((idx%m)!=(m-1) && (info&3)==0) 
        ret = max(ret, val[board[idx]-'A'][board[idx+1]-'A'] + Solve(idx+2, info>>2));
    if (((info&1) == 0) && (idx/m)<(n-1) && ((info&(1<<m)) == 0)) 
        ret = max(ret, val[board[idx]-'A'][board[idx+m]-'A'] + Solve(idx+1, (info>>1)|(1<<(m-1))));
    return dp[idx][info] = ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i=0; i<n*m; i++) cin >> board[i];
    cout << Solve(0, 0);
}