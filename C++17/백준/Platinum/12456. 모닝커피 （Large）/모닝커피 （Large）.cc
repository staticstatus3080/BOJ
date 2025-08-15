#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
using namespace std;

// 일단 시간을 역으로 거스르면서 최적 선택을 하면 됨
// 근데 k가 너무 크네? -> 종류 하나 골라서 경계를 기준으로 한번에 계산
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int j=1; j<=T; j++) {
        ll n, k;
        cin >> n >> k;
        vector<tuple<ll,ll,ll>> v; // 시간,만족도,개수
        for (int i=0; i<n; i++) {
            ll c,t,s;
            cin >> c >> t >> s;
            v.push_back({t,s,c});
        }
        sort(v.begin(), v.end(), greater<>());
        v.push_back({0,0,0});
        ll idx=0, ct=k, bound=0, ans=0;
        priority_queue<pii> pq; // 만족도, 개수
        while (idx<n || !pq.empty()) {
            while (idx!=n && (get<0>(v[idx])==ct || pq.empty())) {
                ct = get<0>(v[idx]);
                auto [cur,s,c] = v[idx++];
                pq.push({s,c});
            }
            if (pq.empty() && idx==n) break;
            if (ct==0) break;
            bound = ct-get<0>(v[idx]);
            auto [cs,cc] = pq.top();
            pq.pop();
            if (cc>bound) {
                ans += cs*bound;
                pq.push({cs,cc-bound});
                ct = get<0>(v[idx]);
            }
            else {
                ans += cs*cc;
                ct-=cc;
            }
        }
        cout << "Case #" << j << ": " << ans << '\n';
    }
}