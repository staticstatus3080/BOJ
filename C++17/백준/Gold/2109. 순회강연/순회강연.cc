#include <bits/stdc++.h>
#define X first 
#define Y second 
#define ll long long

using namespace std;

vector<pair<int, int>> v;
priority_queue<int> pq;
int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back({d,p});
    }
    if (n==0) {cout << 0; return 0;}
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    int ans=0, curd = v[0].X;
    for (int i=0; i<n; i++) {
        while (curd>v[i].X) {
            if (pq.empty()) {
                curd=v[i].X;
                break;
            }
            ans += pq.top();
            pq.pop();
            curd--;
        }
        pq.push(v[i].Y);
    }
    while (curd--) {
        if (pq.empty()) break;
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
} 