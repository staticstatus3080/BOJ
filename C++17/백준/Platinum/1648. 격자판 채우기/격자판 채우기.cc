#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
using namespace std;

// 재풀이 : https://glanceyes.com/entry/BOJ-백준-1648번-격자판-채우기 참고

int dp[197][1<<14], n, m;

int Solve(int idx, int info) {
    if (dp[idx][info]!=-1) return dp[idx][info];
    int ret = 0;
    if (idx>=n*m) {
        if (info==0) return 1;
        else return 0;
    }
    if (info&1) ret = Solve(idx+1, info>>1);
    else {
        ret += Solve(idx+1, (info>>1)|(1<<(m-1)));
        if (idx%m!=(m-1) && (info&2)==0) ret += Solve(idx+2, info>>2);
    }
    ret %= 9901;
    return dp[idx][info] = ret;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    fill(&dp[0][0], &dp[196][1<<14], -1);
    cout << Solve(0, 0);
}