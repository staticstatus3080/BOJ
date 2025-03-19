#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;


priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> sorted;

// 시간, 계산대
int id[100003];
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i=1; i<=k; i++) {
        pq.push(make_pair(0, i));
    }
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        id[i] = a;
        auto cur = pq.top();
        pq.pop();
        pq.push(make_pair(cur.X+b, cur.Y));
        sorted.push(make_pair(cur.X+b, make_pair(-cur.Y, i)));
    }
    ll ans=0;
    ll cnt=1;
    while (!sorted.empty()) {
        auto cur = sorted.top();
        sorted.pop();
        ans += cnt*id[cur.Y.Y];
        cnt++;
    }
    cout << ans;
}