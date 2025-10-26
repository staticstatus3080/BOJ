#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;

// val : 노드에 표기하는값, dp: 노드 한번 거쳤으면 스킵, arr: 최종 돈
ll p[200001], cp[200001], siz[200001], val[200001]={}, dp[200001]={}, arr[200001]={}, nxt;
int getp(int a) {
    if (cp[a]==a) return a;
    else return cp[a] = getp(cp[a]); 
}
void Union(int a, int b) {
    a = getp(a);
    b = getp(b);
    p[a]=cp[a]=p[b]=cp[b]=nxt;
    p[nxt]=nxt;
    siz[nxt] = siz[a]+siz[b];
    nxt++;
}
ll Calc(int a) {
    if (p[a]==a) return dp[a]=val[a];
    if (dp[a]!=-1) return dp[a];
    dp[a] = val[a];
    dp[a] += Calc(p[a]);
    return dp[a];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    nxt = n+1;
    for (int i=1; i<=2*n; i++) {p[i]=cp[i]=i; siz[i]=1;}
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a==1) {
            Union(b,c);
        }
        else {
            arr[b]-=c;
            b = getp(b);
            val[b] += c/siz[b];
        }
    }
    memset(dp, -1, sizeof(dp));
    int init=-1;
    for (int i=1; i<=n; i++) {
        arr[i] += Calc(i);
        if (arr[i]<0) init=i;
    }
    // 음수면 받아야하고 양수면 보내야함
    vector<tuple<ll,ll,ll>> v;
    for (int i=1; i<=n; i++) {
        if (i==init) continue;
        if (arr[i]>0) {
            v.push_back({i, init, arr[i]});
            arr[i]=0;
        }
        if (arr[i]<0) {
            v.push_back({init, i, -arr[i]});
        }
    }
    cout << v.size() << '\n';
    for (auto cur : v) {
        ll a, b, c;
        tie(a,b,c) = cur;
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}    