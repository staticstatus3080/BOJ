#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;

int arr[100001];
int pre[100001]={}; // 역추적
set<int> s; // 원소 존재 판별
map<int, bool> m; // 원소 방문 판별
map<int, int> idx;
queue<pair<int, int>> q;
bool vis[100001]={};
int main() {
    int n, k, r;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        string tmps;
        cin >> tmps;
        arr[i] = 0;
        for (int j=0; j<k; j++) {
            if (tmps[j]=='1') arr[i] += (1<<(k-j-1));
        } 
        s.insert(arr[i]); 
        idx[arr[i]]=i;
    }

    // 전처리
    m[arr[1]]=true;
    q.push({arr[1], 1});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i=0; i<k; i++) {
            int tmp = cur.X;
            if ((tmp&(1<<i))>0) tmp -= (1<<i);
            else tmp += (1<<i);
            if (s.find(tmp)==s.end()) continue;
            if (m[tmp]) continue;
            m[tmp]=1;
            pre[idx[tmp]] = cur.Y;
            q.push({tmp, idx[tmp]});
        }   
    }
    cin >> r;
    while (r--) {
        int t;
        cin >> t;
        if (t==1) {cout << 1 << '\n'; continue;}
        if (pre[t]==0) {cout << -1 << '\n'; continue;}
        stack<int> st;
        while (t != 1) {
            st.push(t);
            t = pre[t];
        }
        cout << 1 << ' ';
        while (!st.empty()) {
            cout << st.top() << ' ';
            st.pop();
        }
        cout << '\n';
    }
}