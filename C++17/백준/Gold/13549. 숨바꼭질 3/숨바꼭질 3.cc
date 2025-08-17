#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main() {
    int n, m, t[100001];
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
    
    fill(t, t+100001, 1e9);
    cin >> n >> m;
    t[n] = 0;
    pq.push({0, n});
    
    while (!pq.empty()) {
        auto cur = pq.top(); // 시간, 번호
        pq.pop();
        if (t[m] != 1e9) break;
        if (t[cur.Y] < cur.X) continue;
           
        int idx = cur.Y;
        if (idx <= 99999 && t[idx+1] > t[idx]+1) {
            t[idx+1] = t[idx]+1;
            pq.push({t[idx+1], idx+1});
        }
        if (1 <= idx && t[idx-1] > t[idx]+1) {
            t[idx-1] = t[idx]+1;
            pq.push({t[idx-1], idx-1});
        }
        if (idx*2 <= 100000 && t[idx*2] > t[idx]) {
            t[idx*2] = t[idx];
            pq.push({t[idx*2], idx*2});
        }
    }
    
    cout << t[m];
}