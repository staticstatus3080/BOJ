#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
#define MOD (ll)(1e9+7)
using namespace std;
// https://littlesam95.tistory.com/entry/BOJPlatinum-3-%EB%B0%B1%EC%A4%80-3830-%EA%B5%90%EC%88%98%EB%8B%98%EC%9D%80-%EA%B8%B0%EB%8B%A4%EB%A6%AC%EC%A7%80-%EC%95%8A%EB%8A%94%EB%8B%A4C 참고
// d[i] : i에서 root까지의 무게차
int p[100001], d[100001];
// p가 갱신되었는지 여부로 잘 d를 합치기?
pair<int,int> find(int a) {
    if (p[a]==a) return {a,d[a]};
    auto [np,nd] = find(p[a]);
    d[a] += nd;
    p[a] = np;
    return {p[a],d[a]};
}


void Union(int a, int b, int w) {
    auto [pa,da] = find(a);
    auto [pb,db] = find(b);
    if (pa==pb) return;
    p[pb]=pa;
    d[pb] = -db+da+w;
}
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    while (1) {
        int n, m;
        cin >> n >> m;
        if (n==0) break;
        for (int i=1; i<=n; i++) {p[i]=i; d[i]=0;}
        while (m--) {
            char c;
            cin >> c;
            if (c=='!') {
                int a, b, w;
                cin >> a >> b >> w;
                Union(a,b,w);
            }
            else {
                int a ,b;
                cin >> a>>b;
                auto [pa,da] = find(a);
                auto [pb,db] = find(b);
                if (pa!=pb) {
                    cout << "UNKNOWN" << '\n';
                }
                else {
                    cout << db-da << '\n';
                }
            }
        }
    }
}   