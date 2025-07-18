#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;

ll n, dp[40001][32];

// 편의상 1-based
ll DFS(ll pos, ll state) {
    if (pos==4*n+1) {
        if (state>0) return 0;
        else return 1;
    }
    if (dp[pos][state]!=-1) return dp[pos][state]; 
    if (state&1) return dp[pos][state] = DFS(pos+1, state>>1);
    dp[pos][state]=0;
    if (pos%4 != 0 && (state&3)==0) dp[pos][state] += DFS(pos, (state|3));
    dp[pos][state] += DFS(pos+1, (state>>1)|(1<<3));
    return dp[pos][state];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << DFS(1, 0) << '\n';
    }
} 